// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileActor.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class CURSO_API AProjectileActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectileActor();

protected:

	UPROPERTY(EditDefaultsOnly,Category=Components)
	UStaticMeshComponent* ProjectileMeshComponent;

	UPROPERTY(EditDefaultsOnly,Category=Components)
	USphereComponent* ProjectileCollisionComponent;

	UPROPERTY(EditDefaultsOnly,Category=Components)
	UProjectileMovementComponent* ProjectileMovementComponent;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	void OnProjectHit(UPrimitiveComponent* HitComponent,AActor* OtherActor,UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:
	// Called every frame
};
