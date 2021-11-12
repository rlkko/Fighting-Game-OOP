#include "stdafx.h"
#include "PlayerSystem.h"


void PlayerSystem::setPlayer(std::string name, int16_t hp, uint16_t defense)
{
	Player createdPlayer = Player(name, hp, defense);
	if(Playercounter < 4)
	{
		playerVector.push_back(createdPlayer);
	}
	else 
	{
		std::cout << "Player Limit reached! \n";
		return;
	}
	Playercounter++;
}

void PlayerSystem::setPresetPlayer(uint16_t DefaultPresetNumber) {
	if (Playercounter < 4)
	{
		playerVector.push_back(Player(DefaultPresetNumber));
	}
	else
	{
		std::cout << "Player Limit reached! \n";
		return;
	}
	Playercounter++;
}

void PlayerSystem::showPlayerData()
{
	//print the player data with the overrided operator "<<" for each player
	for (Player& eachPlayer : playerVector) {
		std::cout << eachPlayer << "\n";
		eachPlayer.showPlayerAttacks();
	}
}

void PlayerSystem::setPlayerAttack(uint16_t index, std::string name, std::string description, uint16_t dmg) 
{
	std::vector<Player> playerVector = getPlayerVector();
	if(index <= playerVector.size())
	playerVector.at(index+1).AddAttack(name, description, dmg);
	else {
		std::cout << "Player Attack index error!\n";
	}
}

