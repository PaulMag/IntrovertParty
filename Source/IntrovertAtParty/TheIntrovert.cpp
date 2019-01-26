// Fill out your copyright notice in the Description page of Project Settings.

#include "TheIntrovert.h"

// Sets default values
ATheIntrovert::ATheIntrovert()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InitialStressLevel = 100.f;
	CurrentStressLevel = InitialStressLevel;
}

// Called when the game starts or when spawned
void ATheIntrovert::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATheIntrovert::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateCurrentStressLevel(-DeltaTime * 0.0f * (InitialStressLevel));
}

// Called to bind functionality to input
void ATheIntrovert::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//** Stress O'Meter **//
float ATheIntrovert::GetInitialStressLevel()
{
	return InitialStressLevel;
}

float ATheIntrovert::GetCurrentStressLevel()
{
	return CurrentStressLevel;
}

void ATheIntrovert::UpdateCurrentStressLevel(float StressLevel)
{
	CurrentStressLevel = CurrentStressLevel + StressLevel;
}

