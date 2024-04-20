// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerInventoryComponent.generated.h"


enum class EInteractableTypes : uint8;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CSGJ2024_API UPlayerInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	//* TOTALS
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Totals)
	int M_TotalStone = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Totals)
	int M_TotalWood = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Totals)
	int M_TotalMushrooms = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Totals)
	int M_TotalFlowers = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Totals)
	int M_TotalGems = 0;
	//*
	
	//* MAX VALUES
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MaxValues)
	int M_MaxStone = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MaxValues)
	int M_MaxWood = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MaxValues)
	int M_MaxMushrooms = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MaxValues)
	int M_MaxFlowers = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MaxValues)
	int M_MaxGems = 5;
	//*

public:
	UFUNCTION(BlueprintCallable)
	void IncreaseResource(EInteractableTypes ResourceType, int Amount);

	UFUNCTION(BlueprintCallable)
	void DecreaseResource(EInteractableTypes ResourceType, int Amount);

	UFUNCTION(BlueprintPure)
	int GetCurrentResourceAmount(EInteractableTypes ResourceType);
	
	UFUNCTION(BlueprintPure)
	int GetMaxResourceAmount(EInteractableTypes ResourceType);
	
};
