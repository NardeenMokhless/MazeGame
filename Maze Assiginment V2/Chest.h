#pragma once
#include "FixedObject.h"
#include "TreasureObject.h"
#include <vector>
#include<typeinfo>

static const int SizeOfChest = 5;
class Chest : public FixedObject
{
private:
	vector<Object*>ObjectsInChest;
public:
	Chest();
	Chest(string, string, PropObject*);
	bool act(player*);
	bool putIn(Object*);
	bool removeIt(Object*,player*);
	void PrintObjectsInChest();
	void addObjects(PropObject*);
};