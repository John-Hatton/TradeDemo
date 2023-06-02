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
