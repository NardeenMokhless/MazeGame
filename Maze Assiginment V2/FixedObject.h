#pragma once
/*#ifndef FIXEDOBJECT_H
#define FIXEDOBJECT_H*/
#include "Object.h"
#include "PropObject.h"
class FixedObject :	public Object
{
protected:
	PropObject* prop;
public:
	FixedObject();
	FixedObject(string, string);
	FixedObject(string, string,PropObject*);
	virtual bool act(player* p)=0;
	PropObject* getProp();
};
//#endif // !FIXEDOBJECT_H
