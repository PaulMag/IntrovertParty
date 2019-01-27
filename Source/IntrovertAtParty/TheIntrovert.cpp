// Fill out your copyright notice in the Description page of Project Settings.

#include "TheIntrovert.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ATheIntrovert::ATheIntrovert()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	previousLocation = GetActorLocation();
	
	// Various variables
	checkingWatch = false;
	objectiveCanInteract = false;
	didJustInteract = false;
}

// Called when the game starts or when spawned
void ATheIntrovert::BeginPlay()
{
	Super::BeginPlay();
	
	// Fill array with all NPCs.
	TArray<AActor*> foundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ANPCPawn::StaticClass(), foundActors);
	ANPCPawn* foundActor;
	for (int i = 0; i < foundActors.Num(); i++)
	{
		foundActor = Cast<ANPCPawn>(foundActors[i]);
		allNPCs.Add(foundActor);
	}
}

// Called every frame
void ATheIntrovert::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	calculatePercievedAmbientLoudness();
	UpdateCurrentStressLevel();
	UpdateCurrentAwkwardnessLevel();
}

// Called to bind functionality to input
void ATheIntrovert::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("CheckWatch", IE_Pressed, this, &ATheIntrovert::CheckWatchStart);
	PlayerInputComponent->BindAction("CheckWatch", IE_Released, this, &ATheIntrovert::CheckWatchStop);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ATheIntrovert::InteractWithObjective);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &ATheIntrovert::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATheIntrovert::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &ATheIntrovert::AddControllerYawInput);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ATheIntrovert::SprintStart);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ATheIntrovert::SprintStop);
}

void ATheIntrovert::CheckWatchStart()
{	
	checkingWatch = true;
	
	// DEBUG!
	//if (GEngine)
	//GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Blue, FString::Printf(TEXT("WATCH")));

}

void ATheIntrovert::CheckWatchStop()
{
	checkingWatch = false;
	
	// DEBUG!
	//if (GEngine)
	//GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Red, FString::Printf(TEXT("NO WATCH")));
}

void ATheIntrovert::InteractWithObjective()
{
	if (objectiveCanInteract)
	{
		didJustInteract = true;
	}
	else
	{
		didJustInteract = false;
	}

	objectiveCanInteract = false;
}

void ATheIntrovert::SprintStart()
{
	sprinting = true;
	UE_LOG(LogTemp, Warning, TEXT("Sprinting"));
}

void ATheIntrovert::SprintStop()
{
	sprinting = false;
	UE_LOG(LogTemp, Warning, TEXT("Stopped Sprinting"));
}

void ATheIntrovert::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// Find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();

		// Add movement in decided direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		if (sprinting == true)
		{
			Value *= SprintSpeedMultiplier;
		}
		else
		{
			Value *= 1;
		}
		AddActorLocalOffset(FVector(Value * GetWorld()->DeltaTimeSeconds *walkSpeed, 0, 0), true);
	}
}

void ATheIntrovert::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		//Find out which way is right 
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// Add movement in decided direction
		AddActorLocalOffset(FVector(0, Value * GetWorld()->DeltaTimeSeconds *walkSpeed, 0), true);
	}
}

//** Stress O'Meter **//
void ATheIntrovert::calculatePercievedAmbientLoudness()
{
	float loudness = 0;
	float distance;
	for (int i = 0; i < allNPCs.Num(); i++)
	{
		distance = (allNPCs[i]->GetActorLocation() - GetActorLocation()).Size();
		loudness += allNPCs[i]->loudness / distance;
	}
	percievedAmbientLoudness = loudness;
}

void ATheIntrovert::UpdateCurrentStressLevel()
{
	stressLevel += percievedAmbientLoudness * GetWorld()->DeltaTimeSeconds * 100;
}

void ATheIntrovert::UpdateCurrentAwkwardnessLevel()
{
	FVector direction;
	float distanceMin = 1e6;
	float distance;
	float visibilitySum = 0;
	float sightMax = 0;
	ANPCPawn* closestNPC = allNPCs[0];
	
	for (int i = 0; i < allNPCs.Num(); i++)
	{
		distance = (allNPCs[i]->GetActorLocation() - GetActorLocation()).Size();
		// Find closest NPC
		if (distance < distanceMin)
		{
			distanceMin = distance;
			closestNPC = allNPCs[i];
		}
		// Find vision of this NPC
		direction = (GetActorLocation() - allNPCs[i]->GetActorLocation()).GetSafeNormal();
		float sightratio = FVector::DotProduct(direction, allNPCs[i]->GetActorForwardVector());
		if (sightratio > 0)
		{
			sightratio = sightratio / distance;
			visibilitySum += sightratio;
			if (sightratio > sightMax) {
				sightMax = sightratio;
			}
		}
	}
	direction = (closestNPC->GetActorLocation() - GetActorLocation()).GetSafeNormal();
	FVector deltaLocation = GetActorLocation() - previousLocation;
	float badness = - FVector::DotProduct(direction, deltaLocation) / pow(distanceMin, 1.5) * 4000;
	if (badness < 0) {
		badness = 0;
	}
	previousLocation = GetActorLocation();

	awkwardnessLevel += badness * GetWorld()->DeltaTimeSeconds;
	visibilityTotal = visibilitySum;
	visibilityHighest = sightMax;
	UE_LOG(LogTemp, Warning, TEXT("visibility=%f, max=%f"), visibilityTotal, visibilityHighest);
}
