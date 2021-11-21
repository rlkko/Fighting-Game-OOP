//CombatSystem.h - All the logs and checks needed for the combat are located here
//Made by RikkoRicardo

#pragma once
#include "stdafx.h"
#include "PlayerSystem.h"
#include "Player.h"

namespace CombatSystem {
	const int firstPlayer = 1;
	const int secondPlayer = 2;

	void Start();
	void StartCombat();

	void PlayerOneTurn();
	void PlayerTwoTurn();
	inline void CheckHitTemplate( Player& fighter, Player& victim);

	bool CheckWinner();
};