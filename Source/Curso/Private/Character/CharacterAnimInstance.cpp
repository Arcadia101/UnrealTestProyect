// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	APawn* Pawn = TryGetPawnOwner();
	if (!IsValid(Pawn)) return;
	CharacterMovementComponent = Pawn->GetComponentByClass<UCharacterMovementComponent>();
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!IsValid(CharacterMovementComponent)) return;

	const FVector CharacterVelocity = CharacterMovementComponent->Velocity;
	Velocity = CharacterVelocity.Size2D();
	bShouldBeMove = Velocity > 0;

	ZVelocity = CharacterVelocity.Z;
	bIsFalling = CharacterMovementComponent->IsFalling();
}
