// Christopher Kelly
// Check out www.chriskelly48th.ca for contact info

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h"

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
	
	if (!(PlayerTank && ControlledTank)) { return; }
    
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

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		//Subscribe our local method to the tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}