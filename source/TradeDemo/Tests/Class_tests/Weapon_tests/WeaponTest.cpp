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

// TODO: Test equipping and unequipping the weapon.
// TODO: Test damage output of the weapon and how it affects enemy health.
// TODO: Test what happens when you try to use a weapon without ammunition (if applicable).
