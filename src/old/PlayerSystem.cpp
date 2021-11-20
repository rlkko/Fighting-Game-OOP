#include "stdafx.h"
#include "Player.h"

namespace{

	uint16_t Playercounter = 1;
	std::map<uint16_t,Player> playerVector;

Player setPreferedFighter() {
	uint16_t chosenFighter;

	std::cout << "\nChoose your main char: \n";

	for(uint16_t i: playerVector) {
		std::cout << i << " - " << playerVector.at(i).getName() << "\n";
	}
	
	do{
		std::cin.get(chosenFighter, 2);
	} while (chosenFighter > playerVector.size());

	putchar('\n');
	return playerVector[chosenFighter];
}

Player setRandEnemy(Player& preferredFighter )
{
	for (Player player : playerVector) {
		if (player.getName() != preferredFighter.getName())
			return player;
	}

	std::cout << "No other Player Found, Default Player Created\n";
	return Player(Default);
}

void setPlayer(uint16_t DefaultPresetNumber = 0,std::string name = "", int16_t hp = 0, uint16_t defense = 0)
{
	Player createdPlayer = Player(DefaultPresetNumber);

	if(Playercounter < 4)
	{
		if (hp != 0 && defense != 0) {
			createdPlayer = Player(name, hp, defense);
		}

		playerVector.insert(std::make_pair(Playercounter,createdPlayer));
	}
	else 
	{
		std::cout << "Player Limit reached! \n";
		return;
	}
	Playercounter++;
}

void showPlayerData()
{
	//print the player data with the overrided operator "<<" for each player
	for (Player& eachPlayer : playerVector) {
		std::cout << eachPlayer << "\n";
		eachPlayer.showPlayerAttacks();
	}
}

void setPlayerAttack(uint16_t index, std::string name, std::string description, uint32_t dmg) 
{
	if (index <= playerVector.size())
		playerVector.at(index).AddAttack(name,description,dmg);
	else {
		std::cout << "Player Attack index error!\n";
	}
}

}