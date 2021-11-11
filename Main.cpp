// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//By zei.

//Essential includes
#include "stdafx.h"
#include "PlayerSystem.h"
#include "CombatSystem.h"

int main()
{
	// pseudo-random number generator is initialized using the argument passed as seed.
	srand(static_cast<uint32_t>(time(nullptr)));
	PlayerSystem game;
	//You can add up to two players
	game.setPlayer("John", 100, 20);
	game.setPlayerAttack(1,"Powerful Punch", "This punch has been blessed by god!", 50);

	//Default Player Preset
	game.setPresetPlayer(Default);

	//Game initializes
	CombatSystem::Start(game);

	//Temp
	std::cin.get();
}