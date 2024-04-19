// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInventoryComponent.h"

#include "CSGJ2024/CustomEnums.h"

// Sets default values for this component's properties
UPlayerInventoryComponent::UPlayerInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UPlayerInventoryComponent::IncreaseResource(EInteractableTypes ResourceType, int Amount)
{
	switch (ResourceType)
	{
		case EInteractableTypes::Stone:
			M_TotalStone += Amount;
			M_TotalStone = FMath::Clamp(M_TotalStone, 0, M_MaxStone);
			break;
		
		case EInteractableTypes::Wood:
			M_TotalWood += Amount;
			M_TotalWood = FMath::Clamp(M_TotalWood, 0, M_MaxWood);
			break;
		
		case EInteractableTypes::Flower:
			M_TotalFlowers += Amount;
			M_TotalFlowers = FMath::Clamp(M_TotalFlowers, 0, M_MaxFlowers);
			break;
		
		case EInteractableTypes::Mushroom:
			M_TotalMushrooms += Amount;
			M_TotalMushrooms = FMath::Clamp(M_TotalMushrooms, 0, M_MaxMushrooms);
			break;
		
		case EInteractableTypes::Gem:
			M_TotalGems += Amount;
			M_TotalGems = FMath::Clamp(M_TotalGems, 0, M_MaxGems);
			break;
		
		default:
			M_TotalStone += Amount;
			M_TotalStone = FMath::Clamp(M_TotalStone, 0, M_MaxStone);
			break;
	}
}

void UPlayerInventoryComponent::DecreaseResource(EInteractableTypes ResourceType, int Amount)
{
	switch (ResourceType)
	{
		case EInteractableTypes::Stone:
			M_TotalStone -= Amount;
			M_TotalStone = FMath::Clamp(M_TotalStone, 0, M_MaxStone);
			break;
			
		case EInteractableTypes::Wood:
			M_TotalWood -= Amount;
			M_TotalWood = FMath::Clamp(M_TotalWood, 0, M_MaxWood);
			break;
			
		case EInteractableTypes::Flower:
			M_TotalFlowers -= Amount;
			M_TotalFlowers = FMath::Clamp(M_TotalFlowers, 0, M_MaxFlowers);
			break;
			
		case EInteractableTypes::Mushroom:
			M_TotalMushrooms -= Amount;
			M_TotalMushrooms = FMath::Clamp(M_TotalMushrooms, 0, M_MaxMushrooms);
			break;
			
		case EInteractableTypes::Gem:
			M_TotalGems -= Amount;
			M_TotalGems = FMath::Clamp(M_TotalGems, 0, M_MaxGems);
			break;
			
		default:
			M_TotalStone -= Amount;
			M_TotalStone = FMath::Clamp(M_TotalStone, 0, M_MaxStone);
			break;
	}
}

int UPlayerInventoryComponent::GetCurrentResourceAmount(EInteractableTypes ResourceType)
{
	switch (ResourceType)
	{
		case EInteractableTypes::Stone:
			return M_TotalStone;
			
		case EInteractableTypes::Wood:
			return M_TotalWood;
			
		case EInteractableTypes::Flower:
			return M_TotalFlowers;
		
		case EInteractableTypes::Mushroom:
			return M_TotalMushrooms;
		
		case EInteractableTypes::Gem:
			return M_TotalGems;
		
		default:
			return M_TotalStone;
	}
}

int UPlayerInventoryComponent::GetMaxResourceAmount(EInteractableTypes ResourceType)
{
	switch (ResourceType)
	{
		case EInteractableTypes::Stone:
			return M_MaxStone;
				
		case EInteractableTypes::Wood:
			return M_MaxWood;
				
		case EInteractableTypes::Flower:
			return M_MaxFlowers;
			
		case EInteractableTypes::Mushroom:
			return M_MaxMushrooms;
			
		case EInteractableTypes::Gem:
			return M_MaxGems;
			
		default:
			return M_MaxStone;
	}
}

