#include "ChasedMonster.h"
#include "Room.h"
ChasedMonster::ChasedMonster() :Monsters() {}
ChasedMonster::ChasedMonster(string n,Room* r,PropObject* p):Monsters(n,r,p){}
bool ChasedMonster::Act() {
	Kill();
	string direc = SearchForPlayer();
	cur_room->leave(this);
	cur_room = cur_room->getLinked(direc);
	cur_room->enter(this);
	Kill();
	return true;
}
string ChasedMonster::SearchForPlayer()
{
	int leastMap = 10000;
	string direc;
	if (cur_room->getLinked("north") != NULL)
	{
//		cout << ((cur_room->getLinked("north"))->getMap()) << endl;
		leastMap = ((cur_room->getLinked("north"))->getMap());
		direc = "north";
	}
	if (cur_room->getLinked("south") != NULL)
	{
//		cout << ((cur_room->getLinked("south"))->getMap()) << endl;
		if (leastMap >= (cur_room->getLinked("south"))->getMap()) {
			leastMap = cur_room->getLinked("south")->getMap();
			direc = "south";
		}
	}
	if (cur_room->getLinked("east") != NULL)
	{
//		cout << ((cur_room->getLinked("east"))->getMap()) << endl;
			if (leastMap >= (cur_room->getLinked("east"))->getMap()) {
			leastMap = cur_room->getLinked("east")->getMap();
			direc = "east";
			}
	}
	if (cur_room->getLinked("west") != NULL)
	{
//		cout << ((cur_room->getLinked("west"))->getMap()) << endl;
		if (leastMap >= (cur_room->getLinked("west"))->getMap()) {
			leastMap = cur_room->getLinked("west")->getMap();
			direc = "west";
		}
	}
	return direc;
}
/*string ChasedMonster::SearchForPlaayer() {
	cout << "C1" << endl;
	int leastMap = 10000;
	string direc;
	if (cur_room->getLinked("north") != NULL)
	{
		leastMap = cur_room->getLinked("north")->getMap();
		cout << "C1" << endl;
		direc = "north";
	}
	if (cur_room->getLinked("south") != NULL)
	{
		if (leastMap > (cur_room->getLinked("south"))->getMap()) {
			leastMap = cur_room->getLinked("south")->getMap();
			direc = "south";
		}
	}
	if (cur_room->getLinked("east") != NULL)
	{
		if (leastMap > (cur_room->getLinked("east"))->getMap()) {
			leastMap = cur_room->getLinked("east")->getMap();
			direc = "east";
		}
	}
	if (cur_room->getLinked("west") != NULL)
	{
		if (leastMap > (cur_room->getLinked("west"))->getMap()) {
			leastMap = cur_room->getLinked("west")->getMap();
			direc = "west";
		}
	}
	return direc;
}*/