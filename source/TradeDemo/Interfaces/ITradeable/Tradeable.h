#pragma once

#include "Tradeable.generated.h"

// This interface could be used for any object that can be traded between players,
// such as items and resources.

UINTERFACE(MinimalAPI, Blueprintable)
class UTradeable : public UInterface
{
	GENERATED_BODY()	
};

class TRADEDEMO_API ITradeable
{
	GENERATED_BODY()
public:
	// Add Interface Functions here:
	virtual void Trade();
};