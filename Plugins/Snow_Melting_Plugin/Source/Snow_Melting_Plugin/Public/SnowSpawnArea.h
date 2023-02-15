// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SnowMeltingObject.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "SnowSpawnArea.generated.h"

class ASnowMeltingObject;

UCLASS(Abstract)
class SNOW_MELTING_PLUGIN_API ASnowSpawnArea : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASnowSpawnArea();

#if WITH_EDITOR
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "")
	UBoxComponent* BoxComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customize")
	TSoftClassPtr<ASnowMeltingObject> SingleSnowMeltingObject;
	
	UPROPERTY(EditAnywhere, Category = "Customize")
	uint32 Quantity = 0;

	UPROPERTY(Category = "")
	TArray<ASnowMeltingObject*> MovableObjects;
	
private:
	void SetUpMovableObjects();
};
