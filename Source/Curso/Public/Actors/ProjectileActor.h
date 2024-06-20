// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileActor.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UStaticMeshComponent;

UCLASS()
class CURSO_API AProjectileActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectileActor();

protected:

	UPROPERTY(VisibleDefaultsOnly, Category=Components)
	USphereComponent* CollisionComponent;

	UPROPERTY(VisibleDefaultsOnly, Category=Components)
	UStaticMeshComponent* ProjectileMeshComponent;
	
	UPROPERTY(VisibleDefaultsOnly, Category=Components)
	UProjectileMovementComponent* ProjectileMovementComponent;

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
