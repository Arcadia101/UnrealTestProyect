// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/EnemyAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
	if(IsValid(AIPerceptionComponent))
	{
		AIPerceptionComponent->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &AEnemyAIController::HandleOnTargetPerceptionUpdated);
	}

	RunBehaviorTree(BTAsset);
	BlackboardComponent = GetBlackboardComponent();
}

void AEnemyAIController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	AIPerceptionComponent->OnTargetPerceptionUpdated.RemoveAll(this);
	Super::EndPlay(EndPlayReason);
}

void AEnemyAIController::HandleOnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if(!IsValid(BlackboardComponent)) return;
	if (Actor->ActorHasTag(PlayerTag) && Stimulus.WasSuccessfullySensed())
	{
		BlackboardComponent->SetValueAsBool(HasLineOfSightKey, true);
		BlackboardComponent->SetValueAsObject(TargetActorKey, Actor);
	}
	else
	{
		BlackboardComponent->SetValueAsBool(HasLineOfSightKey, true);
	}
}

ETeamAttitude::Type AEnemyAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	const IGenericTeamAgentInterface* PossedPawnTeamAgent = Cast<IGenericTeamAgentInterface>(GetPawn());
	const IGenericTeamAgentInterface* OtherPawnTeamAgent = Cast<IGenericTeamAgentInterface>(&Other);
	if(PossedPawnTeamAgent !=nullptr && OtherPawnTeamAgent !=nullptr)
	{
		return (PossedPawnTeamAgent->GetGenericTeamId() == OtherPawnTeamAgent->GetGenericTeamId())?ETeamAttitude::Friendly:ETeamAttitude::Hostile;
	}
	return ETeamAttitude::Neutral;
}

AEnemyAIController::AEnemyAIController()
{
	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>("AIPerceptionComponent");
}
