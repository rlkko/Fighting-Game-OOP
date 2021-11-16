#include "stdafx.h"
#include "Player.h"

void Player::AddPresetAttack(uint16_t presetNumber) {

	if (AttackList.size() < MAX_ATTACKS)
	{
		AttackList.push_back(Attack(presetNumber));
	}
	else
	{
		std::cout << "Attack Limit reached!" << std::endl;
	}
}

void Player::AddAttack(std::string name, std::string description, uint16_t attack) {

	if (AttackList.size() < MAX_ATTACKS)
	{
		AttackList.push_back(Attack(name, description, attack));
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
			int32_t dmg;

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
