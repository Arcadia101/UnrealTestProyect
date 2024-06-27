// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/DoorActor.h"

// Sets default values
ADoorActor::ADoorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

void ADoorActor::Interact_Implementation(AActor* Interactor)
{
	bIsOpen = !bIsOpen;
	OpenClose();
}

void ADoorActor::OpenClose()
{
	FVector DoorLocation = GetActorLocation() + DoorMovementOffset*((bIsOpen)? -1:1);
	SetActorLocation(DoorLocation);
}


