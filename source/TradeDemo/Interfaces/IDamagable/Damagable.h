#pragma once

#include "Damagable.generated.h"

// This interface could be used for any object that can take damage in the game,
// such as players, animals, and environmental objects.

UINTERFACE(MinimalAPI, Blueprintable)
class UDamagable : public UInterface
{
	GENERATED_BODY()	
};

class TRADEDEMO_API IDamagable
{
	GENERATED_BODY()
public:
	// Add Interface Functions here:
	virtual void TakeDamage(float Amount);
};
