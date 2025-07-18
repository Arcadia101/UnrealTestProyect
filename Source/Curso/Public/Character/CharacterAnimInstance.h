// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

class UCharacterMovementComponent;
class APlayerCharacter;
class UCameraComponent;

UCLASS()
class CURSO_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	UCharacterMovementComponent* CharacterMovementComponent;

	UPROPERTY()
	ACharacter* PlayerCharacter;

	UPROPERTY()
	UCameraComponent* CameraComponent;

	UPROPERTY(BlueprintReadOnly)
	bool bShouldBeMove = false;
	
	UPROPERTY(BlueprintReadOnly)
	bool bIsFalling = false;
	
	UPROPERTY(BlueprintReadOnly)
	float Velocity;
	
	UPROPERTY(BlueprintReadOnly)
	float ZVelocity;

	UPROPERTY(BlueprintReadOnly)
	float XRotator;

	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};
