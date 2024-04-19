// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FInteractableInfo.generated.h"

enum class EInteractableTypes : uint8;

USTRUCT(BlueprintType)
struct FInteractableInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EInteractableTypes InteractableType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TotalResources = 1;
};
