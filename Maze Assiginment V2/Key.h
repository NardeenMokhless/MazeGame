#pragma once
#include "PropObject.h"
class Key : public PropObject
{

public:
	Key();
	Key(string n, string d);
	bool act(player* );
};


