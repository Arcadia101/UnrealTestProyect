// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerWidget.h"
#include "Components/TextBlock.h"

void UPlayerWidget::UpdateHealthText(int32 CurrentHealth)
{
	FString StringCurrentHealth = FString::FromInt(CurrentHealth);
	FText TextCurrentHealth = FText::FromString(StringCurrentHealth);
	PlayerHealthText->SetText(TextCurrentHealth);
}
