//PlayerSystem.h - Every Player
//Made by rikkoRicardo

#pragma once
#include "stdafx.h"
#include "Player.h"

class PlayerSystem {
private:
	uint16_t playercounter = 1;
	std::map<uint16_t,Player> playerVector;
public:

	Player getPlayer(uint16_t playerNumber) {if(playerNumber <= playerVector.size()) return playerVector.at(playerNumber); }
	inline void setPlayerTemplate(uint16_t DefaultPresetNumber = 0, std::string name = "", int16_t hp = 0, uint16_t defense = 0);
	void setPlayer(std::string name, int16_t hp, uint16_t defense);
	void setPresetPlayer(uint16_t DefaultPresetNumber);
	inline void resetPlayer(uint16_t index) { playerVector.at(index) = Player(Default); }

	void getPlayerAttackList(Player& fighter) const{ fighter.getAttacks(); }
	void setPlayerAttack(uint16_t index, std::string name, std::string description, uint32_t dmg);
	
	Player setPreferedFighter();
	Player setRandEnemy(Player& preferredFighter);

	void showPlayerData();
	std::map<uint16_t,Player> getPlayerVector() { return playerVector; }

};