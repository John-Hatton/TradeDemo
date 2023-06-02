// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TradeDemo/Interfaces/IInteractable/Interactable.h"
#include "TradeDemo/Interfaces/IInventoryItem/InventoryItem.h"
#include "TradeDemo/Interfaces/ITradeable/Tradeable.h"
#include "TradeDemo/Interfaces/IWeaponInterface/WeaponInterface.h"
#include "Weapon.generated.h"

// A base class for all weapons in the game. It has properties such as
// damage, range, and ammo capacity, which can be extended for specific weapon types.
UCLASS()
class TRADEDEMO_API AWeapon : public AActor, public IInteractable, public IInventoryItem, public ITradeable, public IWeaponInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact() override;
	virtual void AddToInventory() override;
	virtual void RemoveFromInventory() override;
	virtual void Trade() override;
	virtual void Attack() override;
};
