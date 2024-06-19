// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstance.generated.h"

class UCharacterMovementComponent;
UCLASS()
class CURSO_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	UCharacterMovementComponent* CharacterMovementComponent;

	UPROPERTY(BlueprintReadOnly)
	bool bShouldBeMove = false;
	
	UPROPERTY(BlueprintReadOnly)
	bool bIsFalling = false;
	
	UPROPERTY(BlueprintReadOnly)
	float Velocity;
	
	UPROPERTY(BlueprintReadOnly)
	float ZVelocity;
	
};
