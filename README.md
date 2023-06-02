# Trade Demo

---

## Introduction

This project is a demo which sets out to make functional trading work from the start. 

---

## Classes

Animal - A base class for all animals in the game, it has basic properties such as health, speed, and behavior that 
can be extended for specific animal types.

Inventory - A class that represents the inventory system of the player. It contains information about the items that the 
player has, such as the type of item, quantity, and weight.

Item - A base class for all items in the game. It has properties such as name, weight, and value, which can be extended 
for specific item types.

MyPlayer - A class that represents the player character. It contains properties such as health, speed, and inventory 
that can be modified during the game.

TradingSystem - A class that represents the trading system in the game. It contains information about the prices of 
items and allows the player to buy and sell items with NPCs or other players.

Weapon - A base class for all weapons in the game. It has properties such as damage, range, and ammo capacity, which can 
be extended for specific weapon types.

---

## Interfaces 

IInteractable: This interface could be used for any object that can be interacted with in the game, such as items, NPCs, 
and other players.

IDamageable: This interface could be used for any object that can take damage in the game, such as players, animals, and 
environmental objects.

IWeapon: This interface could be used for any object that can be used as a weapon in the game, such as guns, swords, and 
axes.

IInventoryItem: This interface could be used for any object that can be added to the player's inventory, such as
weapons, ammo, and consumables.

ITradeable: This interface could be used for any object that can be traded between players, such as items and resources.

IBuilding: This interface could be used for any object that can be built by players, such as houses, walls, and traps.

ITask: This interface could be used for any task that needs to be completed in the game, such as gathering resources, 
building structures, and completing quests.

