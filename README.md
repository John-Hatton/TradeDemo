# Trade Demo

---

## Introduction

This project is a demo which sets out to make functional trading work from the start. Much effort has been put into the 
design of a few key classes and interfaces, which should be expanded, as the game functionality grows. The idea is to 
have much of the functionality in C++, and then use this to our advantage, as we generate Blueprint classes.

---

## Project Startup

To get started with this project, you will need to Download UE5 from the Epic Games Launcher, or compile the Engine from
source. Once you've got a working engine, simply clone the repository.

Getting things working can be a bit tricky, but here's my preferred setup.

    1. Install Visual Studio Community, see the following link to ensure you have the right settings selected:

https://docs.unrealengine.com/5.2/en-US/setting-up-visual-studio-development-environment-for-cplusplus-projects-in-unreal-engine/

Disregard the fact that it uses VS 2019, and opt for the newest version of Visual Studio.

Next up is: 

    2. Download and install Rider through the Jetbrains Toolbox

https://www.jetbrains.com/toolbox-app/

Once you have Rider installed, you will open up Unreal Engine, navigate to the settings, and change the default editor 
to Rider. After you have done this close the engine.

    3. Open Rider, and select the TradeDemo.sln file 

Once rider opens up, you should be able to build, and Unreal Engine will ask you if you want to install RiderLink.

If you are using the Epic Games launcher version of the Engine, then you will want to install the RiderLink plugin to 
the game, however if you're using the compiled Github source version of the Engine, then you are able to install 
RiderLink directly to the Engine. 

Once it has finished installing, you can then build the project, and it will launch the Unreal Engine Editor when it is 
done. From here the project should play as normal.


!Please note that if you do not have access to rider, you can do all of this from Visual Studio, the project should 
build fine, but if you have access to Jetbrains tools, Rider is worth the extra effort!!!

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

---

## Testing 

For the first time in an Unreal Project, I've decided to incorporate Unit tests into my development. This project is a 
rather complicated one, and I'm hoping to spend quite a lot of time adjusting these base classes, so extending them to 
my blueprint classes, once I get to that stage, will be a walk in the park. To aid in this process, I've written some
basic Unit Tests. The goal is to write new tests, before implementing any functionality. The tests should fail. In fact, 
as of posting this pull request, there are tests that are failing. We want this, so that we can go in later, and 
implement the missing functionality. Eventually, I plan to incorporate a Github action, which will run all the tests, 
and report back. After which, I would then incorporate a Build status indicator, but one thing at a time here.

Please see the test cases in the test folder, and try to come up with your own tests in the future. This models the 
Unreal Engine guide on writing test cases.

---

