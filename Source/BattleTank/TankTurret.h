// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:

void Azimuth(float RelativeSpeed);

private:

	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 15.f; 

	UPROPERTY(EditAnywhere)
	float MaxRotateInDegrees = 360.f;

	UPROPERTY(EditAnywhere)
	float MinRotateInDegrees = -360.f;
	
};
