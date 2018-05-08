// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseInventoryCPP.h"


// Sets default values
ABaseInventoryCPP::ABaseInventoryCPP(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bReplicates = true;
	bOnlyRelevantToOwner = true;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseInventoryCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseInventoryCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

