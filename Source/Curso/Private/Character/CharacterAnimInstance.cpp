// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterAnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Character/PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCharacterAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	APawn* Pawn = TryGetPawnOwner();
	if (!IsValid(Pawn)) return;
	CharacterMovementComponent = Pawn->GetComponentByClass<UCharacterMovementComponent>();

	PlayerCharacter = Cast<ACharacter>(Pawn);
	CameraComponent = PlayerCharacter->FindComponentByClass<UCameraComponent>();

	
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!IsValid(CharacterMovementComponent) || !IsValid(PlayerCharacter)) return;

	const FVector CharacterVelocity = CharacterMovementComponent->Velocity;
	Velocity = CharacterVelocity.Size2D();
	bShouldBeMove = Velocity > 0;

	ZVelocity = CharacterVelocity.Z;
	bIsFalling = CharacterMovementComponent->IsFalling();

	if (!IsValid(CameraComponent)) return;
	XRotator = -CameraComponent->GetComponentRotation().Pitch;
}
