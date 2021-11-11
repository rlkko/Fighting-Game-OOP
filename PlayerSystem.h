#pragma once
#include "stdafx.h"
#include "Player.h"

	static std::vector<Player> players;
	static uint16_t Playercounter = 1;

namespace PlayerSystem {

	void setPlayer(std::string name, int16_t hp, uint16_t defense);
	void setPresetPlayer(uint16_t DefaultPresetNumber);
	inline void resetPlayer(uint16_t index) { players.at(index) = Player(Default); }

	void setPlayerAttack(uint16_t index, std::string name, std::string description, uint16_t dmg);
};