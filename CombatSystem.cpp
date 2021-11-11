#include "stdafx.h"
#include "CombatSystem.h"

std::vector<Player> players;

bool CombatSystem::SetFighters() {

	Player& player1 = players.at(0);
	Player& player2 = players.at(1);

	return !players.empty();
}

//All the logs to be displayed to the user
void CombatSystem::HitLog(Player& fighter, Player& victim, uint32_t randAttack) {
	std::cout << fighter.getName() << " hits " << victim.getName() << " for " << randAttack << " - HP: " << (victim.getHp() - randAttack) << "\n";
}

void CombatSystem::DefendLog(Player& fighter, Player& victim, uint32_t randAttack) {
	std::cout << victim.getName() << " Defended " << fighter.getName() << "'s attack for " << randAttack << " - HP: " << victim.getHp() << "\n";
}

void CombatSystem::Start(PlayerSystem gameObject) {

	gameObject.getPlayerData(players);

	if (CombatSystem::SetFighters()) 
	{
		//print the player data with the overrided operator "<<" for each player
		for (Player eachPlayer : players) {
			std::cout << eachPlayer << "\n";
			eachPlayer.getPlayerAttacks();
		}
	}
}

bool CombatSystem::CheckWinner() {
	//check each player by reference
	for (Player& player : players) {
		//std::cout << "// DEBUG: " << eachPlayer.getName() << " is dead? " << eachPlayer.isDead() << "\n";
		//check if the player is dead with the "isDead()" function in the Player Class
		if (player.isDead()) {
			std::cout << player.getName() << " is dead! " << "\n";
			return true;
		}
	}
	return false;
}

void CombatSystem::Fight(uint32_t attackValue, uint32_t defenseValue, Player& fighter, Player& victim) {
	//Check if the player defends or not the attack
	if (defenseValue > attackValue) {
		CombatSystem::DefendLog(victim, fighter, attackValue);
	}
	// Make it display " Missed " instead of appearing the ugly zero
	else if (attackValue == 0) { std::cout << "Missed" << "\n"; }
	else { // check if the player cant defend, otherwise he gets hit 
		CombatSystem::HitLog(fighter, victim, attackValue);
		victim.getHit(attackValue);
	}
}

void CombatSystem::StartFight() {
	bool turn = true ;

	//CombatSystem::InitLog();
	do {
		turn = !turn;

		//Create a turn changing system
		if (turn) { // player 1's turn	

			//TO DO: attack get dmg
			//CombatSystem::Fight(player1.).getRandAttack(), player2.getRandDefense(), player1, player2);

		}
		else { // player 2's turn

			//TO DO: attack get dmg
			//CombatSystem::Fight(player2.getRandAttack(), player1.getRandDefense(), player2, player1);

		}
		Sleep(500);

	} while (!CombatSystem::CheckWinner()); // if false - repeat , if true exits
}