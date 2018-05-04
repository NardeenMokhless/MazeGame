#pragma once
/*#ifndef OBJECT_H
#define OBJECT_H*/
#include<string>
#include<iostream>
#include "player.h"
using namespace std;
class Object
{
protected:
	string name;
	string discreption;
public:
	Object();
	Object(string, string);
	virtual bool act(player*)=0;
	string getName();
	string getDiscreption();
};
//#endif // !OBJECT_H