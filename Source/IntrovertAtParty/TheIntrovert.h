// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TheIntrovert.generated.h"

UCLASS()
class INTROVERTATPARTY_API ATheIntrovert : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATheIntrovert();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

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
	float SprintSpeedMultiplier;
	void SprintStart();

	void SprintStop();

	//bool sprinting;




};
