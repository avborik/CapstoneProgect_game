// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerSessionVariables.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class UPlayerSessionVariables : public UObject
{
	GENERATED_BODY()
	
public:
	UPlayerSessionVariables(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Session")
		FString guid;

	UFUNCTION(BlueprintCallable, Category = "Player Session")
	void SetGUID(FString newGUID);

	UFUNCTION(BlueprintCallable, Category = "Player Session")
	FString GetGUID();

};
