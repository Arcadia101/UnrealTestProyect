// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class CURSO_API UPlayerWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UTextBlock* PlayerHealthText;

	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void HandleUpdateHealth();

	UFUNCTION()
	void UpdateHealthText(int32 CurrentHealth);
public:
};
