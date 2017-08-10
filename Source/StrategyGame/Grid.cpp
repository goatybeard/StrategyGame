// Fill out your copyright notice in the Description page of Project Settings.

#include "Grid.h"
#include "HexBase.h"


// Sets default values for the
// Class Default Object (CDO)
// aka the "Master" copy created at startup.
AGrid::AGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	origin.Set(0.0f, 0.0f, 0.0f);

	sizeX = 1.0f;
	sizeY = 1.0f;
}

// Called when the game starts or when spawned
// Creates a new instance of the object
// based on the CDO.
void AGrid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrid::Tick(float DeltaTime)
{
	// DeltaTime is the time it took to render the last frame.
	Super::Tick(DeltaTime);

}

FVector AGrid::hexToWorld(const UHexBase & h)
{
	float x = (m0 * h.q() + m1 * h.r()) * sizeX;
	float y = (m2 * h.q() + m1 * h.r()) * sizeY;
	return FVector(x, y, 0.0f);
}

