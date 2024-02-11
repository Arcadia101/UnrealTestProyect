// Fill out your copyright notice in the Description page of Project Settings.


#include "Curso/Public/Character/PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent-> SetupAttachment(RootComponent);
	SpringArmComponent-> TargetArmLength = 400.0f;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent-> SetupAttachment(SpringArmComponent);
	
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
}

void APlayerCharacter::Move(const FInputActionValue& InputActionValue)
{
	FVector2d MovementVector = InputActionValue.Get<FVector2d>();
	if (!IsValid(Controller)) return;

	const FRotator Rotation = Controller-> GetControlRotation();
	const FRotator YawRotation = FRotator(0,Rotation.Yaw,0);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	AddMovementInput(ForwardDirection,MovementVector.Y);
	AddMovementInput(RightDirection,MovementVector.X);
}



// Called every frame
/*void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}*/
