#pragma once

#include "Task.generated.h"

// This interface could be used for any task that needs to be completed in the game,
// such as gathering resources, building structures, and completing quests.

UINTERFACE(MinimalAPI, Blueprintable)
class UTask : public UInterface
{
	GENERATED_BODY()	
};

class TRADEDEMO_API ITask
{
	GENERATED_BODY()
public:
	// Add Interface Functions here:
	virtual void CompleteTask();
};