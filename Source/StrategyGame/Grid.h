// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HexBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

/** Grid class to hold the Hex objects and convert
* hex coords to world coords.
* AActor is a UObject that can be placed in the world
* and has a Tick function. ('A' prefix means Actor)
*/

UCLASS()
class STRATEGYGAME_API AGrid : public AActor
{
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
	FVector origin;

	// Variables to scale the grid in the World.
	float sizeX;
	float sizeY;
	
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
	FVector hexToWorld(const UHexBase& h);
	
};
