// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "Engine/ObjectLibrary.h"
#include "DedicatedGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DEDICATED_API UDedicatedGameInstance : public UGameInstance
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "ShopItemTable")
		UBlueprintGeneratedClass* GetItemClassFromID(UObjectLibrary* ShopItemLibrary, int ItemID);
	
	
};
