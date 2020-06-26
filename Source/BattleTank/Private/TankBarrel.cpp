// Christopher Kelly
// Check out www.chriskelly48th.ca for contact info

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
    RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, +1.f);
    auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewElevation = GetRelativeRotation().Pitch + ElevationChange;
    auto NewElevation = FMath::Clamp(RawNewElevation, MinElevationInDegrees, MaxElevationInDegrees);
    SetRelativeRotation(FRotator(NewElevation, 0, 0));
}