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

	uint32_t randAttackIndex = rand() %  this->getAttacks().size();
	Attack SelectedAttack = this->getAttacks().at(randAttackIndex);

	return SelectedAttack;
}