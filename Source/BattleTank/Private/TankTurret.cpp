// Christopher Kelly
// Check out www.chriskelly48th.ca for contact info

#include "TankTurret.h"

void UTankTurret::Azimuth(float RelativeSpeed)
{
    RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, +1.f);
    auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewRotation = GetRelativeRotation().Yaw + RotationChange;
    SetRelativeRotation(FRotator(0, RawNewRotation, 0), true);
}