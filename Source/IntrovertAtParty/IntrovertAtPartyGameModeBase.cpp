// Fill out your copyright notice in the Description page of Project Settings.

#include "IntrovertAtPartyGameModeBase.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"


AIntrovertAtPartyGameModeBase::AIntrovertAtPartyGameModeBase()
{
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;

	// Variables.
	gameOver = false;
	timeScale = 100;
	
	// When the party/game ends.
	maxHours = 4;

	// The current hour when the game is started
	hours = 20;

}

void AIntrovertAtPartyGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	incrementTime(DeltaSeconds);
}

void AIntrovertAtPartyGameModeBase::incrementTime(float DeltaSeconds)
{	
	seconds += 1 * DeltaSeconds * timeScale;

	if (seconds >= 60.f)
	{
		++minutes;
		seconds = 0.f;
	}

	if (minutes >= 60.f)
	{
		++hours;
		minutes = 0.f;
	}

	if (hours >= 24.f)
	{
		hours = 0.f;
	}

	if (hours > 4.f && hours < 18.f)
	{
		gameOver = true;
	}

	// Updates strings for HUD.
	if (minutes < 10)
	{
		FString addZero = "0";
		stringMinutes = stringMinutes.FromInt(minutes);
		stringMinutes = addZero + stringMinutes;
	}
	else
	{
		stringMinutes = stringMinutes.FromInt(minutes);
	}

	if (hours < 10)
	{
		FString addZero = "0";
		stringHours = stringHours.FromInt(hours);
		stringHours = addZero + stringHours;
	}
	else
	{
		stringHours = stringHours.FromInt(hours);
	}

	// DEBUG!
	//if (GEngine)
	//GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Hours: %f, Minutes: %f"), hours, minutes));
}