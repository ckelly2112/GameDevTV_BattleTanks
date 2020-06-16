// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
  
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

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick( DeltaTime );
}

ATank* ATankAIController::GetControlledTank() const{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const{
    return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    
}