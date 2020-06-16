// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("AI Controller Begin Play"));
    if (!GetControlledTank())
    {
        UE_LOG(LogTemp, Error, TEXT("Pawn not possessed"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("%s Posessed by AI"), *GetControlledTank()->GetName());
    }

    if (!GetPlayerTank())
    {
        UE_LOG(LogTemp, Error, TEXT("AI Can't get player controller"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("AI Gets Player Controller: %s"), *GetPlayerTank()->GetName());
    }

}

ATank* ATankAIController::GetControlledTank() const{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const{
    return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    
}