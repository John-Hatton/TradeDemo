#pragma once

#include "WeaponInterface.generated.h"

// This interface could be used for any object that can be used as a weapon in the game,
// such as guns, swords, and axes.

UINTERFACE(MinimalAPI, Blueprintable)
class UWeaponInterface : public UInterface
{
	GENERATED_BODY()	
};

class IWeaponInterface
{
	GENERATED_BODY()
public:
	// Add Interface Functions here:
};
