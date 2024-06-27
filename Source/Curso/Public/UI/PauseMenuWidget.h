// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenuWidget.generated.h"

class UButton;
class UVerticalBox;
class UWidgetSwitcher;
class USettingsWidget;

UCLASS()
class CURSO_API UPauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UButton* ResumeButton;
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UButton* SettingsButton;
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UButton* QuitButton;
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UButton* BackButton;
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UVerticalBox* VerticalBox;
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	UWidgetSwitcher* WidgetSwitcher;
	UPROPERTY(EditDefaultsOnly, meta=(BindWidget))
	USettingsWidget* SettingsWidget;
	
	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void HandleOnResumeBottonPressed();

	UFUNCTION()
	void HandleOnSettingsBottonPressed();

	UFUNCTION()
	void HandleOnQuitBottonPressed();
	
	UFUNCTION()
	void HandleOnBackBottonPressed();
};
