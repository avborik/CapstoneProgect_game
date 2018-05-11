// Fill out your copyright notice in the Description page of Project Settings.

#include "DedicatedGameInstance.h"


UBlueprintGeneratedClass * UDedicatedGameInstance::GetItemClassFromID(UObjectLibrary* ShopItemLibrary, int ItemID)
{

	TArray<UBlueprintGeneratedClass  *> itemList;
	ShopItemLibrary->GetObjects<UBlueprintGeneratedClass>(itemList);

	//Make sure that ConversationID is in the Range of the Array, else return NULL
	if (itemList.Num() > ItemID)
	{
		return itemList[ItemID];
	}
	else
		return nullptr;

}




