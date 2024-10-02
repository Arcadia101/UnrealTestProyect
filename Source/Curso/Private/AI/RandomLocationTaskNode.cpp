// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/RandomLocationTaskNode.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type URandomLocationTaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const AAIController* AIController = OwnerComp.GetAIOwner();
	if(!IsValid(AIController)) return EBTNodeResult::Failed;
	APawn* Pawn = AIController->GetPawn();
	if(!IsValid(Pawn)) return EBTNodeResult::Failed;

	FVector RandomPoint;
	const UNavigationSystemV1* NavigationSystemV1 = UNavigationSystemV1::GetCurrent(Pawn);
	if(!IsValid(NavigationSystemV1)) return EBTNodeResult::Failed;
	FNavLocation NavLocation;
	if (NavigationSystemV1->GetRandomPointInNavigableRadius(Pawn->GetActorLocation(),Radius,NavLocation))
	{
		RandomPoint = NavLocation.Location;
	}
	else
	{
		RandomPoint = Pawn->GetActorLocation();
	}
	UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if(!IsValid(BlackboardComponent)) return EBTNodeResult::Failed;
	BlackboardComponent->SetValueAsVector(TargetLocationKey.SelectedKeyName, RandomPoint);
	
	return EBTNodeResult::Succeeded;
}
