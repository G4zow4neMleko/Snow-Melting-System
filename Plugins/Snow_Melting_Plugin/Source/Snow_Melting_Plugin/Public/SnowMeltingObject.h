// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnowMeltingObject.generated.h"

UCLASS(Abstract)
class SNOW_MELTING_PLUGIN_API ASnowMeltingObject : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASnowMeltingObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Customize")
	float MaxSpeed = 0.0f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Customize")
	float MinSpeed = 0.0f;
};
