#pragma once
/*#ifndef RANDOMMONSTERS_H
#define RANDOMMONSTERS_H*/
#include "Monsters.h"
class RandomMonster :public Monsters
{
public:
	RandomMonster();
	RandomMonster(string, Room*, PropObject*);
	bool Act();
};
//#endif // !RANDOMMONSTERS_H

