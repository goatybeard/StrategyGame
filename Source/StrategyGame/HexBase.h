// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "HexBase.generated.h"

/**The base struct to hold Hex coordinates and
 * arithmetic functions.
 * Inheriting from an Unreal class to benefit from garbage
 * collection and better integration with other Unreal classes.
 */

// UCLASS is a Macro function used the Unreal Header Tool (UHT).
// It allows you to change access to class by other parts of the engine
// (Blueprints, Content Browser, etc.) and other metadata.
UCLASS()
class STRATEGYGAME_API UHexBase : public UUserDefinedStruct
{
	// GENERATED_BODY is a macro that takes no arguments and
	// "sets up the class to support the infrastructure
	// required by the engine."
	GENERATED_BODY()

public:
	// Axial storage of cubic coordinates. (q + r + s == 0)

	// UPROPERTY macro allows the UHT to give access to the variable in
	// the editor and Blueprints with keywords. Also enables the reflective
	// debugging and garbage collector system to see it.

	// Q part of hex coordinate.
	UPROPERTY()
	int32 q_;

	// R part of hex coordinate.
	UPROPERTY()
	int32 r_;

public:
	// Default constructor.
	// FYI: The U prefix denotes it is a gameplay object that
	// cannot be directly instanced into the world. They are
	// usually Components attached to Actors.
	UHexBase() : UUserDefinedStruct()
	{
	}

	// Axial constructor.
	UHexBase(int32 q, int32 r)
	{
		q_ = q;
		r_ = r;
	}

	// Cubic constructor (ignore s).
	UHexBase(int32 q, int32 r, int32 s)
	{
		q_ = q;
		r_ = r;
	}

	void SetQ(int32 q)
	{
		q_ = q;
	}

	void SetR(int32 r)
	{
		r_ = r;
	}

	const int32 q() { return q_; }
	const int32 r() { return r_; }
	const int32 s() { return -q_ - r_; }

	const int32 q() const { return q_; }
	const int32 r() const { return r_; }
	const int32 s() const { return -q_ - r_; }
	
	// Check if two HexBase are the same HexBase.
	friend bool operator== (UHexBase& a, UHexBase& b)
	{
		return a.q_ == b.q_ && a.r_ == b.r_;
	}

	// Check if two HexBase are not the same HexBase.
	friend bool operator!= (UHexBase& a, UHexBase& b)
	{
		return !(a == b);
	}

	// Hex coordinate arithmetic.
	friend UHexBase hexAdd(UHexBase& a, UHexBase& b)
	{
		return UHexBase(a.q_ + b.q_, a.r_ + b.q_);
	}

	friend UHexBase hexSubtract(UHexBase& a, UHexBase& b)
	{
		return UHexBase(a.q_ - b.q_, a.r_ - b.q_);
	}

	// Multiply hex coordinates by a scalar.
	friend UHexBase hexMultiply(UHexBase& a, int32 k)
	{
		return UHexBase(a.q_ * k, a.r_ * k);
	}

	// Find the distance between two HexBase (Based on Manhattan distance).
	friend int32 hexDistance(UHexBase& a, UHexBase& b);


};
