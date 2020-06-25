// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTracks.h"


UTankTracks::UTankTracks()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UTankTracks::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTracks::OnHit);
}

void UTankTracks::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveTracks();
	ApplySidewaysforce();
	//Apply Sideways Force
	CurretThrottle = 0.f;
}


void UTankTracks::ApplySidewaysforce()
{
	//Calculate slippage(sic?) speed
	auto SlippageSpeed = FVector::DotProduct(GetComponentVelocity(), GetRightVector());

	//Work out required acceleration this frame to correct
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	//Calculate and apply sideways force (F = m a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Two Tracks

	TankRoot->AddForce(CorrectionForce);
}


void UTankTracks::SetThrottle(float Throttle)
{
	CurretThrottle = FMath::Clamp<float>(CurretThrottle + Throttle, -1.5, 1.5);
}

void UTankTracks::DriveTracks()
{
	auto ForceApplied = GetForwardVector() * CurretThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}