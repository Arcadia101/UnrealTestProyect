// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/PushCharacterActor.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"

// Sets default values
APushCharacterActor::APushCharacterActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	RootComponent = BoxComponent;
	BoxComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

// Called when the game starts or when spawned
void APushCharacterActor::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &APushCharacterActor::BeginOverlap);
	BoxComponent->OnComponentEndOverlap.AddUniqueDynamic(this, &APushCharacterActor::EndOverlap);
}

void APushCharacterActor::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyComponent, bool bFromSweep, const FHitResult& SweepResults)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, TEXT("Enter"));
	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (!IsValid(Character)) return;

	Character->LaunchCharacter(-OtherActor->GetActorForwardVector()*ForceImpulse,true,false);
}

void APushCharacterActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyComponent)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Exit"));
}


