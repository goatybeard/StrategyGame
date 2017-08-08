// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "HexBase.generated.h"

/**The base struct to hold Hex coordinates and
 * arithmetic functions.
 */
UCLASS()
class STRATEGYGAME_API UHexBase : public UUserDefinedStruct
{
	GENERATED_BODY()

private:
	// Axial storage of cubic coordinates. (q + r + s == 0)
	int32 q_;
	int32 r_;

public:
	// Default constructor.
	UHexBase()
	{
		q_ = 0;
		r_ = 0;
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
	
	const int32 q() { return q_; }
	const int32 r() { return r_; }
	const int32 s() { return -q_ - r_; }
	
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
	int32 hexDistance(UHexBase& a, UHexBase& b);


};
