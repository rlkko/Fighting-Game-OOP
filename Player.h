#pragma once
#include "stdafx.h"

class Player
{
private:
	const std::string name;
	int16_t hp;
	uint16_t attack;
	uint16_t defense;
	float luck;

public:

	short getRandAttack() const { return rand() % this->attack; }
	short getRandDefense() const { return rand() % this->defense; }

	//declare a Default player model
	Player() {Player PlayerModel(this->name = "Default", this->hp = 100, this->attack = 20, this->defense = 30, this->luck = 0.2f);}

	//Define a costum player model
	Player(const std::string theName, short theHp, unsigned short theAttack, unsigned short theDefense, float theLuck) :name(theName), hp(theHp), attack(theAttack), luck(theLuck) { }

	//Get dmg by other player
	short getHit(short Enemydmg) { return this->hp -= Enemydmg; }

	//Check if the player is dead
	bool isDead() const { return (this->hp <= 0 ? true : false); } // condition ? result_if_true : result_if_false

	//Creating getters for the attributes so we can use them
	std::string getName() const { return this->name; }
	short getHp() const { return this->hp; }
	short getAttackInfo() const { return this->attack; }
	short getDefenseInfo() const { return this->defense; }
	float getLuck() const { return this->luck; }
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