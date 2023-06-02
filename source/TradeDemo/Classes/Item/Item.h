// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TradeDemo/Interfaces/IDamagable/Damagable.h"
#include "TradeDemo/Interfaces/IInteractable/Interactable.h"
#include "TradeDemo/Interfaces/IInventoryItem/InventoryItem.h"
#include "TradeDemo/Interfaces/ITradeable/Tradeable.h"
#include "Item.generated.h"

// A base class for all items in the game. It has properties such as
// name, weight, and value, which can be extended for specific item types.
UCLASS()
class TRADEDEMO_API AItem : public AActor, public IDamagable, public IInteractable, public IInventoryItem, public ITradeable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Class Attributes and Properties
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FString Name;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	float Weight;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	float Value;

	virtual float TakeDamage( float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser ) override;
	virtual void Interact() override;
	virtual void AddToInventory() override;
	virtual void RemoveFromInventory() override;
	virtual void Trade() override;

};
