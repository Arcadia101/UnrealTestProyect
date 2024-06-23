// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GunComponent.generated.h"

UCLASS()
class CURSO_API UGunComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UGunComponent();

	void Fire(USceneComponent* FirePosComponent);

protected:

	UPROPERTY(EditDefaultsOnly, Category=Settings)
	float Distance = 1000.0f;
};
