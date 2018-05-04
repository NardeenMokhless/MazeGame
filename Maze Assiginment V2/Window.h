#pragma once
#include "FixedObject.h"
class Window : public FixedObject
{
public:
	Window();
	Window(string, string);
	bool act(player*);
};

