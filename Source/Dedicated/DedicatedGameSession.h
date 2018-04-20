// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "OnlineSubsystemUtils.h"
#include "DedicatedGameSession.generated.h"
/**
 * 
 */
UCLASS()
class DEDICATED_API ADedicatedGameSession : public AGameSession
{
	GENERATED_BODY()

	void RegisterServer();
	//void CreateGameSession();
	
	
	
};
