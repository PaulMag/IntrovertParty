// Fill out your copyright notice in the Description page of Project Settings.

#include "TheIntrovert.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

// Sets default values
ATheIntrovert::ATheIntrovert()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Various variables
	checkingWatch = false;
}

// Called when the game starts or when spawned
void ATheIntrovert::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATheIntrovert::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATheIntrovert::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("CheckWatch", IE_Pressed, this, &ATheIntrovert::CheckWatchStart);
	PlayerInputComponent->BindAction("CheckWatch", IE_Released, this, &ATheIntrovert::CheckWatchStop);

	//Set up movement key bindings
	PlayerInputComponent->BindAxis("MoveForward", this, &ATheIntrovert::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATheIntrovert::MoveRight);
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

void ATheIntrovert::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// Find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();

		// Add movement in decided direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
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
		AddMovementInput(Direction, Value);
	}
}