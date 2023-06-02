#include "TradingSystem/TradingSystem.h"
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FTradingSystemBuySell_Test, "TradeDemo.TradingSystemTests.Buy_Sell_Test", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FTradingSystemBuySell_Test::RunTest(const FString& Parameters)
{
	UTradingSystem* TestTradingSystem = NewObject<UTradingSystem>();
	AMyPlayer* TestPlayer = NewObject<AMyPlayer>();
	AItem* TestItem = NewObject<AItem>();
	TestItem->Value = 100.0f;

	TestTradingSystem->SellItem(TestPlayer, TestItem);
	TestEqual("Test if Player money is increased after selling", TestPlayer->Money, 100.0f);

	TestTradingSystem->BuyItem(TestPlayer, TestItem);
	TestEqual("Test if Player money is decreased after buying", TestPlayer->Money, 0.0f);

	return true;
}

// TODO: Test buying and selling items, especially edge cases such as trying to buy an item without enough money or sell an item not in inventory.
// TODO: Test changes in the prices map, such as adding new items or removing existing ones.
// TODO: Test transactions with non-existent items or non-existent players.
