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
	virtual void Interact();
};
