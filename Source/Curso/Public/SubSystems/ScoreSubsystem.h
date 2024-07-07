// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ScoreSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreUpdated, const int32, CurrentScore);

UCLASS()
class CURSO_API UScoreSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	FOnScoreUpdated OnScoreUpdated;
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	void AddPoints(const int32 Points);

	int32 GetScore() const{return CurrentScore;}

private:
	int32 CurrentScore = 0;
};
