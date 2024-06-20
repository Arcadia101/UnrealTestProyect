// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/ProjectileActor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
AProjectileActor::AProjectileActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>("CollisionComponent");
	CollisionComponent->InitSphereRadius(5.0f);
	CollisionComponent->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComponent->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable,0.0f));
	CollisionComponent->CanCharacterStepUpOn = ECB_No;
	RootComponent = CollisionComponent;

	ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("ProjectileMeshComponent");
	ProjectileMeshComponent->BodyInstance.SetCollisionProfileName("NoCollision");
	ProjectileMeshComponent->SetupAttachment(RootComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	ProjectileMovementComponent->UpdatedComponent = CollisionComponent;
	ProjectileMovementComponent->InitialSpeed = 300.0f;
	ProjectileMovementComponent->MaxSpeed = 300.0f;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f;

	InitialLifeSpan = 3.0f;
	
}

void AProjectileActor::BeginPlay()
{
	Super::BeginPlay();

	CollisionComponent->OnComponentHit.AddDynamic(this, &AProjectileActor::OnHit);
}

void AProjectileActor::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& Hit)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Orange, FString::Printf(TEXT("OtherActor: %s"), *OtherActor->GetName()));
	Destroy();
}

