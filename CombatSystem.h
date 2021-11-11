#pragma once
#include "stdafx.h"
#include "PlayerSystem.h"
#include "Player.h"

namespace CombatSystem {

	void Start(PlayerSystem gameObject);
	void HitLog(Player& fighter, Player& victim, uint32_t rand_attack);
	void DefendLog(Player& fighter, Player& victim, uint32_t rand_attack);
	bool SetFighters();
	
	bool CheckWinner();
	void StartFight();
	void Fight(uint32_t attackValue, uint32_t defenseValue, Player& fighter, Player& victim);
}