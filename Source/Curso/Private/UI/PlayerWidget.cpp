// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PlayerWidget.h"
#include "Components/HealthComponent.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UPlayerWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	APawn* Pawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
	if(!IsValid(Pawn)) return;

	UHealthComponent* HealthComponent = Pawn->FindComponentByClass<UHealthComponent>();
	if(!IsValid(HealthComponent)) return;
	HealthComponent->OnUpdateHealth.AddDynamic(this, &UPlayerWidget::UpdateHealthText);
}

void UPlayerWidget::HandleUpdateHealth()
{
	GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Cyan,TEXT("HandleUpdateHealth"));
}

void UPlayerWidget::UpdateHealthText(int32 CurrentHealth)
{
	FString StringCurrentHealth = FString::FromInt(CurrentHealth);
	FText TextCurrentHealth = FText::FromString(StringCurrentHealth);
	PlayerHealthText->SetText(TextCurrentHealth);
}
