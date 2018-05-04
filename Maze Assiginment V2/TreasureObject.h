#pragma once
#include "PropObject.h"
class TreasureObject : public PropObject
{
public:
	TreasureObject();
	TreasureObject(string, string);
	bool act(player*);
};
