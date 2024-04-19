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

void UPlayerInteractionComponent::CheckInteractable(FInteractableInfo ResourceInfo, AActor* InteractableActor)
{
	CurrentInteractableInfo = ResourceInfo;
	m_interactableActor = InteractableActor;
	
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
			PickupLargeObject(0.5f);
			break;
		default:
			break;
	}
}

void UPlayerInteractionComponent::StartPunching(float Duration)
{
	UE_LOG(LogTemp, Warning, TEXT("PUNCH"));

	CurrentAnimationState = EAnimationStates::Punching;
	GetWorld()->GetTimerManager().SetTimer(
		InteractionTimerHandle, this, &UPlayerInteractionComponent::FinishInteraction, Duration, false);
}

void UPlayerInteractionComponent::GatherResource(float Duration)
{
	UE_LOG(LogTemp, Warning, TEXT("GATHER"));
	
	CurrentAnimationState = EAnimationStates::Grabbing;
	GetWorld()->GetTimerManager().SetTimer(
		InteractionTimerHandle, this, &UPlayerInteractionComponent::FinishInteraction, Duration, false);
}

void UPlayerInteractionComponent::PickupLargeObject(float Duration)
{
	UE_LOG(LogTemp, Warning, TEXT("PICKUP LARGE OBJECT"));
	
	CurrentAnimationState = EAnimationStates::SlowedWalking;
	PlayerMovementComp->MaxWalkSpeed = LargeObjectMovementSpeed;

}

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
	m_interactableActor->Destroy();
	
	CancelInteraction();
}

