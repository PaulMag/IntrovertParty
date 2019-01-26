// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine.h"
#include "TheIntrovert.generated.h"


UCLASS()
class INTROVERTATPARTY_API ATheIntrovert : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATheIntrovert();

	//Accsesor function for initial stress level
	UFUNCTION (BlueprintPure, Category = "Stress")
	float GetInitialStressLevel();

	//Accsesor function for current stress level
	UFUNCTION (BlueprintPure, Category = "Stress")
	float GetCurrentStressLevel();

	//* @param Stress Level: This is the amount to change the players stress level by. it can be either positive or negetive. 
	UFUNCTION (BlueprintCallable, Category = "Stress")
	void UpdateCurrentStressLevel (float StressLevel);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//** STRESS O'METER **//
	//The Players initial stress level
	UPROPERTY(EditAnywhere, Category = "Stress")
	float InitialStressLevel;

	//The players current stress level
	UPROPERTY(EditAnywhere, Category = "Stress")
	float CurrentStressLevel;
};
