// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Weapon.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize default values
	Name = TEXT("Default Weapon");
	Weight = 0.0f;
	Value = 0.0f;
	Damage = 0.0f;
	Range = 0.0f;
	
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AWeapon::Interact()
{
	// implementation of interaction with weapon
}

void AWeapon::AddToInventory()
{
	// implementation of adding weapon to inventory
}

void AWeapon::RemoveFromInventory()
{
	// implementation of removing weapon from inventory
}

void AWeapon::Trade()
{
	// implementation of weapon being traded
}

void AWeapon::Attack()
{
	// implementation of weapon attack
}

