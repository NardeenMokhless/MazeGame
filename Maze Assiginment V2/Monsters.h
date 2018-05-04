#pragma once
#ifndef MONSTERS_H
#define MONSTERS_H
#include "Agents.h"
#include "PropObject.h"
class Monsters :public Agents
{
protected:
	PropObject* Weapons;
public:
	Monsters();
	Monsters(string, Room *,PropObject*);
	virtual bool Act()=0;
	PropObject* getWeapons();
	void Kill();
};

#endif // !MONSTERS_H
