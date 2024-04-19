// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class CSGJ2024_API CustomEnums
{
public:
	CustomEnums();
	~CustomEnums();
};

UENUM(BlueprintType)
enum class EInteractableTypes : uint8
{
	Stone,
	Wood,
	Mushroom,
	Flower,
	Gem
};

UENUM(BlueprintType)
enum class EAnimationStates : uint8
{
	Idle,
	Walking,
	SlowedWalking,
	Punching,
	Grabbing
};
