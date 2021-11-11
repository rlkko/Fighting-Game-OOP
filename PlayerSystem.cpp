#include "stdafx.h"
#include "PlayerSystem.h"


void PlayerSystem::setPlayer(std::string name, int16_t hp, uint16_t defense)
{
	Player createdPlayer = Player(name, hp, defense, NULL);
	if(Playercounter < 4)
	{
		players.at(Playercounter) = createdPlayer;
	}
	else 
	{
		std::cout << "Player Limit reached! \n";
		return;
	}
	Playercounter++;
}

void PlayerSystem::setPlayer(uint16_t DefaultPresetNumber) {
	if (Playercounter < 4)
	{
		players.at(Playercounter) = Player(DefaultPresetNumber);
	}
	else
	{
		std::cout << "Player Limit reached! \n";
		return;
	}
	Playercounter++;
}

void PlayerSystem::setPlayerAttack(uint16_t index, std::string name, std::string description, uint16_t dmg) 
{
	players.at(index).AddAttack(name, description, dmg);
}