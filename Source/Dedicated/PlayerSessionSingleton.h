// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayerSessionVariables.h"
#include "PlayerSessionSingleton.generated.h"

/**
 * 
 */
UCLASS()
class DEDICATED_API UPlayerSessionSingleton : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UPlayerSessionSingleton(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, Category = "Player Session")
		static UPlayerSessionVariables* GetPlayerSessionSingleton(bool& IsValid);
	
	
	
};
