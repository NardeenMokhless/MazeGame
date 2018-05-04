#pragma once
#include "PropObject.h"
class Gun :	public PropObject
{
public:
	Gun();
	Gun(string, string);
	bool act(player*);
};

