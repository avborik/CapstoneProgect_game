// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DedicatedGameMode.generated.h"

UCLASS(minimalapi)
class ADedicatedGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADedicatedGameMode();
	FString InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal);

	//UFUNCTION(BlueprintNativeEvent, Category = "Test")
	//	void ChangeName(AController* Other, const FString& S, bool bNameChange);

};



