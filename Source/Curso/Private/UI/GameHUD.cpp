// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GameHUD.h"
#include "UI/PlayerWidget.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	if(!IsValid(PlayerWidgetClass)) return;

	UPlayerWidget* PlayerWidget = CreateWidget<UPlayerWidget>(GetWorld(), PlayerWidgetClass);
	PlayerWidget-> AddToViewport();

	PlayerWidget-> UpdateHealthText(100);
}
