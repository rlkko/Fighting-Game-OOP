//CombatSystem.h - All the logs and checks needed for the combat are located here
//Made by RikkoRicardo

#pragma once
#include "stdafx.h"
#include "PlayerSystem.h"
#include "Player.h"
#include "Fight.h"

namespace CombatSystem {

	void Start();
	void HitLog(Player& fighter, Player& victim, uint32_t rand_attack);
	void DefendLog(Player& fighter, Player& victim, uint32_t rand_attack);
	
	bool CheckWinner();
	void StartFight();
	void Fight(uint32_t attackValue, uint32_t defenseValue, Player& fighter, Player& victim);
}