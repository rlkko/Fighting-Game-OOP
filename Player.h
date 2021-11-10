#pragma once
#include "stdafx.h"

class Player
{
private:
	std::string name;
	int16_t hp;
	uint16_t attack;
	uint16_t defense;
	float luck;

public:

	short getRandAttack() const { return rand() % this->attack; }
	short getRandDefense() const { return rand() % this->defense; }

	Player() { Player DefaultPlayer(this->name = "Default", this->hp = 100, this->attack = 20, this->defense = 30, this->luck = 0.2f); }

	//Define a costum player model
	Player(const std::string theName, int16_t theHp, uint16_t theAttack, uint16_t theDefense, float theLuck) :name(theName), hp(theHp), attack(theAttack),defense(theDefense), luck(theLuck) { }

	short getHit(uint16_t Enemydmg) { return this->hp -= Enemydmg; }

	constexpr bool isDead() const { return (this->hp <= 0 ? true : false); } // condition ? result_if_true : result_if_false

	//Creating getters for the attributes so we can use them
	std::string getName() const { return this->name; }
	constexpr short getHp() const { return this->hp; }
	constexpr short getAttackInfo() const { return this->attack; }
	constexpr short getDefenseInfo() const { return this->defense; }
	constexpr float getLuck() const { return this->luck; }
};

//Override the Operator "<<" to be able to print out the player object
std::ostream& operator<< (std::ostream& obj, Player& player) {
	return obj << "Name: " << player.getName() << std::endl <<
		"HP: " << player.getHp() << std::endl <<
		"Attack: " << player.getAttackInfo() << std::endl <<
		"Defense: " << player.getDefenseInfo() << std::endl <<
		"Luck: " << player.getLuck() * 100 << std::endl <<
		"Added Sucessfully!" << std::endl;
}