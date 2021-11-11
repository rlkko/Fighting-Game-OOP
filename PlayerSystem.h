#pragma once
#include "stdafx.h"
#include "Player.h"

static uint16_t Playercounter = 0;
static std::vector<Player> playerVector;

class PlayerSystem {

public:
	void setPlayer(std::string name, int16_t hp, uint16_t defense);
	void setPresetPlayer(uint16_t DefaultPresetNumber);
	inline void resetPlayer(uint16_t index) { playerVector.at(index) = Player(Default); }

	void setPlayerAttack(uint16_t index, std::string name, std::string description, uint16_t dmg);

	std::vector<Player> getPlayerVector() { return playerVector; }
	void getPlayerData(std::vector<Player> playervec);
};