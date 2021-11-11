#pragma once
#include "stdafx.h"
#include "Attack.h"

static uint16_t number = 0;

class Player
{
private:
	uint16_t number = number;
	std::string name;
	int16_t hp;
	uint16_t defense = 0;
	float luck = 0;
	std::vector<Attack> AttackList;

public:
	short getRandDefense() const { return rand() % this->defense; }

	//Constructor
	Player(const std::string theName, int16_t theHp, uint16_t theDefense, float theLuck) :name(theName), hp(theHp), defense(theDefense), luck(theLuck) { number++; }

	//PlayerModels
	Player(uint32_t presetNumber) {

		uint16_t playerPresetLimit = 1;

		if (presetNumber > playerPresetLimit) {
			std::cout << "Invalid player Model number \n";
			return;
		}

		switch (presetNumber)
		{
		case 1:
			Player DefaultPlayer(this->name = "Default", this->hp = 100, this->defense = 30, this->luck = 0.2f);
			break;
		}//doing a default case would break the initialization

	}

	short getHit(uint16_t Enemydmg) { return this->hp -= Enemydmg; }

	constexpr bool isDead() const { return (this->hp <= 0 ? true : false); } // condition ? result_if_true : result_if_false

	//Creating getters for the attributes so we can use them
	std::string getName() { return this->name; }
	constexpr short getHp() { return this->hp; }
	constexpr short getDefenseInfo() { return this->defense; }
	constexpr float getLuck() { return this->luck; }
	
	void AddAttack(std::string name,std::string description,uint32_t attack) {
		AttackList.push_back(Attack(name, description, attack));
	}

	void getPlayerAttacks() {
		if (AttackList.empty()) {
			//Attack one is the default Attack
			this->AttackList.push_back(Attack(1));
		}

		for (Attack& attack : AttackList) {
			std::cout << attack << '\n';
		}
	}

};

//Override the Operator "<<" to be able to print out the player object
inline
std::ostream& operator<< (std::ostream& obj,Player& player) {
	return obj << "Name: " << player.getName() <<
				"\nHP: " << player.getHp() <<
				"\nDefense: " << player.getDefenseInfo() <<
				"\nLuck: " << player.getLuck() * 100 << '\n';
}