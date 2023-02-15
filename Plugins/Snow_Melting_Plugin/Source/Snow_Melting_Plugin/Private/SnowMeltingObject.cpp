// Fill out your copyright notice in the Description page of Project Settings.


#include "SnowMeltingObject.h"


// Sets default values
ASnowMeltingObject::ASnowMeltingObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	MeshComponent->SetRenderCustomDepth(true);
	MeshComponent->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void ASnowMeltingObject::BeginPlay()
{
	Super::BeginPlay();
		
	const float Velocity = FMath::RandRange(MinSpeed,MaxSpeed);
	FVector Direction = FMath::VRand();
	Direction.Z = 0.0f;
	Direction.Normalize(0.0001f);
	MeshComponent->AddImpulse(Velocity * Direction, EName::None,true);
}

// Called every frame
void ASnowMeltingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

