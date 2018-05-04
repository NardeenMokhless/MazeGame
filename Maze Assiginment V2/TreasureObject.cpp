#include "TreasureObject.h"

TreasureObject::TreasureObject():PropObject() {}
TreasureObject::TreasureObject(string n, string d) :PropObject(n, d) {}

bool TreasureObject::act(player* p)
{
	return true;
}