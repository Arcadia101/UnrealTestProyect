// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PauseMenuWidget.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/VerticalBox.h"
#include "Kismet/KismetSystemLibrary.h"
#include "UI/SettingsWidget.h"


void UPauseMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ResumeButton->OnPressed.AddUniqueDynamic(this, &UPauseMenuWidget::HandleOnResumeBottonPressed);
	SettingsButton->OnPressed.AddUniqueDynamic(this, &UPauseMenuWidget::HandleOnSettingsBottonPressed);
	QuitButton->OnPressed.AddUniqueDynamic(this, &UPauseMenuWidget::HandleOnQuitBottonPressed);
	BackButton->OnPressed.AddUniqueDynamic(this, &UPauseMenuWidget::HandleOnBackBottonPressed);

	BackButton->SetVisibility(ESlateVisibility::Collapsed);
}

void UPauseMenuWidget::HandleOnResumeBottonPressed()
{
	const UWorld* World = GetWorld();
	if(!IsValid(World)) return;
	APlayerController* PlayerController = World->GetFirstPlayerController();
	if(!IsValid(PlayerController)) return;

	PlayerController->SetShowMouseCursor(false);
	PlayerController->SetInputMode(FInputModeGameOnly());
	PlayerController->SetPause(false);

	RemoveFromParent();
}

void UPauseMenuWidget::HandleOnSettingsBottonPressed()
{
	WidgetSwitcher->SetActiveWidget(SettingsWidget);
	BackButton->SetVisibility(ESlateVisibility::Visible);
}

void UPauseMenuWidget::HandleOnQuitBottonPressed()
{
	const UWorld* World = GetWorld();
	if(!IsValid(World)) return;

	UKismetSystemLibrary::QuitGame(World, World->GetFirstPlayerController(),EQuitPreference::Quit,false);
}

void UPauseMenuWidget::HandleOnBackBottonPressed()
{
	WidgetSwitcher->SetActiveWidget(VerticalBox);
	BackButton->SetVisibility(ESlateVisibility::Collapsed);
}
