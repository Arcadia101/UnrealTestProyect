// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateHealth,int32,CurrentHealth);

class UPlayerWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CURSO_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	FOnUpdateHealth OnUpdateHealth;
	
	// Sets default values for this component's properties
	UHealthComponent();

	int32 GetCurrentHealth() const {return CurrentHealth;}
	bool IsDead() const {return CurrentHealth <= 0;}
	void UpdateCurrentHealth(int32 AmountHealth);
	void Dead();


protected:
	UPROPERTY(EditDefaultsOnly, Category=Settings)
	int32 MaxHealth = 100;
	
	int32 CurrentHealth = 0;

	virtual void BeginPlay() override;
};
