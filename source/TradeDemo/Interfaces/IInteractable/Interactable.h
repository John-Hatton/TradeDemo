#pragma once

#include "Interactable.generated.h"

// This interface could be used for any object that can be interacted with in the game,
// such as items, NPCs, and other players.

UINTERFACE(MinimalAPI, Blueprintable)
class UInteractable : public UInterface
{
	GENERATED_BODY()	
};

class TRADEDEMO_API IInteractable
{
	GENERATED_BODY()
public:
	// Add Interface Functions here:
	virtual void Interact() = 0;

	// Optional function to execute the Interact function on an actor

	static void Execute_Interact(AActor* Actor)
	{
		if (!Actor)
		{
			UE_LOG(LogTemp, Warning, TEXT("Invalid actor reference passed to Execute_Interact"));
			return;
		}

		if (Actor->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
		{
			IInteractable::Execute_Interact(Actor);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Actor does not implement IInteractable interface"));
		}
	}
	
};


