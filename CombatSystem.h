#pragma once
#include "stdafx.h"
#include "Player.h"

namespace CombatSystem {
	void AddDefaultPlayer();
	void AddPlayer(std::string name, short hp, unsigned short attack, unsigned short defense);
	void HitLog(Player& fighter, Player& victim, int rand_attack);
	void DefendLog(Player& fighter, Player& victim, int rand_attack);
	void InitLog();
	bool CheckWinner();
	void Fight(int attackValue, int defenseValue, Player& fighter, Player& victim);
	void StartFight();
}