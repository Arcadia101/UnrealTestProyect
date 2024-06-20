// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PushCharacterActor.generated.h"

class UBoxComponent;

UCLASS()
class CURSO_API APushCharacterActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APushCharacterActor();

protected:
	UPROPERTY(EditAnywhere)
	UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, Category=Settings)
	float ForceImpulse = 500.0f;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
		int32 OtherBodyComponent, bool bFromSweep, const FHitResult& SweepResults);

	UFUNCTION()
	void EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyComponent);

};
