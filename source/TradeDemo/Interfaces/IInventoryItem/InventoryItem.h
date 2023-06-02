#pragma once

#include "InventoryItem.generated.h"

// IInventoryItem: This interface could be used for any object that can be added to the player's inventory,
// such as weapons, ammo, and consumables.

UINTERFACE(MinimalAPI, Blueprintable)
class UInventoryItem : public UInterface
{
	GENERATED_BODY()	
};

class TRADEDEMO_API IInventoryItem
{
	GENERATED_BODY()
public:
	// Add Interface Functions here:
	virtual void AddToInventory() = 0;
	virtual void RemoveFromInventory() = 0;
};