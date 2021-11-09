#include "stdafx.h"
#include "CombatSystem.h"

#define FIRST 0
#define SECOND 1

std::vector<Player> players;

void CombatSystem::AddPlayer(std::string name,short hp,unsigned short attack,unsigned short defense) {
	players.push_back(Player(name,hp,attack,defense,NULL)); 
	// Last parameter is NULL because the feature is not implemented yet
}

void CombatSystem::AddDefaultPlayer() {
	players.push_back(Player());
}

//All the logs to be displayed to the user
void CombatSystem::HitLog(Player& fighter, Player& victim, int rand_attack) {
	std::cout << fighter.getName() << " hits " << victim.getName() << " for " << rand_attack << " - HP: " << (victim.getHp() - rand_attack) << std::endl;
}

void CombatSystem::DefendLog(Player& fighter, Player& victim, int rand_attack) {
	std::cout << victim.getName() << " Defended " << fighter.getName() << "'s attack for " << rand_attack << " - HP: " << victim.getHp() << std::endl;
}

void CombatSystem::InitLog() {
	// pseudo-random number generator is initialized using the argument passed as seed.
	srand(time(NULL));
 
	//print the player data with the overrided operator "<<" for each player
	for (Player& eachPlayer : players) {
		std::cout << eachPlayer << std::endl;
	}
}

bool CombatSystem::CheckWinner() {
	//check each player by reference
	for (Player& player : players) {
		//std::cout << "// DEBUG: " << eachPlayer.getName() << " is dead? " << eachPlayer.is_dead() << std::endl;
		//check if the player is dead with the "is_dead()" function in the Player Class
		if (player.is_dead()) {
			std::cout << player.getName() << " is dead! " << std::endl;
			return true;
		}
	}
	return false;
}

void CombatSystem::Fight(int attack_value, int defense_value, Player& fighter, Player& victim) {

	//Check if the player defends or not the attack
	if (defense_value > attack_value) {
		CombatSystem::DefendLog(victim, fighter, attack_value);
	}
	// Make it display " Missed " instead of appearing the ugly zero
	else if (attack_value == 0) { std::cout << "Missed" << std::endl; }
	else { // check if the player cant defend, otherwise he gets hit 
		CombatSystem::HitLog(fighter, victim, attack_value);
		victim.getHit(attack_value);
	}
}

void CombatSystem::StartFight() {
	bool turn = true;

	//Initialize the palyers
	Player& player1 = players[FIRST];
	Player& player2 = players[SECOND];

	do {
		turn = !turn;

		//Create a turn changing system
		if (turn) { // player 1's turn	

			CombatSystem::Fight(player1.getRandAttack(), player2.getRandDefense(), player1, player2);

		}
		else { // player 2's turn

			CombatSystem::Fight(player2.getRandAttack(), player1.getRandDefense(), player2, player1);

		}
		Sleep(500);

	} while (!CombatSystem::CheckWinner()); // if false - repeat , if true exits
}