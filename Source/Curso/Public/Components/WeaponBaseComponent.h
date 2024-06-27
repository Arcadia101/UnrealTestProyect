// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "WeaponBaseComponent.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class CURSO_API UWeaponBaseComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	virtual void Fire(FVector Position, FVector Forward) PURE_VIRTUAL();
	virtual void Reload() PURE_VIRTUAL();
};
