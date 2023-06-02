#include "MyPlayer/MyPlayer.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlayerInit_Test, "TradeDemo.PlayerTests.Initialization_Test", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPlayerInit_Test::RunTest(const FString& Parameters)
{
	AMyPlayer* TestPlayer = NewObject<AMyPlayer>();
    
	TestPlayer->Health = 100.0f;
	TestPlayer->Speed = 50.0f;

	TestEqual("Test if Player Health is initialized correctly", TestPlayer->Health, 100.0f);
	TestEqual("Test if Player Speed is initialized correctly", TestPlayer->Speed, 50.0f);

	return true;
}
