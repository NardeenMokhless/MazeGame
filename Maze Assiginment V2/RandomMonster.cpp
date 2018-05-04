#include "RandomMonster.h"

RandomMonster::RandomMonster():Monsters(){}
RandomMonster::RandomMonster(string n,Room* r,PropObject* p):Monsters(n,r,p){}
bool RandomMonster::Act() 
{
	Kill();
	string direction;
	string arr[4];
	int counter = 0;
	if (cur_room->getLinked("north") != NULL)
		arr[counter++] = "north";
	if (cur_room->getLinked("south") != NULL)
		arr[counter++] = "south";
	if (cur_room->getLinked("west") != NULL)
		arr[counter++] = "west";
	if (cur_room->getLinked("east") != NULL)
		arr[counter++] = "east";
	int n = rand() % (--counter);
	direction = arr[n];
	cur_room->leave(this);
	cur_room = cur_room->getLinked(direction);
	cur_room->enter(this);
	Kill();
	return true;
}