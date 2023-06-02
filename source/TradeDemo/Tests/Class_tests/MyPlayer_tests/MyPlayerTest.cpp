#include "Editor.h"
#include "Engine/DamageEvents.h"
#include "TradeDemo/Classes/MyPlayer/MyPlayer.h"
#include "TradeDemo/Interfaces/IInteractable/Interactable.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FPlayerTakeDamage_Test, "TradeDemo.PlayerTests.TakeDamage_Test", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FPlayerTakeDamage_Test::RunTest(const FString& Parameters)
{
	UWorld* World = GWorld;
	FActorSpawnParameters SpawnParams;
    
	AMyPlayer* TestPlayer = World->SpawnActor<AMyPlayer>(AMyPlayer::StaticClass(), SpawnParams);
	TestPlayer->SetCanBeDamaged(true); // Ensure the player can be damaged
	float DamageAmount;

	// Create mock objects for the additional parameters.

	// Mock Damage Event
	FPointDamageEvent MockDamageEvent;
	MockDamageEvent.Damage = 20.0f;
	DamageAmount = MockDamageEvent.Damage;
	MockDamageEvent.ShotDirection = FVector(1.f, 0.f, 0.f);
	MockDamageEvent.HitInfo = FHitResult();

	// Mock PlayerController
	APlayerController* EventInstigator = World->SpawnActor<APlayerController>(APlayerController::StaticClass(), SpawnParams);
	EventInstigator->SetPawn(TestPlayer); // The controller should control the player

	// Mock Pawn
	APawn* DamageCauser = World->SpawnActor<APawn>(APawn::StaticClass(), SpawnParams);

	// Call TakeDamage with the additional parameters;
	TestPlayer->TakeDamage(DamageAmount, MockDamageEvent, EventInstigator, DamageCauser);

	// Expect the player's health to be reduced by the actual damage amount
	return TestEqual("Test if Player health decreases correctly", TestPlayer->GetCurrentHealth(), 80.0f);
}



