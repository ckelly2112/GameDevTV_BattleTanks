// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    if (!GetControlledTank())
    {
        UE_LOG(LogTemp, Error, TEXT("Pawn not possessed"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("%s Posessed by Player"), *GetControlledTank()->GetName());
    }
    

}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick( DeltaTime );
    AimTowardsCrosshair();


    //Aim Toward Crosshair
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if(!GetControlledTank()) {return;}

    FVector HitLocation;
    if(GetSightRayHitLocation(HitLocation)) // Has "Side-effect" that it is going to line trace
    {
        // TODO Tell controlled tank to aim at this point
    }

    //Get world location of linetrace through crosshair
   
}

//Returns true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
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
        // GetVectorHitLocation();
    }

    return true;
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

bool ATankPlayerController::GetLookVectorHitLocation()
{

    //TODO Actually make this do something
    FVector Start, End;
    FHitResult Hit;
    GetWorld()->LineTraceSingleByChannel
    (
        Hit,
        Start,
        End,
        ECollisionChannel::ECC_Visibility
    );
    return false;
}