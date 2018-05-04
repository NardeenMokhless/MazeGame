#include "Door.h"

Door::Door():FixedObject(){}

Door::Door(string n, string d, PropObject* p):FixedObject(n,d,p){}

bool Door::act(player* p)
{
	if (p->searchforProp(prop))
		return cout << "You opened this door" << endl, true;
	return cout << "You can not open this door" << endl, false;
}

void Door::SetPropKey(PropObject* p)
{
	prop = p;
}
