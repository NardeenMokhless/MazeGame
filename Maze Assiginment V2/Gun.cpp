#include "Gun.h"



Gun::Gun() :PropObject() {}
Gun::Gun(string n, string d) : PropObject(n, d) {}

bool Gun::act(player* p)
{
	return true;
}
