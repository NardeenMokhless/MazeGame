#pragma once
/*#ifndef PLAYER_H
#define PLAYER_H*/
#include<vector>
#include "Agents.h"
class PropObject;
class RandomMonsters;
class Object;
static const int PlayerMaxSize = 10;
class player : public Agents
{
private:
	vector<PropObject*> VofPropObject;
public:
	bool Act();
	bool PickUp(PropObject*);
	bool DropDown(PropObject*);
	player(string n, Room* r);
	int searchforProp(PropObject*);
	void PrintPropWithPlayer();
	Object* getObject(int x);
	void addObject(PropObject*);
	int getSize();
	void Kill();

};
//#endif // !1