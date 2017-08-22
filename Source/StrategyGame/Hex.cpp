// Fill out your copyright notice in the Description page of Project Settings.

#include "Hex.h"
#include "HexBase.h"


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
	/*directions.Emplace(UHexBase( 1,  0));
	directions.Emplace(UHexBase( 1, -1));
	directions.Emplace(UHexBase( 0, -1));
	directions.Emplace(UHexBase(-1,  0));
	directions.Emplace(UHexBase(-1,  1));
	directions.Emplace(UHexBase( 0,  1));
	*/

	//directions.Emplace(UHexBase());

	

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

