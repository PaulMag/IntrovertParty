// Fill out your copyright notice in the Description page of Project Settings.

#include "TheIntrovert.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

// Sets default values
ATheIntrovert::ATheIntrovert()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Various variables
	checkingWatch = false;
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

}

// Called to bind functionality to input
void ATheIntrovert::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("CheckWatch", IE_Pressed, this, &ATheIntrovert::CheckWatchStart);
	PlayerInputComponent->BindAction("CheckWatch", IE_Released, this, &ATheIntrovert::CheckWatchStop);

}

void ATheIntrovert::CheckWatchStart()
{	
	checkingWatch = true;
	
	// DEBUG!
	//if (GEngine)
	//GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Blue, FString::Printf(TEXT("WATCH")));

}

void ATheIntrovert::CheckWatchStop()
{
	checkingWatch = false;
	
	// DEBUG!
	//if (GEngine)
	//GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Red, FString::Printf(TEXT("NO WATCH")));
}