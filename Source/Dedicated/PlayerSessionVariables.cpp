// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerSessionVariables.h"

UPlayerSessionVariables::UPlayerSessionVariables(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	guid = "";
}

void UPlayerSessionVariables::SetGUID(FString newGUID)
{
	guid = newGUID;
}

FString UPlayerSessionVariables::GetGUID()
{
	return guid;
}


