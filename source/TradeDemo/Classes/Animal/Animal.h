// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TradeDemo/Interfaces/IDamagable/Damagable.h"
#include "TradeDemo/Interfaces/IInteractable/Interactable.h"
#include "Animal.generated.h"


// A base class for all animals in the game. It has basic properties such as
// health, speed, and behavior that can be extended for specific animal types.
UCLASS()
class TRADEDEMO_API AAnimal : public APawn, public IDamagable, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAnimal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
