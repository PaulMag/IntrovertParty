// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseCharacter.h"
#include "NPCPawn.h"

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPCController.generated.h"

/**
 * 
 */
UCLASS()
class INTROVERTATPARTY_API ANPCController : public AAIController
{
	GENERATED_BODY()
	
public:
	ANPCPawn* pawn;
	ABaseCharacter* targetCurrent;

	virtual void BeginPlay() override;
};
