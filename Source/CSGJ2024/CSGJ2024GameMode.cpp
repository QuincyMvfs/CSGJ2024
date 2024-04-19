// Copyright Epic Games, Inc. All Rights Reserved.

#include "CSGJ2024GameMode.h"
#include "CSGJ2024Character.h"
#include "UObject/ConstructorHelpers.h"

ACSGJ2024GameMode::ACSGJ2024GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
