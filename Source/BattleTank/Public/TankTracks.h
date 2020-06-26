// Christopher Kelly
// Check out www.chriskelly48th.ca for contact info
#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * Tank track static mesh componenents that handle the driving of the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	void DriveTracks();
	// Max force per track, in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000.0f; // Assume 40 tonne tank with 1g acceleration

private:

	UTankTracks();
	void ApplySidewaysforce();
	void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = HitEvents)
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	float CurretThrottle = 0.f;
};
