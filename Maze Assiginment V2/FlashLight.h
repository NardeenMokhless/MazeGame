#pragma once
#include "PropObject.h"
class FlashLight :	public PropObject
{
public:
	FlashLight();
	FlashLight(string,string);
	bool act(player* );
};

