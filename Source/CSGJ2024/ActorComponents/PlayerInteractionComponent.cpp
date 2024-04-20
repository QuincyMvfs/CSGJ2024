// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInteractionComponent.h"

#include "PlayerInventoryComponent.h"
#include "CSGJ2024/CustomEnums.h"
#include "CSGJ2024/FInteractableInfo.h"
#include "GameFramework/CharacterMovementComponent.h"

UPlayerInteractionComponent::UPlayerInteractionComponent() { }

void UPlayerInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	m_startMovementSpeed = PlayerMovementComp->MaxWalkSpeed;
}

// Gets the correlated task to perform
void UPlayerInteractionComponent::CheckInteractable(FInteractableInfo ResourceInfo, AActor* InteractableActor)
{
	CurrentInteractableInfo = ResourceInfo;
	m_interactableActor = InteractableActor;
	InteractionStartedEvent.Broadcast(ResourceInfo);
	
	switch (ResourceInfo.InteractableType)
	{
		case EInteractableTypes::Stone:
			StartPunching(StonePunchingDuration);
			break;
		case EInteractableTypes::Wood:
			StartPunching(WoodPunchingDuration);
			break;
		case EInteractableTypes::Flower:
			GatherResource(GatherFlowersDuration);
			break;
		case EInteractableTypes::Mushroom:
			GatherResource(GatherMushroomsDuration);
			break;
		case EInteractableTypes::Gem:
			TryPickupLargeObject(GatherGemDuration);
			break;
		default:
			break;
	}
}

// PUNCHING
void UPlayerInteractionComponent::StartPunching(float Duration)
{
	UE_LOG(LogTemp, Warning, TEXT("PUNCH"));

	CurrentAnimationState = EAnimationStates::Punching;
	GetWorld()->GetTimerManager().SetTimer(
		InteractionTimerHandle, this, &UPlayerInteractionComponent::FinishInteraction, Duration, false);
}

// GATHERING
void UPlayerInteractionComponent::GatherResource(float Duration)
{
	UE_LOG(LogTemp, Warning, TEXT("GATHER"));
	
	CurrentAnimationState = EAnimationStates::Grabbing;
	GetWorld()->GetTimerManager().SetTimer(
		InteractionTimerHandle, this, &UPlayerInteractionComponent::FinishInteraction, Duration, false);
}

//* GEM
void UPlayerInteractionComponent::TryPickupLargeObject(float Duration)
{
	UE_LOG(LogTemp, Warning, TEXT("TRY PICKUP LARGE OBJECT"));
	
	CurrentAnimationState = EAnimationStates::Grabbing;
	GetWorld()->GetTimerManager().SetTimer(
		InteractionTimerHandle, this, &UPlayerInteractionComponent::PickupLargeObject, Duration, false);
}

void UPlayerInteractionComponent::PickupLargeObject()
{
	UE_LOG(LogTemp, Warning, TEXT("PICKUP LARGE OBJECT"));
	
	CurrentAnimationState = EAnimationStates::SlowedWalking;
	PlayerMovementComp->MaxWalkSpeed = LargeObjectMovementSpeed;
	PlayerInventoryComp->IncreaseResource(
		CurrentInteractableInfo.InteractableType, CurrentInteractableInfo.TotalResources);

	InteractionCompleteEvent.Broadcast(m_interactableActor);
}
//*

//* STOPPING FUNCTIONS
void UPlayerInteractionComponent::CancelInteraction()
{
	UE_LOG(LogTemp, Warning, TEXT("CANCEL"));

	GetWorld()->GetTimerManager().ClearTimer(InteractionTimerHandle);
	CurrentAnimationState = EAnimationStates::Idle;
	PlayerMovementComp->MaxWalkSpeed = m_startMovementSpeed;
}

void UPlayerInteractionComponent::FinishInteraction()
{
	UE_LOG(LogTemp, Warning, TEXT("DO SOMETHING"));
	
	PlayerInventoryComp->IncreaseResource(
		CurrentInteractableInfo.InteractableType, CurrentInteractableInfo.TotalResources);
	InteractionCompleteEvent.Broadcast(m_interactableActor);
	
	CancelInteraction();
}
//*

