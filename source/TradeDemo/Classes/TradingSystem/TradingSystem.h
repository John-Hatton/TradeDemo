#pragma once

// A class that represents the trading system in the game. It contains information about
// the prices of items and allows the player to buy and sell items with NPCs or other players.


#include "TradeDemo/Classes/MyPlayer/MyPlayer.h"
#include "TradeDemo/Classes/Item/Item.h"
#include "TradingSystem.generated.h"

UCLASS()
class TRADEDEMO_API UTradingSystem : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trading")
	TMap<AItem*, float> Prices;

	bool BuyItem(AMyPlayer* Player, AItem* Item);
	bool SellItem(AMyPlayer* Player, AItem* Item);
};
