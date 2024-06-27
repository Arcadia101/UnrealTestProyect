// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponBaseComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GunComponent.generated.h"

UCLASS()
class CURSO_API UGunComponent : public UWeaponBaseComponent
{
	GENERATED_BODY()

public:
	UGunComponent();

	virtual void Fire(FVector Position, FVector Forward) override;
	virtual void Reload() override;

protected:

	UPROPERTY(EditDefaultsOnly, Category=Settings)
	float Distance = 1000.0f;
};
