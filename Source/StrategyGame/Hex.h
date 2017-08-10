// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "HexBase.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hex.generated.h"

/** Hex Actor to place in the World.
* Contains a UHexBase to store coordinates
* and to be passed to other functions.
* Hex and/or its components will probably do most of the game logic.
*/

UCLASS()
class STRATEGYGAME_API AHex : public AActor
{
	GENERATED_BODY()

private:
	// UHexBase with coordinates.
	//////UHexBase base;
	// Do I need to SetupAttachment to add UHexBase on creation?
	// I don't think I can pass a parameter to an Actor constructor.
	// If so, I need to do this in Grid while building the map.

	// 3d model and other components will go here.
	
public:	
	// Sets default values for this actor's properties
	AHex();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Get function for base.
	//////const UHexBase GetBase() { return base; }
	
};
