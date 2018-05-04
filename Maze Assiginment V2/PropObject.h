#pragma once
/*#ifndef PROPOBJECT_H
#define PROPOBJECT_H*/
#include "Object.h"
#include "player.h"
class PropObject : public Object
{
public:
	PropObject();
	PropObject(string n, string d);
	virtual bool act(player* p)=0;
//	void pickUp(player *);
//	void dropdown(player *);
};
//#endif // !PROPOBJECT_H


