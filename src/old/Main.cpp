// Main.cpp : Program execution begins and ends there. the game variable can be found at "Fight.h"
//By rikkoRicardo

//Essential includes
#include "stdafx.h"
#include "FightingGame.h"

int main()
{
	// pseudo-random number generator is initialized using the argument passed as seed.
	srand(static_cast<uint32_t>(time(nullptr)));

	//You can add up to two players, global variable game
	setPlayer(NULL,"John God", 100, 20);
	//game.setPlayerAttack(0,"Powerful Punch", "This punch has been blessed by god!", 50);

	setPlayer(1);

	Start();
	
	//Temp
	std::cin.get();
}