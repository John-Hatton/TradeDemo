#pragma once

#include "Building.generated.h"

// This interface could be used for any object that can be built by players,
// such as houses, walls, and traps.

UINTERFACE(MinimalAPI, Blueprintable)
class UBuilding : public UInterface
{
	GENERATED_BODY()	
};

class TRADEDEMO_API IBuilding
{
	GENERATED_BODY()
public:
	// Add Interface Functions here:
	virtual void Build();
};
