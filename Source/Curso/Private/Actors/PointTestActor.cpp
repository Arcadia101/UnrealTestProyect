// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/PointTestActor.h"

#include "Components/HealthComponent.h"
#include "SubSystems/ScoreSubsystem.h"

// Sets default values
APointTestActor::APointTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	SetRootComponent(StaticMeshComponent);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
	
}

// Called when the game starts or when spawned
void APointTestActor::BeginPlay()
{
	Super::BeginPlay();

	HealthComponent->OnUpdateHealth.AddUniqueDynamic(this, &APointTestActor::HandleOnUpdateHealth);
}

void APointTestActor::HandleOnUpdateHealth(int32 CurrentHealth)
{
	if(HealthComponent->IsDead())
	{
		UScoreSubsystem* ScoreSubsystem = GetGameInstance()->GetSubsystem<UScoreSubsystem>();
		if(!IsValid(ScoreSubsystem)) return;

		ScoreSubsystem->AddPoints(100);

		HealthComponent->OnUpdateHealth.RemoveAll(this);
	}
}


