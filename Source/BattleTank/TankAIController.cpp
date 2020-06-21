// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
  
    if (!GetControlledTank())
    {
        UE_LOG(LogTemp, Error, TEXT("Pawn not possessed"));
    }
    if (!GetPlayerTank())
    {
        UE_LOG(LogTemp, Error, TEXT("AI Can't get player controller"));
    }
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick( DeltaTime );
    if(GetPlayerTank())
    {
        GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
    }
}

ATank* ATankAIController::GetControlledTank() const{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const{
    return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    
}