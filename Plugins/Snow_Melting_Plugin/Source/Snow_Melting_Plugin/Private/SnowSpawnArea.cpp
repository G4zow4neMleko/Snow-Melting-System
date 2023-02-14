// Fill out your copyright notice in the Description page of Project Settings.


#include "SnowSpawnArea.h"

#include "Kismet/KismetMathLibrary.h"


// Sets default values
ASnowSpawnArea::ASnowSpawnArea()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>("Box");
	SetUpMovableObjects();
}

void ASnowSpawnArea::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if(PropertyChangedEvent.GetPropertyName().ToString().Contains("Quantity") ||
		PropertyChangedEvent.GetPropertyName().ToString().Contains("SingleSnowMeltingObject"))
	{
		SetUpMovableObjects();
	}
}

// Called when the game starts or when spawned
void ASnowSpawnArea::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASnowSpawnArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
	for (auto &MovableObject : MovableObjects)
	{
		if( !IsOverlappingActor(MovableObject))
		{
			MovableObject->SetActorHiddenInGame(true);
			MovableObject->DisableComponentsSimulatePhysics();
			MovableObject->SetActorEnableCollision(false);
			//MovableObject->Destroy();
		}
	}
}

void ASnowSpawnArea::SetUpMovableObjects()
{
	if(!SingleSnowMeltingObject.Get()){return;}
	
	for (auto &MovableObject : MovableObjects)
	{
		MovableObject->Destroy();
	}
	
	MovableObjects.SetNum(Quantity);
	
	FVector3d SpawnPoint(0.0f,0.0f,0.0f);
	for (auto &MovableObject : MovableObjects)
	{
		MovableObject = Cast<ASnowMeltingObject>(GetWorld()->SpawnActor(SingleSnowMeltingObject.Get()));
		SpawnPoint = FMath::RandPointInBox(BoxComponent->GetNavigationBounds());
		MovableObject->SetActorLocation(SpawnPoint);
		//MovableObject->SingleMovableObj->SetStaticMesh();
	}
}

/*void ASnowSpawnArea::UpdateMeshes()
{
	for (auto &MovableObject : MovableObjects)
	{
		MovableObject->SingleMovableObj->SetStaticMesh();
	}
}*/

