// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCController.h"
#include "NPCPawn.h"


void ANPCController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("NPC: Controller live."));

	pawn = Cast<ANPCPawn>(GetPawn());
	pawn->controller = this;

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
