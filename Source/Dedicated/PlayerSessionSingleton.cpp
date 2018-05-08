// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerSessionSingleton.h"
#include "Dedicated.h"

#include "Engine.h"


UPlayerSessionSingleton::UPlayerSessionSingleton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

UPlayerSessionVariables* UPlayerSessionSingleton::GetPlayerSessionSingleton(bool& IsValid)
{
	IsValid = false;
	UPlayerSessionVariables* DataInstance = Cast<UPlayerSessionVariables>(GEngine->GameSingleton);

	if (!DataInstance) return NULL;
	if (!DataInstance->IsValidLowLevel()) return NULL;

	IsValid = true;
	return DataInstance;
}


