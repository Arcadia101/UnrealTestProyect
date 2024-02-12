// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"


struct FInputActionValue;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class AProjectileActor;

UCLASS()
class CURSO_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	UPROPERTY(EditDefaultsOnly, Category=Components)
	USpringArmComponent* SpringArmComponent;
	
	UPROPERTY(EditDefaultsOnly, Category=Components)
	UCameraComponent* CameraComponent;

	UPROPERTY(EditDefaultsOnly, Category=Components)
	USceneComponent* FireSceneComponent;

	UPROPERTY(EditDefaultsOnly, Category=Input)
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, Category=Input)
	UInputAction* MoveAction;
	
	UPROPERTY(EditDefaultsOnly, Category=Input)
	UInputAction* LookAction;
	
	UPROPERTY(EditDefaultsOnly, Category=Input)
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, Category=Input)
	UInputAction* FireAction;

	UPROPERTY(EditDefaultsOnly, Category=ProjectileConfig)
	TSubclassOf<AProjectileActor> ProjectileActorClass;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Fire(const FInputActionValue& Value);

public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
