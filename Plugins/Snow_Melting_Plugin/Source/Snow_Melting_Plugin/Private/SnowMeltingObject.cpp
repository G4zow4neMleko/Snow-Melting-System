// Fill out your copyright notice in the Description page of Project Settings.


#include "SnowMeltingObject.h"

#include <filesystem>


// Sets default values
ASnowMeltingObject::ASnowMeltingObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Sphere_Sphere");
	MeshComponent->SetRenderCustomDepth(true);
}

// Called when the game starts or when spawned
void ASnowMeltingObject::BeginPlay()
{
	Super::BeginPlay();
	const FVector Velocity = FVector(FMath::RandRange(-1000,1000),FMath::RandRange(-1000,1000),0);
	MeshComponent->AddImpulse(Velocity, EName::None,true);
}

// Called every frame
void ASnowMeltingObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

