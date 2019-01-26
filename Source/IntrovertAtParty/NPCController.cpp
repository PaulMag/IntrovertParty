// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCController.h"

#include "BaseCharacter.h"
#include "NPCPawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Engine/World.h"


void ANPCController::BeginPlay()
{
	Super::BeginPlay();

	pawn = Cast<ANPCPawn>(GetPawn());
	pawn->controller = this;

	TArray<AActor*> foundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseCharacter::StaticClass(), foundActors);
	ABaseCharacter* foundActor;
	for (int i = 0; i < foundActors.Num(); i++)
	{
		foundActor = Cast<ABaseCharacter>(foundActors[i]);
		allCharacters.Add(foundActor);
	}

	paceToRandomPoint();
}

void ANPCController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	float waitTime = FMath::RandRange(2.f, 5.f);
	GetWorldTimerManager().SetTimer(moveTimerHandle, this, &ANPCController::paceToRandomPoint, waitTime, false);
}

void ANPCController::paceToRandomPoint()
{
	if (FMath::RandRange(0.f, 100.f) < 50.)
	{
		target.X = FMath::RandRange(-2000.f, 2000.f);
		target.Y = FMath::RandRange(-2000.f, 2000.f);
	}
	else
	{
		int charIndex = FMath::RandRange(0, allCharacters.Num()-1);
		targetCharacter = allCharacters[charIndex];
		float direction = FMath::RandRange(0.f, 2 * PI);
		float distance = FMath::RandRange(150.f, 250.f);
		target.X = cos(direction) * distance;
		target.Y = sin(direction) * distance;
		target += targetCharacter->GetActorLocation();
	}
	UE_LOG(LogTemp, Warning, TEXT("NPC: Move started to (%f, %f)"), target.X, target.Y);
	MoveToLocation(target, 100.);
}
