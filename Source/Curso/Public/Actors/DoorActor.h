// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "DoorActor.generated.h"

UCLASS()
class CURSO_API ADoorActor : public AActor,public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorActor();
	
	virtual void Interact_Implementation(AActor* Interactor) override;
protected:

	UPROPERTY(EditAnywhere, Category=Settings)
	FVector DoorMovementOffset;
	
	bool bIsOpen;

	void OpenClose();
};
