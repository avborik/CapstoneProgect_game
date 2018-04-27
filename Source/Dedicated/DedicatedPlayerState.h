// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "DedicatedPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class DEDICATED_API ADedicatedPlayerState : public APlayerState
{
	GENERATED_BODY()

	/** Previous player name.  Saved on client-side to detect player name changes. */
	FString OldNamePrivate;
	

	UFUNCTION(BlueprintCallable, Category= "Player")
	void SetPlayerName(const FString& S);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void SetPlayerNetID(int32 newID);

	UFUNCTION(BlueprintCallable, Category = "Player")
	void SetPlayerNetIDFromString(FString newID);
	
};
