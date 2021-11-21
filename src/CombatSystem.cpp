#include "stdafx.h"
#include "CombatSystem.h"

//Prototype variable to be replaced in the runtime
PlayerSystem game;

//Map to store all the fighters and index
std::map<uint16_t, Player>fighterList;

void CombatSystem::Start() {

	game.showPlayerData();

	//Creating a pair to attribute an id to a player
	fighterList.insert(std::make_pair(firstPlayer, game.setPreferedFighter()));
	fighterList.insert(std::make_pair(secondPlayer, game.setRandEnemy()));
	
	CombatSystem::StartCombat();
}

void CombatSystem::StartCombat() {
	bool turn = true;

	do {
		turn = !turn;

		turn ? PlayerOneTurn() : PlayerTwoTurn();

		Sleep(500);

	} while (!CombatSystem::CheckWinner()); // if false - repeat , if true returns
	
}


inline void CombatSystem::CheckHitTemplate( Player& fighter, Player& victim) {
	const Attack& nextAttack = fighter.getNextAttack();
	const uint32_t& attackValue = nextAttack.getRandDamage();
	const uint32_t& defenseValue = victim.getRandDefense();

	// Make it display " Missed " instead of appearing the ugly zero
	if (!attackValue) { std::cout << fighter.getName() << " Missed!" << "\n\n"; return; }
	else 
	{
		if (attackValue > defenseValue) 
		{
			victim.getHit(attackValue);
			std::cout << fighter.getName() << " hits " << victim.getName() << " with " << nextAttack.getName() << " for " << attackValue << " - HP: " << victim.getHp() << "\n\n";
		}
		else 
		{
			std::cout << victim.getName() << " Defendeds " << fighter.getName() << "'s " << nextAttack.getName() << " for " << attackValue << " - HP: " << victim.getHp() << "\n\n";
		}
	}
}

void CombatSystem::PlayerOneTurn() {
	CheckHitTemplate(fighterList.at(firstPlayer), fighterList.at(secondPlayer));
}

void CombatSystem::PlayerTwoTurn() {
	CheckHitTemplate(fighterList.at(secondPlayer), fighterList.at(firstPlayer));
}


bool CombatSystem::CheckWinner() 
{
	//check each player by reference
	for (auto& fighter: fighterList) {
		
		if(fighter.second.isDead()){
			std::cout << fighter.second.getName() << " is dead! " << "\n";
			return true;
		}
	}
	return false;

}

