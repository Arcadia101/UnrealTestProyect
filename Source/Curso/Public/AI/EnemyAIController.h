// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Perception/AIPerceptionTypes.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class CURSO_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category= "Components")
	UAIPerceptionComponent* AIPerceptionComponent;

	UPROPERTY(EditDefaultsOnly,Category= "Settings")
	UBehaviorTree* BTAsset = nullptr;

	UPROPERTY(EditDefaultsOnly,Category= "Settings")
	FName PlayerTag;

	UPROPERTY(EditDefaultsOnly,Category= "Settings")
	FName HasLineOfSightKey;

	UPROPERTY(EditDefaultsOnly,Category= "Settings")
	FName TargetActorKey;

	UPROPERTY()
	UBlackboardComponent* BlackboardComponent;
	
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UFUNCTION()
	void HandleOnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
	
public:
	AEnemyAIController();
};
