#include "Key.h"



Key::Key():PropObject(){}
Key::Key(string n, string d):PropObject(n,d){}

bool Key::act(player* p)
{
	return true;
}