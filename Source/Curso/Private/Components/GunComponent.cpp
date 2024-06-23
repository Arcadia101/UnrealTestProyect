// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/GunComponent.h"

UGunComponent::UGunComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UGunComponent::Fire(USceneComponent* FirePosComponent)
{
	FHitResult OutHit;
	FVector StartPos = FirePosComponent->GetComponentLocation();
	FVector EndPos = StartPos + (FirePosComponent->GetForwardVector()*Distance);
	FCollisionQueryParams CollisionQueryParams;

	DrawDebugLine(GetWorld(),StartPos,EndPos,FColor::Green);

	if (GetWorld()->LineTraceSingleByChannel(OutHit,StartPos,EndPos,ECC_Visibility,CollisionQueryParams))
	{
		if (OutHit.bBlockingHit)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("Hitting Actor: %s, Impact Point: %s, Impact Normal: %s"),
				*OutHit.GetActor()->GetName(),
				*OutHit.ImpactPoint.ToString(),
				*OutHit.ImpactNormal.ToString()));
		}
	}
}
