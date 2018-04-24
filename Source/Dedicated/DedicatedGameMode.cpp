// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "DedicatedGameMode.h"
#include "DedicatedCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameNetworkManager.h"
#include "Matinee/MatineeActor.h"
#include "Engine/LevelScriptActor.h"
#include "Engine/World.h"
#include "Misc/CommandLine.h"
#include "UObject/Package.h"
#include "Misc/PackageName.h"
#include "Net/OnlineEngineInterface.h"
#include "GameFramework/GameStateBase.h"
#include "PhysicsEngine/BodyInstance.h"
#include "GameFramework/DefaultPawn.h"
#include "GameFramework/SpectatorPawn.h"
#include "GameFramework/HUD.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/GameSession.h"
#include "GameFramework/PlayerStart.h"
#include "GameFramework/WorldSettings.h"
#include "Engine/NetConnection.h"
#include "Engine/ChildConnection.h"
#include "Engine/PlayerStartPIE.h"
#include "Engine/LocalPlayer.h"
#include "Engine/Engine.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreaming.h"



ADedicatedGameMode::ADedicatedGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Character/DedicatedCharacterBP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

FString ADedicatedGameMode::InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal)
{
	/*PRAGMA_DISABLE_DEPRECATION_WARNINGS
		// Try calling deprecated version first
		FString DeprecatedError = InitNewPlayer(NewPlayerController, UniqueId.GetUniqueNetId(), Options, Portal);
	if (DeprecatedError != TEXT("DEPRECATED"))
	{
		// This means it was implemented in subclass
		return DeprecatedError;
	}
	PRAGMA_ENABLE_DEPRECATION_WARNINGS*/

		check(NewPlayerController);

	FString ErrorMessage;

	FString ParamOne = UGameplayStatics::ParseOption(Options, TEXT("Param1"));
	FString ParamTwo = UGameplayStatics::ParseOption(Options, TEXT("Param2"));

	// Register the player with the session
	GameSession->RegisterPlayer(NewPlayerController, UniqueId.GetUniqueNetId(), UGameplayStatics::HasOption(Options, TEXT("bIsFromInvite")));
	
	// Find a starting spot
	AActor* const StartSpot = FindPlayerStart(NewPlayerController, Portal);
	if (StartSpot != nullptr)
	{
		// Set the player controller / camera in this new location
		FRotator InitialControllerRot = StartSpot->GetActorRotation();
		InitialControllerRot.Roll = 0.f;
		NewPlayerController->SetInitialLocationAndRotation(StartSpot->GetActorLocation(), InitialControllerRot);
		NewPlayerController->StartSpot = StartSpot;
	}
	else
	{
		ErrorMessage = FString::Printf(TEXT("Failed to find PlayerStart"));
	}

	// Set up spectating
	bool bSpectator = FCString::Stricmp(*UGameplayStatics::ParseOption(Options, TEXT("SpectatorOnly")), TEXT("1")) == 0;
	if (bSpectator || MustSpectate(NewPlayerController))
	{
		NewPlayerController->StartSpectatingOnly();
	}

	// Init player's name
	FString InName = UGameplayStatics::ParseOption(Options, TEXT("Name")).Left(20);
	if (InName.IsEmpty())
	{
		InName = FString::Printf(TEXT("%s%i"), *DefaultPlayerName.ToString(), NewPlayerController->PlayerState->PlayerId);
	}

	ChangeName(NewPlayerController, InName, false);

	return ErrorMessage;
}

/*void ADedicatedGameMode::ChangeName(AController* Other, const FString& S, bool bNameChange)
{
	if (Other && !S.IsEmpty())
	{
		Other->PlayerState->SetPlayerName(S);

		K2_OnChangeName(Other, S, bNameChange);
	}
}*/
