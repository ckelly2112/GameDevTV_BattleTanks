// Christopher Kelly
// Check out www.chriskelly48th.ca for contact info
#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
		void BeginPlay() override;
		void Tick(float DeltaTime) override;

protected:

		UPROPERTY(EditDefaultsOnly, Category = Setup)
		float AcceptanceRadius = 3000.f;

private:

};
