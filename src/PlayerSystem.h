//PlayerSystem.h - Every Player
//Made by rikkoRicardo

#pragma once
#include "stdafx.h"
#include "Player.h"

class PlayerSystem {
public:
	const int Default = 1;
	std::map<uint16_t, Player>& playerMap = PlayerSystem::getPlayerMap();

private:
	uint16_t playercounter = 1;
	uint16_t preferedPlayerId = 0;
public:

	std::map<uint16_t, Player>& getPlayerMap() { 
		static std::map<uint16_t, Player>playerMap;
		return playerMap; 
	}

	uint16_t getPreferedPlayerId() const{ return preferedPlayerId; }
	Player getPlayer(const uint16_t playerNumber) {if(playerNumber <= playerMap.size()) return PlayerSystem::getPlayerMap().at(playerNumber); }
	inline void setPlayerTemplate(const uint16_t DefaultPresetNumber = 0,const std::string name = "",const int16_t hp = 0,const uint16_t defense = 0);
	void setPlayer(const std::string name,const int16_t hp,const uint16_t defense);
	void setPresetPlayer(const uint16_t DefaultPresetNumber);
	inline void resetPlayer(const uint16_t index) { playerMap.at(index) = Player(Default); }

	void getPlayerAttackList(const Player& fighter) const{ fighter.getAttacks(); }
	void setPlayerAttack(const uint16_t index,const std::string name,const std::string description,const uint32_t dmg);
	
	Player setPreferedFighter();
	Player setRandEnemy();
	
	void showPlayerData();

};