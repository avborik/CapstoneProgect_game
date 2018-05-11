// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
//#include "GameFramework/Actor.h"
//#include "UnrealNetwork.h"
#include "BaseInventoryCPP.generated.h"

USTRUCT(BlueprintType)
struct FInventoryStruct 
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite)
	TSubclassOf<class ABaseObjectCPP> ItemType;
	
	UPROPERTY(BlueprintReadWrite)
	int StackCount;

	FInventoryStruct()
	{
		ItemType = nullptr;
		StackCount = 0;
	}

};

UCLASS(BlueprintType)
class DEDICATED_API ABaseInventoryCPP : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	ABaseInventoryCPP(const FObjectInitializer& ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
