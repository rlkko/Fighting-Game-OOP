#pragma once
#include "stdafx.h"
#include "Player.h"

#define Default 1

	static std::vector<Player> players = { Player(Default),Player(Default),Player(Default),Player(Default) };
	static uint16_t Playercounter = 0;

namespace PlayerSystem {

	void setPlayer(std::string name, int16_t hp, uint16_t defense);
	void setPlayer(uint16_t DefaultPresetNumber);
	//void resetPlayer(uint16_t index) { players[index] = Player(Default); }

	void setPlayerAttack(uint16_t index, std::string name, std::string description, uint16_t dmg);
	
	// Remember to initialize the players first
	//std::vector<Player> returnPlayers() { if (players.empty()) return players; else return 0; };
};