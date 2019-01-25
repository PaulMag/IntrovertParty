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
	virtual void SetupPlayerInputComponent (class UInputComponent* InputComponent) override;

	//Handles moving backward and forward
	UFUNCTION()
	void MoveForward(float AxisInput);
	//Handles strafing
	UFUNCTION()
	void MoveRight(float AxisInput);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
