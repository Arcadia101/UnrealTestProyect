// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WeaponBaseComponent.h"
#include "RifleComponent.generated.h"

/**
 * 
 */
UCLASS()
class CURSO_API URifleComponent : public UWeaponBaseComponent
{
	GENERATED_BODY()
public:
	virtual void Fire(FVector Position, FVector Forward) override;
	virtual void Reload() override;
};
