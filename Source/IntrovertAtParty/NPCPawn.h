// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

class ANPCController;

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "NPCPawn.generated.h"

/**
 * 
 */
UCLASS()
class INTROVERTATPARTY_API ANPCPawn : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ANPCController* controller;  // is set by the controller itself
};
