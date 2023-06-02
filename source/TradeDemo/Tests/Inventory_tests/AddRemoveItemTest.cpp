#include "Inventory/Inventory.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FInventoryAddRemove_Test, "TradeDemo.InventoryTests.Add_Remove_Test", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FInventoryAddRemove_Test::RunTest(const FString& Parameters)
{
	UInventory* TestInventory = NewObject<UInventory>();
	AItem* TestItem = NewObject<AItem>();
	TestItem->Weight = 10.0f;
    
	TestInventory->AddItem(TestItem);
	TestTrue("Test if Item is added to Inventory", TestInventory->Items.Contains(TestItem));
	TestEqual("Test if Inventory weight is updated", TestInventory->Weight, 10.0f);

	TestInventory->RemoveItem(TestItem);
	TestFalse("Test if Item is removed from Inventory", TestInventory->Items.Contains(TestItem));
	TestEqual("Test if Inventory weight is updated", TestInventory->Weight, 0.0f);

	return true;
}
