#include "Weapon/Weapon.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FWeaponInit_Test, "TradeDemo.WeaponTests.Initialization_Test", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FWeaponInit_Test::RunTest(const FString& Parameters)
{
	AWeapon* TestWeapon = NewObject<AWeapon>();
    
	TestWeapon->Damage = 50.0f;
	TestWeapon->Range = 100.0f;

	TestEqual("Test if Weapon Damage is initialized correctly", TestWeapon->Damage, 50.0f);
	TestEqual("Test if Weapon Range is initialized correctly", TestWeapon->Range, 100.0f);

	return true;
}
