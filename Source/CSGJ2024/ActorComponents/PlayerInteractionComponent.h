// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CSGJ2024/CustomEnums.h"
#include "CSGJ2024/FInteractableInfo.h"
#include "PlayerInteractionComponent.generated.h"


struct FInteractableInfo;
class UCharacterMovementComponent;
class UPlayerInventoryComponent;
enum class EAnimationStates : uint8;
enum class EInteractableTypes : uint8;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CSGJ2024_API UPlayerInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerInteractionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void CheckInteractable(FInteractableInfo ResourceInfo, AActor* InteractableActor);

	UFUNCTION(BlueprintCallable)
	void StartPunching(float Duration);

	UFUNCTION(BlueprintCallable)
	void GatherResource(float Duration);

	UFUNCTION(BlueprintCallable)
	void PickupLargeObject(float Duration);

public:
	UPlayerInventoryComponent* PlayerInventoryComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Interaction Component")
	float StonePunchingDuration = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Interaction Component")
	float WoodPunchingDuration = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Interaction Component")
	float GatherFlowersDuration = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Interaction Component")
	float GatherMushroomsDuration = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Interaction Component")
	float LargeObjectMovementSpeed = 200.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	EAnimationStates CurrentAnimationState = EAnimationStates::Idle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCharacterMovementComponent* PlayerMovementComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPlayerInventoryComponent* PlayerInventoryComp;

	UFUNCTION(BlueprintCallable)
	void CancelInteraction();
	
private:
	void FinishInteraction();
	AActor* m_interactableActor;
	float m_startMovementSpeed;
	FTimerHandle InteractionTimerHandle;
	FInteractableInfo CurrentInteractableInfo;
};
