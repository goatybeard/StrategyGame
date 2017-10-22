// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "HexBase.h"
#include "Hex.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

/** Grid class to hold the Hex objects and convert
* hex coords to world coords.
* AActor is a UObject that can be placed in the world
* and has a Tick function. ('A' prefix means Actor)
*/

// Struct holding AHex. Part of the map array.
// Required to make a multi-dimensional array.
USTRUCT()
struct FHexRow
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(VisibleAnywhere)
	TArray<AHex*> Row;
};

// UCLASS is a Macro function used by the Unreal Header Tool (UHT).
// It allows you to change access to class by other parts of the engine
// (Blueprints, Content Browser, etc.) and other metadata.
UCLASS()
class STRATEGYGAME_API AGrid : public AActor
{
	// GENERATED_BODY is a UHT macro that takes no arguments and
	// "sets up the class to support the infrastructure
	// required by the engine."
	GENERATED_BODY()

private:
	// Matrix for converting hex to world.
	// (I haven't figured out TArray yet)
	const float m0 = 3.0f / 2.0f;
	const float m1 = 0.0f;
	const float m2 = sqrt(3.0f) / 2.0f;
	const float m3 = sqrt(3.0f);

	// Inverse of Matrix for world->hex.
	// I'm not sure if this is needed yet
	// if I make Hex an Actor with collision.
	const float i0 = 2.0f / 3.0f;
	const float i1 = 0.0f;
	const float i2 = -1.0f / 3.0f;
	const float i3 = sqrt(3.0f) / 3.0f;

	// Float vector defining where the grid will be centered.
	// UPROPERTY macro allows the UHT to give access to the variable in
	// the editor and Blueprints with keywords. Also enables the reflective
	// debugging and garbage collector system to see it.
	// EditAnywhere allows it to be edited in the Editor and BPs.
	UPROPERTY(EditAnywhere)
	FVector origin;

	// Variables to scale the grid in the World.
	UPROPERTY(EditAnywhere)
	float sizeX;

	UPROPERTY(EditAnywhere)
	float sizeY;

	// TArray of FHexRow to hold the map.
	// Map[i].Row[j]	i == column  j == row
	UPROPERTY(VisibleAnywhere)
	TArray<FHexRow> hexMap;

	// The world that the map will be spawned in.
	//UWorld* World = GetWorld();
	
public:	
	// Sets default values for this actor's properties
	AGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Convert Hex coord to World.
	FVector hexToWorld(const FIntVector& h);
	
};
