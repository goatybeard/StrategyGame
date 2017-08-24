// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "HexBase.h"
#include "IntVector.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hex.generated.h"

/** Hex Actor to place in the World.
* Contains an FIntVector to store coordinates
* and to be passed to other functions.
* Hex and/or its components will probably do most of the game logic.
*/

// UCLASS is a Macro function used by the Unreal Header Tool (UHT).
// It allows you to change access to class by other parts of the engine
// (Blueprints, Content Browser, etc.) and other metadata.
UCLASS()
class STRATEGYGAME_API AHex : public AActor
{
	// GENERATED_BODY is a UHT macro that takes no arguments and
	// "sets up the class to support the infrastructure
	// required by the engine."
	GENERATED_BODY()

private:

	// FIntVector used to store the cubic coordinates of the Hex.
	// UPROPERTY macro allows the UHT to give access to the variable in
	// the editor and Blueprints with keywords. Also enables the reflective
	// debugging and garbage collector system to see it.
	// VisibleAnywhere allows it to be seen in the Editor and BPs but cannot be edited.
	UPROPERTY(VisibleAnywhere)
	FIntVector HexCoords;

	// 3d model and other components will go here.
	
public:	
	// Sets default values for this actor's properties
	AHex();

	// TArray of FIntVextors used with vector math to find neighboring
	// hexes, movement, etc.
	UPROPERTY(VisibleAnywhere)
	TArray<FIntVector> directions;	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Getter for HexCoords.
	const FIntVector& getHexCoords()
	{
		return HexCoords;
	}
	
	// Setter for HexCoords. Only call once on creation!
	void setHexCoords(FIntVector hex)
	{
		HexCoords = hex;
	}

	// Set of functions to find the distance between hexes
	// based of Manhattan distance.
	int32 HexLength(FIntVector hex);

	int32 HexDistance(FIntVector& a, FIntVector& b);
};
