#include "TradeDemo/Classes/Item/Item.h"

// TODO: Expirement with TDD and learn how Automation Tests work

// Also note that this macro creates the test for us!
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FItemInit_Test, "TradeDemo.ItemTests.Initialization_Test", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FItemInit_Test::RunTest(const FString& Parameters)
{
	AItem* TestItem = NewObject<AItem>();
    
	TestItem->Name = "TestItem";
	TestItem->Weight = 10.0f;
	TestItem->Value = 50.0f;

	// Check if the Name is properly initialized
	TestEqual("Test if Item Name is initialized correctly", TestItem->Name, "TestItem");

	// Check if the Weight is properly initialized
	TestEqual("Test if Item Weight is initialized correctly", TestItem->Weight, 10.0f);

	// Check if the Value is properly initialized
	TestEqual("Test if Item Value is initialized correctly", TestItem->Value, 50.0f);

	return true;
}

// TODO: Test creating various items with different values and weights.
// TODO: Test interaction with items such as picking them up and using them.
// TODO: Test what happens when you try to interact with a non-interactive item.