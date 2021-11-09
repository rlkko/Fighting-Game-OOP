#pragma once
#include "stdafx.h"
#include "Player.h"

namespace CombatSystem {
	void HitLog(Player& assasin, Player& victim, int rand_attack);
	void AddDefaultPlayer();
	void AddPlayer(std::string name, short hp, unsigned short attack, unsigned short defense);
	void HitLog(Player& assasin, Player& victim, int rand_attack);
	void DefendLog(Player& assasin, Player& victim, int rand_attack);
	void InitLog();
	bool CheckWinner();
	void Fight(int attack_value, int defense_value, Player& fighter, Player& victim);
	void StartFight();
}