#include "stdafx.h"
#include "FightingGame.h"

void Player::AddPresetAttack(uint16_t presetNumber) {
	AddAttackTemplate(presetNumber,"", "", 0);
}

void Player::AddAttack(std::string name, std::string description, uint16_t attack) {
	AddAttackTemplate(NULL, name, description, attack);
}

inline void Player::AddAttackTemplate(const uint16_t attackPresetNum,const std::string name,const std::string description,const uint16_t attack) {
	const int MAX_ATTACKS = 4;
	
	Attack chosenAttack = Attack(attackPresetNum);

	if (AttackList.size() < MAX_ATTACKS)
	{
		if (!name.empty()) {
			chosenAttack = Attack(name, description, attack);
		}

		AttackList.push_back(chosenAttack);
	}
	else
	{
		std::cout << "Attack Limit reached!" << std::endl;
	}
}

void Player::showPlayerAttacks()
{
	for (Attack& attack : AttackList) {
		std::cout << attack << '\n';
	}
}

Attack Player::getNextAttack() {
	char choice;

	std::map<uint16_t, Player> playerMap = game.getPlayerMap();

	if (this->AttackList.empty())
	{
		if(playerMap.size() > 2)
			std::cout << "Attacks of " << this->getName() << " not found, want to use the default one ? (y / n)\n";

			std::string name;

			std::cin >> choice;

			if(choice == 'y')
			{
				this->AddPresetAttack(Default);
			}
			else if (choice == 'n')
			{
				return NULL;
			}
	}
	uint32_t randAttackIndex = rand() % this->getAttacks().size();
	Attack SelectedAttack = this->getAttacks().at(randAttackIndex);

	return SelectedAttack;
}
