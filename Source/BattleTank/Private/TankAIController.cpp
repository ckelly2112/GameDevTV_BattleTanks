// Christopher Kelly
// Check out www.chriskelly48th.ca for contact info

#include "TankAIController.h"
#include "TankAimingComponent.h"

// Depends on movement component via pathfinding

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
 
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick( DeltaTime );
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();
	
	if (!ensure(PlayerTank && ControlledTank)) { return; }
    
		// Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);

		auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
        AimingComponent->AimAt(PlayerTank->GetActorLocation());

		// TODO Turn this on when bullets are less annoying...
		if (AimingComponent->GetFiringStatus() == EFiringStatus::Locked)
		{
			
			AimingComponent->Fire();

		}

    
}