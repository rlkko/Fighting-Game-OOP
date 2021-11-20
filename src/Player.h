//Player.h
//Made by rikkoRicardo

#pragma once
#include "stdafx.h"
#include "Attack.h"

#define MAX_ATTACKS 4

class Player
{
private:
	std::string name = "";
	int16_t hp = 0;
	uint16_t defense = 0;
	float luck = 0;
	std::vector<Attack> AttackList;

public:
	short getRandDefense() const { return rand() % this->defense; }

	//Constructor
	Player(const std::string theName, int16_t theHp, uint16_t theDefense) :name(theName), hp(theHp), defense(theDefense) {}

	//PlayerModels
	Player(uint32_t presetNumber) 
	{
		uint16_t playerPresetLimit = 1;

		if (presetNumber > playerPresetLimit) {
			std::cout << "Invalid player Model number \n";
			return;
		}

		switch (presetNumber)
		{
		case 1:
			Player DefaultPlayer(this->name = "Default", this->hp = 100, this->defense = 30);
			AttackList.push_back(Attack(1));
			break;
		}
	}

	short getHit(uint16_t Enemydmg) { return this->hp -= Enemydmg; }
	constexpr bool isDead() const { return (this->hp <= 0 ? true : false); } // condition ? result_if_true : result_if_false

	void AddAttackTemplate(uint16_t attackPresetNum, std::string name, std::string description, uint16_t attack);
	void AddPresetAttack(uint16_t presetNumber);
	void AddAttack(std::string name, std::string description, uint16_t attack);

	Attack getNextAttack();
	
	void showPlayerAttacks();

	//Creating getters for the attributes so we can use them
	std::string getName() const { return this->name; }
	constexpr short getHp() const { return this->hp; }
	constexpr short getDefenseInfo() const { return this->defense; }
	constexpr float getLuck() const { return this->luck; }
	std::vector<Attack> getAttacks() const { return this->AttackList; }

};

//Override the Operator "<<" to be able to print out the player object
inline
std::ostream& operator<< (std::ostream& obj,Player& player) 
{
	return obj << "\nName: " << player.getName() <<
		"\nHP: " << player.getHp() <<
		"\nDefense: " << player.getDefenseInfo();
}