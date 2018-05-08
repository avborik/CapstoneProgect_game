// Fill out your copyright notice in the Description page of Project Settings.

#include "DedicatedPlayerState.h"

void ADedicatedPlayerState::SetPlayerName(const FString& S)
{
	SetPlayerNameInternal(S);

	// RepNotify callback won't get called by net code if we are the server
	ENetMode NetMode = GetNetMode();
	if (NetMode == NM_Standalone || NetMode == NM_ListenServer)
	{
		OnRep_PlayerName();
	}

	OldNamePrivate = GetPlayerName();
	PRAGMA_DISABLE_DEPRECATION_WARNINGS;
	OldName = OldNamePrivate;
	PRAGMA_ENABLE_DEPRECATION_WARNINGS;

	ForceNetUpdate();
}

void ADedicatedPlayerState::SetPlayerNetID(int32 newID)
{
	PlayerId = newID;
}

void ADedicatedPlayerState::SetPlayerNetIDFromString(FString newID)
{
	SetPlayerNetID(FCString::Atoi(*newID));
}


