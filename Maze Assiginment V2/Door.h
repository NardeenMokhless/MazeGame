#pragma once
#include "FixedObject.h"

class Door : public FixedObject
{

public:
	Door();
	Door(string, string, PropObject*);
	bool act(player* p);
	void SetPropKey(PropObject*);
};