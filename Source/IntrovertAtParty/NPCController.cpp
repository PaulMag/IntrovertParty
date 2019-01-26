// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCController.h"

#include "BaseCharacter.h"
#include "NPCPawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TimerManager.h"


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
	//paceToRandomPoint();
}

void ANPCController::paceToRandomPoint()
{
	float direction = FMath::RandRange(0.f, 2 * PI);
	float distance = FMath::RandRange(100.f, 300.f);
	target.X = cos(direction) * distance;
	target.Y = sin(direction) * distance;
	target += pawn->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("NPC: Move started to (%f, %f)"), target.X, target.Y);
	MoveToLocation(target, 5);
}
