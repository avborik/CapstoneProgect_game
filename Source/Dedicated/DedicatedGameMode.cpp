// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "DedicatedGameMode.h"
#include "DedicatedCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADedicatedGameMode::ADedicatedGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Character/DedicatedCharacterBP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
