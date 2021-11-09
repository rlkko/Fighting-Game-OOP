// Revisao.cpp : This file contains the 'main' function. Program execution begins and ends there.
//By zei.

//Essential includes
#include "stdafx.h"
#include "CombatSystem.h"


int main()
{
	//PlayerModel(name , hp, attack, defense)
	CombatSystem::AddPlayer("John", 100, 50, 20);
	CombatSystem::AddDefaultPlayer();

	//Game initializes
	CombatSystem::InitLog();

	CombatSystem::StartFight();

	//Temp
	std::cin.get();
}