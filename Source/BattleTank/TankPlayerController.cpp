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

    FVector HitLocation; // Out parameter
    if(GetSightRayHitLocation(HitLocation)) // Has "Side-effect" that it is going to line trace
    {
        UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
        // TODO Tell controlled tank to aim at this point
    }

    //Get world location of linetrace through crosshair
   
}

//Returns true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{   
    OutHitLocation = FVector(1.0f);
    return true;
}