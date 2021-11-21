//PlayerSystem.h - Every Player
//Made by rikkoRicardo

#pragma once
#include "stdafx.h"
#include "Player.h"

class PlayerSystem {
private:
	uint16_t playercounter = 1;
	uint16_t preferedPlayerId = 0;
	std::map<uint16_t,Player> playerMap;
public:

	uint16_t getPreferedPlayerId() const{ return preferedPlayerId; }
	Player getPlayer(uint16_t playerNumber) {if(playerNumber <= playerMap.size()) return playerMap.at(playerNumber); }
	inline void setPlayerTemplate(uint16_t DefaultPresetNumber = 0, std::string name = "", int16_t hp = 0, uint16_t defense = 0);
	void setPlayer(std::string name, int16_t hp, uint16_t defense);
	void setPresetPlayer(uint16_t DefaultPresetNumber);
	inline void resetPlayer(uint16_t index) { playerMap.at(index) = Player(Default); }

	void getPlayerAttackList(Player& fighter) const{ fighter.getAttacks(); }
	void setPlayerAttack(uint16_t index, std::string name, std::string description, uint32_t dmg);
	
	Player setPreferedFighter();
	Player setRandEnemy();

	void showPlayerData();

};