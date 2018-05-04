#pragma once
#include "Monsters.h"
class ChasedMonster :public Monsters
{
public:
	ChasedMonster();
	ChasedMonster(string, Room*, PropObject*);
	bool Act();
	string SearchForPlayer();
};