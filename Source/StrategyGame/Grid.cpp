// Fill out your copyright notice in the Description page of Project Settings.

#include "Grid.h"
#include "Hex.h"
//#include "HexBase.h"


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

	// Test map.
	hexMap.Reserve(10);
	for (int32 i = 0; i < 10; i++)
	{
		hexMap.Emplace(FHexRow());

		for (int32 j = 0; j < 10; j++)
		{
			FIntVector hexCoords(i, j, 0);
			//FTransform SpawnLocAndRot;
			//SpawnLocAndRot.AddToTranslation(hexToWorld(hexCoords));
			//UWorld* World = GetWorld();
			//AHex* hex = World->SpawnActorDeferred<AHex>(AHex::StaticClass(),SpawnLocAndRot);

			hexMap[i].Row.Emplace();
			//hexMap[i].Row[j]->setHexCoords(temp);
		}
	}
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

FVector AGrid::hexToWorld(const FIntVector& h)
{
	float x = (m0 * h.X + m1 * h.Y) * sizeX;
	float y = (m2 * h.X + m1 * h.Y) * sizeY;
	return FVector(x, y, 0.0f);
}

