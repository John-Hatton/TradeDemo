// Fill out your copyright notice in the Description page of Project Settings.
#include "Item/Item.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AItem::TakeDamage(float Amount)
{
	// implementation of item taking damage
}

void AItem::Interact()
{
	// implementation of interaction with item
}

void AItem::AddToInventory()
{
	// implementation of adding item to inventory
}

void AItem::RemoveFromInventory()
{
	// implementation of removing item from inventory
}

void AItem::Trade()
{
	// implementation of item being traded
}
