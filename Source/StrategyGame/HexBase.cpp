// Fill out your copyright notice in the Description page of Project Settings.

#include "HexBase.h"

// Find the distance between two HexBase (Based on Manhattan distance).
int32 UHexBase::hexDistance(UHexBase & a, UHexBase & b)
{
	return int32(abs(a.q_ - b.q_) + abs(a.r_ - b.r_) + abs(a.s() - b.s()));
}
