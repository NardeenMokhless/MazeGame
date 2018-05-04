#pragma once
#include"Agents.h"
#include"ChasedMonster.h"
#include"Chest.h"
#include"Door.h"
#include"FixedObject.h"
#include"FlashLight.h"
#include"Game.h"
#include"Gun.h"
#include"Key.h"
#include"Monsters.h"
#include"Object.h"
#include"player.h"
#include"PropObject.h"
#include"RandomMonster.h"
#include"Room.h"
#include"TreasureObject.h"
#include"Window.h"
class Game
{
private:
	vector<Agents*> Agent;
public:
	Game(vector<Agents*>);
	void fun ();
	void ShiftAgents();
	void EraseAgent();
	string CheckForWinner();
};

