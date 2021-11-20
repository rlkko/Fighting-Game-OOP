#include "stdafx.h"
#include "PlayerSystem.h"

Player PlayerSystem::setPreferedFighter() {
	uint16_t chosenFighter;	

	for (auto& player : playerVector) {
		//Player.first being the ID, Player.second being the actual player
		 std::cout << player.first << " - " << player.second.getName() << '\n';
	}
	std::cout << "0 - Quit\n";

	std::cout << "\nChoose your main char: \n";

	do{
		std::cin >> chosenFighter;

		if (chosenFighter == 0) exit(0);

	} while (playerVector.find(chosenFighter) == playerVector.end());

	return playerVector.at(chosenFighter);
}

Player PlayerSystem::setRandEnemy(Player& preferredFighter )
{	
	for (auto& player : playerVector)
	{
		if (player.second.getName().compare(preferredFighter.getName()))
		{
			//player.second is the pair second variable / the player class
			 return player.second;
		}
	}

	std::cout << "No other Player Found, Default Player Created\n";
	return Player(Default);
}

void PlayerSystem::setPlayer(std::string name, int16_t hp, uint16_t defense)
{
	setPlayerTemplate(NULL, name, hp, defense);
}

void PlayerSystem::setPresetPlayer(uint16_t DefaultPresetNumber) {
	setPlayerTemplate(DefaultPresetNumber);
}

inline void PlayerSystem::setPlayerTemplate(uint16_t DefaultPresetNumber, std::string name, int16_t hp, uint16_t defense)
{
	Player createdPlayer = Player(DefaultPresetNumber);

	if (playercounter < 4)
	{
		if (hp != 0 && defense != 0) {
			createdPlayer = Player(name, hp, defense);
		}

		playerVector.insert(std::make_pair(playercounter, createdPlayer));
	}
	else
	{
		std::cout << "Player Limit reached! \n";
		return;
	}
	playercounter++;
}

void PlayerSystem::showPlayerData()
{
	//print the player data with the overrided operator "<<" for each player
	for (auto& eachPlayer : playerVector) {
		std::cout << eachPlayer.second << "\n";
		eachPlayer.second.showPlayerAttacks();
	}
}

void PlayerSystem::setPlayerAttack(uint16_t index, std::string name, std::string description, uint32_t dmg) 
{
	//You've got 5
	for(auto& player : playerVector)
	{
		if (player.first == index) player.second.AddAttack(name,description,dmg);
		else std::cout << "Player Attack index error!\n";
	}
}
