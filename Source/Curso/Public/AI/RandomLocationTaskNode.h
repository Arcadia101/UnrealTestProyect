// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "RandomLocationTaskNode.generated.h"

/**
 * 
 */
UCLASS()
class CURSO_API URandomLocationTaskNode : public UBTTaskNode
{
	GENERATED_BODY()
	
	
public:
	UPROPERTY(EditAnywhere, Category= "Blackboard")
	FBlackboardKeySelector TargetLocationKey;

	UPROPERTY(EditAnywhere, Category= "AI")
	float Radius = 500.0f;

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
