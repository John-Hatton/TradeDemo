#include "Animal/Animal.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAnimalInit_Test, "TradeDemo.AnimalTests.Initialization_Test", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAnimalInit_Test::RunTest(const FString& Parameters)
{
	AAnimal* TestAnimal = NewObject<AAnimal>();
    
	TestAnimal->Health = 100.0f;
	TestAnimal->Speed = 50.0f;

	TestEqual("Test if Animal Health is initialized correctly", TestAnimal->Health, 100.0f);
	TestEqual("Test if Animal Speed is initialized correctly", TestAnimal->Speed, 50.0f);

	return true;
}
