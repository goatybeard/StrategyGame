// Fill out your copyright notice in the Description page of Project Settings.

#include "Hex.h"
//#include "HexBase.h"


// Sets default values for the
// Class Default Object (CDO)
// aka the "Master" copy created at startup.
AHex::AHex()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Populating the directions TArray.
	// (TArray apparently doesn't accept initializer lists.)
	// array.Reserve( int i ) allocates memory for at least i elements to prevent dynamically allocating more as you add elements.
	// array.Add() copies or moves an existing instance of the element type.
	// array.Emplace() constructs a new instance of the element type.
	directions.Reserve(6);
	directions.Emplace(FIntVector( 1,  0, -1));
	directions.Emplace(FIntVector( 1, -1,  0));
	directions.Emplace(FIntVector( 0, -1,  1));
	directions.Emplace(FIntVector(-1,  0,  1));
	directions.Emplace(FIntVector(-1,  1,  0));
	directions.Emplace(FIntVector( 0,  1, -1));

	hexMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HexMesh"));
	

}

// Called when the game starts or when spawned
// Creates a new instance of the object
// based on the CDO.
void AHex::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHex::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Manhattan distance from 0, 0, 0 to hex.
int32 AHex::HexLength(FIntVector hex)
{
	return int32((abs(hex.X) + abs(hex.Y) + abs(hex.Z)) / 2);
}

// Manhattan distance from hex a to hex b.
int32 AHex::HexDistance(FIntVector & a, FIntVector & b)
{
	return HexLength(a - b);
}

