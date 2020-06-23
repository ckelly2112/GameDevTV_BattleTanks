// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
 
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick( DeltaTime );
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	
    if(PlayerTank)
    {
		// Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);

        ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// TODO Turn this on when bullets are less annoying
		//ControlledTank->Fire();
    }
}