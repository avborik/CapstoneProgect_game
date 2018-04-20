// Fill out your copyright notice in the Description page of Project Settings.

#include "DedicatedGameSession.h"
#include "OnlineSession.generated.h"


void ADedicatedGameSession::RegisterServer()
{
	UWorld* World = GetWorld();
	IOnlineSessionPtr SessionInt = Online::GetSessionInterface(World);

	FOnlineSessionSettings Settings;
	Settings.NumPublicConnections = 20;
	Settings.bShouldAdvertise = true;
	Settings.bAllowJoinInProgress = true;
	Settings.bIsLANMatch = true;
	Settings.bUsesPresence = false;
	Settings.bAllowJoinViaPresence = false;

	SessionInt->CreateSession(0, GameSessionName, Settings);
	return;
}




