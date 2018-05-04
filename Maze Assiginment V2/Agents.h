#pragma once
/*#ifndef AGENT_H
#define AGENT_H*/
#include"Room.h"
class Agents
{
protected:
	Room* cur_room;
	string name;
	bool Life;//new
public:
	Agents();
	Agents(string,Room*);
	virtual bool Act() = 0;
	string getname();
	bool GetLife();
	void setLife(bool);
};
//#endif // !1