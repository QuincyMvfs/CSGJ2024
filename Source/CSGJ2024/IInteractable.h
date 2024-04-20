// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IInteractable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIInteractable : public UInterface
{
	GENERATED_BODY()

};

class CSGJ2024_API IIInteractable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interactable")
	void Interact();

	UFUNCTION()
	virtual void Interact_Implementation() = 0;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interactable")
	void UnInteract();

	UFUNCTION()
	virtual void UnInteract_Implementation() = 0;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interactable")
	void InteractionComplete();

	UFUNCTION()
	virtual void InteractionComplete_Implementation() = 0;
};
