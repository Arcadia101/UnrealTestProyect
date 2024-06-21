// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/HealthComponent.h"
#include "UI/PlayerWidget.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UHealthComponent::UpdateCurrentHealth(int32 AmountHealth)
{
	CurrentHealth += AmountHealth;

	/*CurrentHealth = (CurrentHealth > MaxHealth) ? MaxHealth:CurrentHealth;
	CurrentHealth = (CurrentHealth < 0) ? 0:CurrentHealth;*/

	CurrentHealth = FMath::Clamp(CurrentHealth, 0, MaxHealth);
	
	if (CurrentHealth <= 0)
	{
		Dead();
	}

	OnUpdateHealth.Broadcast(CurrentHealth);
}

void UHealthComponent::Dead()
{
	GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Red,TEXT("Player Is Dead"));
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	UpdateCurrentHealth(MaxHealth);
	
}


