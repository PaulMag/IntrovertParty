// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "IntrovertAtPartyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class INTROVERTATPARTY_API AIntrovertAtPartyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	AIntrovertAtPartyGameModeBase();

	void Tick(float DeltaSeconds);

public:
	///////////////////////////////
	// ==========|TIME|===========

	void incrementTime(float DeltaSeconds);

	float timeScale;

	float maxHours;

	float seconds;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Time")
		float minutes;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Time")
		float hours;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Time")
		FString stringMinutes;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Time")
		FString stringHours;

	///////////////////////////////////////
	// ==========|Game Systems|===========

	bool gameOver;
};
