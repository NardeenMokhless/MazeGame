#include "FixedObject.h"
#include "player.h"

FixedObject::FixedObject():Object(){
	prop = NULL;
}
FixedObject::FixedObject(string n,string d):Object(n,d)
{
	prop = NULL;
}
FixedObject::FixedObject(string n, string d,PropObject* p) : Object(n, d)
{
	prop = p;
}
PropObject* FixedObject::getProp(){
	return prop;
}
