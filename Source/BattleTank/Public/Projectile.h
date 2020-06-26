// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;
UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LaunchProjectile(float Speed);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UProjectileMovementComponent* ProjectileMovementComponent = nullptr;

private:	
	
	UPROPERTY(VisibleAnywhere, Category = Setup)
	UStaticMeshComponent* CollisionMesh = nullptr;
	UPROPERTY(VisibleAnywhere, Category = Setup)
	UParticleSystemComponent* LaunchBlast = nullptr;
	UPROPERTY(VisibleAnywhere, Category = Setup)
	UParticleSystemComponent* ImpactBlast = nullptr;

	UFUNCTION(BlueprintCallable, Category = HitEvents)
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
