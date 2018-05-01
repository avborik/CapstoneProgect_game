// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryCPP.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class DEDICATED_API UInventoryCPP : public UObject
{
	GENERATED_BODY()

public:

	UInventoryCPP();

	//bool IsNameStableForNetworking() const override;

	bool IsSupportedForNetworking() const override
	{
		return true;
	}
	
	
};
