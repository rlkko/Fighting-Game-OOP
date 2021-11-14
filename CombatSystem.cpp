#include "stdafx.h"
#include "CombatSystem.h"

PlayerSystem game;
std::vector<std::pair<uint16_t, Player>>fightersVec;

void CombatSystem::Start() {

	for(Player& player:game.getPlayerVector()){
		if (player.getAttacks().empty())
		{
			//TO DO: this doesnt work
			//Attack one is the default Attack
			player.AddPresetAttack(Default);
		}
	}
	game.showPlayerData();

	//First the player number, then the Player
	fightersVec.emplace_back(1,game.setPreferedFighter());
	fightersVec.emplace_back(2,game.setRandEnemy(fightersVec.at(0).second));

	CombatSystem::StartCombat();
}

void CombatSystem::StartCombat() {
	bool turn = true;

	do {
		turn = !turn;

		if (turn)
		{ // player 1's turn
			CombatSystem::CheckHit(fightersVec.at(0).second, fightersVec.at(1).second);
		}
		else
		{ // player 2's turn
			CombatSystem::CheckHit(fightersVec.at(1).second, fightersVec.at(0).second);
		}
		Sleep(500);

	} while (!CombatSystem::CheckWinner()); // if false - repeat , if true returns
}

void CombatSystem::CheckHit(Player& fighter, Player& victim) {
	Attack nextAttack = fighter.getNextAttack();
	uint32_t attackValue = nextAttack.getRandDamage();
	uint32_t defenseValue = victim.getRandDefense();

	// Make it display " Missed " instead of appearing the ugly zero
	if (attackValue == 0) { std::cout << fighter.getName() << " Missed!" << "\n"; return; }

	if (attackValue > defenseValue) 
	{//next attack operator>> overloaded
		victim.getHit(attackValue);
		std::cout << fighter.getName() << " hits " << victim.getName() << " with " << nextAttack.getName() << " for " << attackValue << " - HP: " << victim.getHp() << "\n";
	}
	else 
	{//next attack operator>> overloaded
		std::cout << victim.getName() << " Defendeds " << fighter.getName() << " 's " << nextAttack.getName() << " for " << attackValue << " - HP: " << victim.getHp() << "\n";
	}
}

bool CombatSystem::CheckWinner() 
{
	//check each player by reference
	for (auto& fighter: fightersVec ) {
		
		if(fighter.second.isDead()){
			std::cout << fighter.second.getName() << " is dead! " << "\n";
			return true;
		}
	}
	return false;
}