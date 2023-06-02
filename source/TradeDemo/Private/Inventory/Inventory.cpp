#include "Inventory/Inventory.h"


void UInventory::AddItem(AItem* Item)
{
	if ((Weight + Item->Weight) <= MaxWeight)
	{
		Items.Add(Item);
		Weight += Item->Weight;
	}
}

void UInventory::RemoveItem(AItem* Item)
{
	if (Items.Contains(Item))
	{
		Items.Remove(Item);
		Weight -= Item->Weight;
	}
}
