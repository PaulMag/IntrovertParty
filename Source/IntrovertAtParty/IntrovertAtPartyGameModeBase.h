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

	void updatePromptText();

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
	// ==========|Goal System|===========
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Goals")
		bool hasCalled;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Goals")
		bool hasUsedBathroom;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Goals")
		bool hasReturnedComic;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Goals")
		bool hasLeft;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Goals - Text")
		FString promptText;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Actions")
		int objectiveType = 0;

	///////////////////////////////////////
	// ==========|Game Systems|===========
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Goals")
		bool gameOver;
};
