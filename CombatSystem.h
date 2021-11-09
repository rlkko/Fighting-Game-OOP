#pragma once
#include "stdafx.h"
#include "Player.h"

namespace CombatSystem {
	void AddPlayer();
	void AddPlayer(std::string name, int16_t hp, int16_t attack, uint16_t defense);
	void HitLog(Player& fighter, Player& victim, uint32_t rand_attack);
	void DefendLog(Player& fighter, Player& victim, uint32_t rand_attack);
	void InitLog();
	bool CheckWinner();
	void Fight(uint32_t attackValue, uint32_t defenseValue, Player& fighter, Player& victim);
	void StartFight();
}