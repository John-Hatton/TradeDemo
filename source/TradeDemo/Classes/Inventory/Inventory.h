#pragma once

#include "TradeDemo/Classes/Item/Item.h"
#include "Inventory.generated.h"

UCLASS()
class TRADEDEMO_API UInventory : public UObject
{
    GENERATED_BODY()
    
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    TArray<AItem*> Items;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    float Weight;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    float MaxWeight;

    void AddItem(AItem* Item);
    void RemoveItem(AItem* Item);
};
