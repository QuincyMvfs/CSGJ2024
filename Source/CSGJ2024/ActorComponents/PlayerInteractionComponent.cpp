// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInteractionComponent.h"

#include "PlayerInventoryComponent.h"
#include "CSGJ2024/CustomEnums.h"
#include "CSGJ2024/FInteractableInfo.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values for this component's properties
UPlayerInteractionComponent::UPlayerInteractionComponent()
{

}

// Called when the game starts
void UPlayerInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	m_startMovementSpeed = PlayerMovementComp->MaxWalkSpeed;
}

void UPlayerInteractionComponent::CheckInteractable(FInteractableInfo ResourceInfo)
{
	CurrentInteractableInfo = ResourceInfo;
	
	switch (ResourceInfo.InteractableType)
	{
		case EInteractableTypes::Stone:
			StartPunching(4);
			break;
		case EInteractableTypes::Wood:
			break;
		case EInteractableTypes::Flower:
			break;
		case EInteractableTypes::Mushroom:
			break;
		case EInteractableTypes::Gem:
			break;
		default:
			break;
	}
}

void UPlayerInteractionComponent::StartPunching(float Duration)
{
	CurrentAnimationState = EAnimationStates::Punching;
	GetWorld()->GetTimerManager().SetTimer(
		InteractionTimerHandle, this, &UPlayerInteractionComponent::FinishInteraction, Duration, false);
}

void UPlayerInteractionComponent::GatherResource(float Duration)
{
}

void UPlayerInteractionComponent::PickupLargeObject()
{
}

void UPlayerInteractionComponent::FinishInteraction()
{
	PlayerInventoryComp->IncreaseResource(
		CurrentInteractableInfo.InteractableType, CurrentInteractableInfo.TotalResources);
	CurrentAnimationState = EAnimationStates::Idle;
	PlayerMovementComp->MaxWalkSpeed = m_startMovementSpeed;
}

