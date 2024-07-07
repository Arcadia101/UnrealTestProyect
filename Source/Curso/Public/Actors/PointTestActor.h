// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointTestActor.generated.h"

class UHealthComponent;

UCLASS()
class CURSO_API APointTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APointTestActor();

protected:
	UPROPERTY(EditDefaultsOnly, Category= "Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditDefaultsOnly, Category= "Components")
	UHealthComponent* HealthComponent;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void HandleOnUpdateHealth(int32 CurrentHealth);
	

};
