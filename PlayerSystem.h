//PlayerSystem.h - Every Player
//Made by rikkoRicardo

#pragma once
#include "stdafx.h"
#include "Player.h"


class PlayerSystem {
private:
	uint16_t Playercounter = 0;
	std::vector<Player> playerVector;
public:
	Player getPlayer(uint16_t playerNumber) {if(playerNumber <= playerVector.size()) return playerVector.at(playerNumber); }
	void setPlayer(std::string name, int16_t hp, uint16_t defense);
	void setPresetPlayer(uint16_t DefaultPresetNumber);
	inline void resetPlayer(uint16_t index) { playerVector.at(index) = Player(Default); }

	void getPlayerAttackList(Player& fighter) { fighter.getAttacks(); }
	void setPlayerAttack(uint16_t index, std::string name, std::string description, uint32_t dmg);

	void showPlayerData();
	std::vector<Player> getPlayerVector() { return playerVector; }
};