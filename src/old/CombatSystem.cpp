#include "stdafx.h"
#include "Player.h"
#include "PlayerSystem.cpp"
#include <map>

//Initialized variable to use the external one
//Map to store all the fighters and index
std::map<uint16_t, Player>fighterList;

void Start() {

	showPlayerData();

	//Creating a pair to attribute an id to a player
	fighterList.insert(std::make_pair(1, setPreferedFighter()));
	fighterList.insert(std::make_pair(2, setRandEnemy(fighterList.at(1))));
	
	StartCombat();
}

bool CheckWinner()
{
	//check each player by reference
	for (auto& fighter : fighterList) {

		if (fighter.second.isDead()) {
			std::cout << fighter.second.getName() << " / player N " << fighter.first << " is dead! " << "\n";
			return true;
		}
	}
	return false;

}

void CheckHit(Player& fighter, Player& victim) {
	const Attack& nextAttack = fighter.getNextAttack();
	const uint32_t& attackValue = nextAttack.getRandDamage();
	const uint32_t& defenseValue = victim.getRandDefense();

	// Make it display " Missed " instead of appearing the ugly zero
	if (!attackValue) { std::cout << fighter.getName() << " Missed!" << "\n\n"; }
	else
	{
		if (attackValue > defenseValue)
		{//next attack operator>> overloaded
			victim.getHit(attackValue);
			std::cout << fighter.getName() << " hits " << victim.getName() << " with " << nextAttack.getName() << " for " << attackValue << " - HP: " << victim.getHp() << "\n\n";
		}
		else
		{//next attack operator>> overloaded
			std::cout << victim.getName() << " Defendeds " << fighter.getName() << "'s " << nextAttack.getName() << " for " << attackValue << " - HP: " << victim.getHp() << "\n\n";
		}
	}
}

void StartCombat() {
	bool turn = true;

	do {
		turn = !turn;

		if (turn)
		{ // player 1's turn
			CheckHit(fighterList.at(1), fighterList.at(2));
		}
		else
		{ // player 2's turn
			CheckHit(fighterList.at(2), fighterList.at(1));
		}
		Sleep(500);

	} while (!CheckWinner()); // if false - repeat , if true returns
	
}