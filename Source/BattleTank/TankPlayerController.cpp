// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

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
    if(!GetControlledTank()) return;

    //Get world location in linetrace through crosshair
   
}