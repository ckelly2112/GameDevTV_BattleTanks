// Christopher Kelly
// Check out www.chriskelly48th.ca for contact info
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	float TakeDamage (float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	// Returns Current Health as a percentage of starting health
	UFUNCTION(BlueprintPure, Category = "Damage")
	float GetHealthPercent() const;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Damage")
	int32 CurrentHealth = StartingHealth;

};
