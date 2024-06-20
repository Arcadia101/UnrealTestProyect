// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

class UPlayerWidget;

UCLASS()
class CURSO_API AGameHUD : public AHUD
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category=Settings)
	TSubclassOf<UPlayerWidget> PlayerWidgetClass;

	virtual void BeginPlay() override;
};
