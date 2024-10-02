// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/Character.h"
#include "UI/PauseMenuWidget.h"
#include "PlayerCharacter.generated.h"


struct FInputActionValue;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class AProjectileActor;
class UHealthComponent;
class UGunComponent;

UCLASS()
class CURSO_API APlayerCharacter : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	UPROPERTY(EditDefaultsOnly, Category=Components)
	USpringArmComponent* SpringArmComponent;
	
	UPROPERTY(EditDefaultsOnly, Category=Components)
	UCameraComponent* ThirdCameraComponent;

	UPROPERTY(EditDefaultsOnly, Category=Components)
	UCameraComponent* FirstCameraComponent;

	UPROPERTY(EditDefaultsOnly, Category=Components)
	USceneComponent* FireSceneComponent;

	UPROPERTY(EditDefaultsOnly, Category=Components)
	UHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly, Category=Components)
	UGunComponent* GunComponent;

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

	UPROPERTY(EditDefaultsOnly, Category=Input)
	UInputAction* ChangeCameraAction;

	UPROPERTY(EditDefaultsOnly, Category=Input)
	UInputAction* InteractionAction;

	UPROPERTY(EditDefaultsOnly, Category=Input)
	UInputAction* PauseAction;

	UPROPERTY(EditDefaultsOnly, Category=Settings)
	float InteractDistance = 200.0f;

	UPROPERTY(EditDefaultsOnly, Category=ProjectileConfig)
	TSubclassOf<AProjectileActor> ProjectileActorClass;

	UPROPERTY(EditDefaultsOnly, Category=Settings)
	TSubclassOf<UPauseMenuWidget> PauseMenuWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category=Teams)
	int32 TeamId = 100;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Fire();
	void Interact();
	void Pause();

	void ChangeFirstCamera();
	void ChangeThirdCamera();

	virtual FGenericTeamId GetGenericTeamId() const override;

	UFUNCTION()
	void HandleOnScoreUpdated(const int32 CurrentPoints);
public:
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UCameraComponent* GetThirdCameraComponent() const {return ThirdCameraComponent;}
};
