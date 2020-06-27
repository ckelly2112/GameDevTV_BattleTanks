// Christopher Kelly
// Check out www.chriskelly48th.ca for contact info

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

	
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick( DeltaTime );
	if (!GetPawn()) { return; }
    AimTowardsCrosshair();
}


void ATankPlayerController::AimTowardsCrosshair()
{
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }

    FVector HitLocation(0);
    if(GetSightRayHitLocation(HitLocation)) // This Gets the target location through a series of calculations
    {
        AimingComponent->AimAt(HitLocation);
    }

   
}

//Returns true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& out_HitLocation) const
{   
    //Find crosshair position
    int32 ViewPortSizeX, ViewPortSizeY;
    GetViewportSize(ViewPortSizeX, ViewPortSizeY);

    // De-Project the screen position of the crosshair to a world direction
    FVector2D ScreenLocation(CrosshairXLocation * ViewPortSizeX, CrosshairYLocation * ViewPortSizeY);
    FVector LookDirection;
    if(GetLookDirection(ScreenLocation, LookDirection))
    {
        //Line-Trace along that look direction and see what we hit
		return GetLookVectorHitLocation(LookDirection, out_HitLocation);
    }

    //If Not
    return false;

}


bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& out_HitLocation) const
{

    FHitResult HitResult;
    FVector StartLocation = PlayerCameraManager->GetCameraLocation();
    FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);
    if (GetWorld()->LineTraceSingleByChannel
        (
            HitResult,
            StartLocation,
            EndLocation,
            ECollisionChannel::ECC_Visibility
        ))
    {
        out_HitLocation = HitResult.Location;
        return true;
    }
    return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& out_LookDirection) const
{
    FVector LookLocation; // Will be discarded

   return DeprojectScreenPositionToWorld
    (
        ScreenLocation.X, 
        ScreenLocation.Y, 
        LookLocation, 
        out_LookDirection
    );

}

void ATankPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		//Subscribe our local method to the tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPossessedTankDeath);
	}
}

void ATankPlayerController::OnPossessedTankDeath()
{
	if (!GetPawn()) { return; }
	StartSpectatingOnly();
}

