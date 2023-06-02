#include "TradingSystem/TradingSystem.h"

// TradingSystem.cpp

#include "TradeDemo/Classes/TradingSystem/TradingSystem.h"

bool UTradingSystem::BuyItem(AMyPlayer* Player, AItem* Item)
{
	// If the player has enough money and the item is available
	if (Player && Item && Prices.Contains(Item) && Player->Money >= Prices[Item])
	{
		// Deduct the cost from the player's money
		Player->Money -= Prices[Item];

		// Add the item to the player's inventory
		Player->Inventory->AddItem(Item);

		return true;
	}

	// Return false if the item could not be bought
	return false;
}

bool UTradingSystem::SellItem(AMyPlayer* Player, AItem* Item)
{
	// If the player has the item in inventory and the item's price is defined
	if (Player && Item && Prices.Contains(Item) && Player->Inventory->Items.Contains(Item))
	{
		// Increase the player's money by the item's value
		Player->Money += Prices[Item];

		// Remove the item from the player's inventory
		Player->Inventory->RemoveItem(Item);

		return true;
	}

	// Return false if the item could not be sold
	return false;
}
