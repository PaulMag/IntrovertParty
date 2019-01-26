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
	TArray<ANPCPawn*> allNPCs;  // list of all NPC characters

	ATheIntrovert();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//////////////////////////////
	// ===== STRESS O'METER =====
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stress")
	float percievedAmbientLoudness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stress")
	float CurrentStressLevel = 10.;  // [0, 100]

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stress")
	float CurrentAwkwardnessLevel = 10.;  // [0, 100]

	UFUNCTION(BlueprintCallable, Category = "Stress")
	void calculatePercievedAmbientLoudness();

	UFUNCTION(BlueprintCallable, Category = "Stress")
	void UpdateCurrentStressLevel();

	UFUNCTION(BlueprintCallable, Category = "Stress")
	void UpdateCurrentAwkwardnessLevel();

	//////////////////////////////
	// ===== WATCH MECHANICS =====
	void CheckWatchStart();
	void CheckWatchStop();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Actions")
	bool checkingWatch;

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
