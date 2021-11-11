// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//By zei.

//Essential includes
#include "stdafx.h"
#include "PlayerSystem.h"
#include "CombatSystem.h"

int main()
{
	// pseudo-random number generator is initialized using the argument passed as seed.
	srand(time(NULL));
	//PlayerSystem Game;

	//You can add up to two players
	//Game.SetPlayer(1,"John", 100, 20);
	//Game.SetPlayerAttack(1,"Powerful Punch", "This punch has been blessed by god!", 50);

	//Game.SetPlayer(2,"Miguel",100,50);

	//Game initializes
	//CombatSystem::SetFighters();

	CombatSystem::StartFight();

	//Temp
	std::cin.get();
}