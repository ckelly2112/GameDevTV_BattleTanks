// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked
};


//Forward Declaration
class UTankBarrel; 
class UTankTurret;
class AProjectile;
// Hold parameters for barrel properties
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Controls)
	void Fire();

protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringStatus FiringStatus = EFiringStatus::Aiming;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	double LastFireTime = 0;


	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000.f;
	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3.f;
	
	void MoveBarrelTowards(FVector AimDirection);
	void MoveTurretTowards(FVector AimDirection);

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

		
};
