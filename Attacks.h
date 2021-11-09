#pragma once
#include "stdafx.h"
class Attack
{
private:
	std::string Name;
	std::string Description;
	uint32_t Dmg;

public:

	Attack() 
	{
		this->Name = "Default";
		this->Description = "Default Attack";
		this->Dmg = 30;
	}

	Attack(std::string name, std::string description, uint32_t dmg) : Name(name), Description(description), Dmg(dmg) {}

	std::string get_name() { return this->Name; }
	std::string get_description() { return this->Name; }
	std::uint32_t get_dmg() { return this->Dmg; }

};