// Fill out your copyright notice in the Description page of Project Settings.

#include "NPCController.h"
#include "NPCPawn.h"


void ANPCController::BeginPlay()
{
	Super::BeginPlay();

	pawn = Cast<ANPCPawn>(GetPawn());
	pawn->controller = this;
}
