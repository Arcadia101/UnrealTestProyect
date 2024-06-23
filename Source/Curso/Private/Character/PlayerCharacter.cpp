// Fill out your copyright notice in the Description page of Project Settings.


#include "Curso/Public/Character/PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Actors/ProjectileActor.h"
#include "Components/GunComponent.h"
#include "Components/HealthComponent.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent-> SetupAttachment(RootComponent);
	SpringArmComponent-> TargetArmLength = 400.0f;
	SpringArmComponent-> bUsePawnControlRotation = true;

	ThirdCameraComponent = CreateDefaultSubobject<UCameraComponent>("Third Camera");
	ThirdCameraComponent-> SetupAttachment(SpringArmComponent);
	ThirdCameraComponent-> bUsePawnControlRotation = false;

	FirstCameraComponent = CreateDefaultSubobject<UCameraComponent>("First Camera");
	FirstCameraComponent-> SetupAttachment(GetMesh(), "Eyes_Position");
	FirstCameraComponent-> bUsePawnControlRotation = true;

	GunComponent = CreateDefaultSubobject<UGunComponent>("GunComponent");
	GunComponent->SetupAttachment(RootComponent);
	
	FireSceneComponent = CreateDefaultSubobject<USceneComponent>("FireSceneComponent");
	FireSceneComponent->SetupAttachment(GunComponent);

	HealthComponent = CreateDefaultSubobject<UHealthComponent>("HealthComponent");
	
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (!IsValid(PlayerController)) return;
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	if (!IsValid(Subsystem)) return;
	
	Subsystem-> AddMappingContext(DefaultMappingContext,0);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!IsValid(EnhancedInputComponent)) return;

	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered, this, &APlayerCharacter::Move);
	EnhancedInputComponent->BindAction(LookAction,ETriggerEvent::Triggered,this, &APlayerCharacter::Look);

	EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Started,this,&ACharacter::Jump);
	EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Completed,this,&ACharacter::StopJumping);

	EnhancedInputComponent->BindAction(FireAction,ETriggerEvent::Started,this,&APlayerCharacter::Fire);
	
	EnhancedInputComponent->BindAction(ChangeCameraAction, ETriggerEvent::Started, this,&APlayerCharacter::ChangeFirstCamera);
	EnhancedInputComponent->BindAction(ChangeCameraAction, ETriggerEvent::Completed, this,&APlayerCharacter::ChangeThirdCamera);
}

void APlayerCharacter::Move(const FInputActionValue& InputActionValue)
{
	if (!IsValid(Controller)) return;
	FVector2d MovementVector = InputActionValue.Get<FVector2d>();

	const FRotator Rotation = Controller-> GetControlRotation();
	const FRotator YawRotation = FRotator(0,Rotation.Yaw,0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection,MovementVector.Y);
	AddMovementInput(RightDirection,MovementVector.X);
}

void APlayerCharacter::Look(const FInputActionValue& InputActionValue)
{
	if (!IsValid(Controller)) return;
	FVector2d LookVector = InputActionValue.Get<FVector2d>();

	AddControllerYawInput(LookVector.X);
	AddControllerPitchInput(LookVector.Y);
}

void APlayerCharacter::Fire(const FInputActionValue& Value)
{
	/*FVector SpawnPos = FireSceneComponent->GetComponentLocation();
	FRotator SpawnRot = FireSceneComponent->GetComponentRotation();

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = this;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

	GetWorld()->SpawnActor<AProjectileActor>(ProjectileActorClass,SpawnPos,SpawnRot,SpawnInfo);*/

	GunComponent->Fire(FireSceneComponent);
}

void APlayerCharacter::ChangeFirstCamera()
{
	ThirdCameraComponent->SetActive(false);
	FirstCameraComponent->SetActive(true);

	bUseControllerRotationYaw = true;
}

void APlayerCharacter::ChangeThirdCamera()
{
	FirstCameraComponent->SetActive(false);
	ThirdCameraComponent->SetActive(true);

	bUseControllerRotationYaw = false;
}
