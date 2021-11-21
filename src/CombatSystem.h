//CombatSystem.h - All the logs and checks needed for the combat are located here
//Made by RikkoRicardo

#pragma once
#include "stdafx.h"
#include "PlayerSystem.h"
#include "Player.h"
#include "FightingGame.h"

namespace CombatSystem {
	void Start();
	void StartCombat();

	void PlayerOneTurn();
	void PlayerTwoTurn();
	inline void CheckHitTemplate(Player& fighter, Player& victim);

	bool CheckWinner();
}