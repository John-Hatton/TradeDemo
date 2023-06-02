// ITradeableWeaponTest.cpp

#include "TradeDemo/Interfaces/ITradeable/Tradeable.h"
#include "TradeDemo/Classes/Weapon/Weapon.h"
#include "Tests/AutomationEditorCommon.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FITradeableWeaponTest, "TradeDemo.InterfaceTests.ITradeableWeapon", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FITradeableWeaponTest::RunTest(const FString& Parameters)
{
	AWeapon* TestWeapon = NewObject<AWeapon>();
    
	TestWeapon->Value = 100.0f;

	// Check if the weapon object implements the ITradeable interface
	TestTrue("Weapon implements the ITradeable interface", TestWeapon->GetClass()->ImplementsInterface(UTradeable::StaticClass()));

	// Check if the weapon's value is correctly assigned
	TestEqual("Weapon value is correct", TestWeapon->Value, 100.0f);

	// Add any other tests you might think of

	return true;
}


// TODO: Test that all classes implementing an interface correctly perform its required actions.
// TODO: Test how the system handles objects that are supposed to implement an interface but do not.