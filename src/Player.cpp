#include "stdafx.h"
#include "Player.h"

void Player::AddPresetAttack(uint16_t presetNumber) {
	AddAttackTemplate(presetNumber,"", "", 0);
}

void Player::AddAttack(std::string name, std::string description, uint16_t attack) {
	AddAttackTemplate(NULL, name, description, attack);
}

void Player::AddAttackTemplate(uint16_t attackPresetNum, std::string name, std::string description, uint16_t attack) {
	Attack chosenAttack = Attack(attackPresetNum);

	if (AttackList.size() < MAX_ATTACKS)
	{
		if (!name.empty() && attack != 0) {
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

	if (this->AttackList.empty())
	{
		//Attack one is the default Attack
		std::cout << "Attacks of " << this->getName() << "Not found, want to use the default one ? (y / n)\n";

			std::string name;

			std::cin >> choice;

			if(choice == 'y')
			{
				this->AddPresetAttack(Default);
			}
			else if (choice == 'n')
			{
				system("cls");
				std::cout << "Add one using the method game.AddAttack()\n";
				exit(0);
			}

	}

	uint32_t randAttackIndex = rand() %  this->getAttacks().size();
	Attack SelectedAttack = this->getAttacks().at(randAttackIndex);

	return SelectedAttack;
}
