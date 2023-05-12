// TODO: Expirement with TDD and learn how Automation Tests work

// Also note that this macro creates the test for us!
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FItemInit_Test, "TradeDemo.ItemTests.Initialization_Test", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
bool FItemInit_Test::RunTest(const FString& Parameters)
{
	// Make the test pass by returning true, or fail by returning false.
	return true; 
}