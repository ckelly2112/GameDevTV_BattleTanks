// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Tank Barrel that controls barrel elevation
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
public:
	GENERATED_BODY()

	// -1 is max downward speed, and +1 is max up movement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly)
	float MaxDegreesPerSecond = 5.f;

	UPROPERTY(EditDefaultsOnly)
	float MaxElevationInDegrees = 25.f;

	UPROPERTY(EditDefaultsOnly)
	float MinElevationInDegrees = 0.f;
	
};
