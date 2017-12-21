// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController1.h"

void ATankPlayerController1::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing %s."), *(ControlledTank->GetName()));

	}
}

void ATankPlayerController1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank *ATankPlayerController1::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController1::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out Perameter
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
			//  TODO Tell Controlled tank to aim towards crosshair.
	}
}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController1::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}