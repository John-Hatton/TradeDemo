// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TradeDemo/Interfaces/IDamagable/Damagable.h"
#include "TradeDemo/Interfaces/IInteractable/Interactable.h"
#include "TradeDemo/Classes/Inventory/Inventory.h"
#include "MyPlayer.generated.h"

// A class that represents the player character. It contains properties such as
// health, speed, and inventory that can be modified during the game.
UCLASS()
class TRADEDEMO_API AMyPlayer : public APawn, public IDamagable, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	float Health;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	UInventory* Inventory;

	virtual void TakeDamage(float Amount) override;
	virtual void Interact() override;

};
