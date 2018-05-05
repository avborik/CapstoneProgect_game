// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseObjectCPP.h"
#include "UnrealNetwork.h"


// Sets default values
ABaseObjectCPP::ABaseObjectCPP(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bReplicates = true;
	bAlwaysRelevant = true;
	bNetLoadOnClient = true;
	//bOnlyRelevantToOwner = true;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ABaseObjectCPP::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABaseObjectCPP, ObjectID);
	DOREPLIFETIME(ABaseObjectCPP, ObjectName);
	DOREPLIFETIME(ABaseObjectCPP, IsStackable);
	DOREPLIFETIME(ABaseObjectCPP, MaxStackSize);
	DOREPLIFETIME(ABaseObjectCPP, Weight);
	DOREPLIFETIME(ABaseObjectCPP, ImageContainer);


}

// Called when the game starts or when spawned
void ABaseObjectCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseObjectCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

