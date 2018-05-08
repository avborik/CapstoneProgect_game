// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnrealNetwork.h"
#include "BaseObjectCPP.generated.h"

USTRUCT(BlueprintType)
struct FImageContainer
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UTexture2D * Image;

	FImageContainer()
	{
		Image = nullptr;
	}

};

UCLASS(BlueprintType)
class DEDICATED_API ABaseObjectCPP : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseObjectCPP(const FObjectInitializer& ObjectInitializer);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Replicated)
		int ObjectID;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Replicated)
		FString ObjectName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Replicated)
		bool IsStackable;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Replicated)
		int MaxStackSize;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Replicated)
		float Weight;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Replicated)
		FImageContainer ImageContainer;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
