// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 20.f;

	UPROPERTY(EditAnywhere)
	float MaxElevationInDegrees = 30.f;

	UPROPERTY(EditAnywhere)
	float MinElevationInDegrees = 0.f;
	
};
