// Fill out your copyright notice in the Description page of Project Settings.


#include "SubSystems/ScoreSubsystem.h"

void UScoreSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	CurrentScore = 0;
}

void UScoreSubsystem::AddPoints(const int32 Points)
{
	CurrentScore += Points;

	OnScoreUpdated.Broadcast(CurrentScore);
}
