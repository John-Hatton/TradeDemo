#include "Inventory/Inventory.h"

void UInventory::AddItem(AItem* Item)
{
	if (Item)
	{
		Items.Add(Item);
		Weight += Item->Weight;
	}
}

void UInventory::RemoveItem(AItem* Item)
{
	if (Item && Items.Contains(Item))
	{
		Items.Remove(Item);
		Weight -= Item->Weight;
	}
}
