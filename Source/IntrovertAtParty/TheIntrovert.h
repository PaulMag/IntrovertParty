// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "NPCPawn.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine.h"
#include "TheIntrovert.generated.h"


UCLASS()
class INTROVERTATPARTY_API ATheIntrovert : public ACharacter
{
	GENERATED_BODY()

public:
	TArray<ANPCPawn*> allNPCs;

	ATheIntrovert();

	//* @param Stress Level: This is the amount to change the players stress level by. it can be either positive or negetive. 
	UFUNCTION (BlueprintCallable, Category = "Stress")
	void UpdateCurrentStressLevel();

	UFUNCTION(BlueprintCallable, Category = "Stress")
	void UpdateCurrentAwkwardnessLevel();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//** STRESS O'METER **//
	UPROPERTY(EditAnywhere, Category = "Stress")
	float InitialStressLevel;

	void calculatePercievedAmbientLoudness();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stress")
	float stressLevel = 10.;  // [0, 100]

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stress")
	float awkwardnessLevel = 10.;  // [0, 100]

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stress")
	float percievedAmbientLoudness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stress")
	float socialInteraction;

	//////////////////////////////
	// ===== WATCH MECHANICS =====
	void CheckWatchStart();

	void CheckWatchStop();

	void InteractWithObjective();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Actions")
		bool checkingWatch;

	///////////////////////////////////
	// ===== OBJECTIVE MECHANICS =====

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Actions")
		bool objectiveCanInteract;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Actions")
		bool didJustInteract;

	/////////////////////////////////
	// ===== MOVEMENT MECHANICS =====
	void MoveForward(float Value);
	void MoveRight(float Value);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Character Movement: Walking")
	float SprintSpeedMultiplier = 2.0f;
	float walkSpeed = 400;
	
	void SprintStart();
	void SprintStop();
	bool sprinting;
};
