#include "Agents.h"
#include "ChasedMonster.h"
#include "RandomMonster.h"
#include"Object.h"
// constractors ;

Room::Room() // default constractor.
{
	size = 0;
	name = "NONE";
	description = "NONE";
	Map = INT_MAX-10;
	west = east = south = north = NULL;
	NorthDoor = SouthDoor = WestDoor = EastDoor = NULL;
}
// constarctor to take name only.
Room::Room(string nm)
{
	size = 0;
	name = nm;
	Map = INT_MAX-10;
	description = "NONE";
	west = east = south = north = NULL;
	NorthDoor = SouthDoor = WestDoor = EastDoor = NULL;
}
// constarctor to take name and Description.
Room::Room(string nm, string ds)
{
	size = 0;
	name = nm;
	Map = INT_MAX-10;
	description = ds;
	west = east = south = north = NULL;
	NorthDoor = SouthDoor = WestDoor = EastDoor = NULL;
}
Room::Room(string n, string d, vector<Object*> O):Room(n,d) {
	for (int i = 0; i < O.size(); i++)
		ObjectInRoom.push_back(O[i]);
}
// copy function for room
void Room::copyRoom(const Room *r)
{
	size = r->size;
	name = r->name;
	Map = r->Map;
	description = r->description;
	north = r->north;
	south = r->south;
	east = r->east;
	west = r->west;
	NorthDoor = r->NorthDoor; 
	SouthDoor = r->SouthDoor; 
	WestDoor = r->WestDoor; 
	EastDoor = r->WestDoor;
	//	delete r;
}
// name getter 
string Room::getName()
{
	return name;
}
// Desciption getter 
string Room::getDescription()
{
	return description;
}
// make link between 2 rooms
void Room::link(Room *r, string dir,Door* d)
{
	transform(dir.begin(), dir.end(), dir.begin(), ::tolower);
	if (dir == "north") {
		north = r;
		NorthDoor = d;
	}
	if (dir == "south") {
		south = r;
		SouthDoor = d;
	}
	if (dir == "east") {
		east = r;
		EastDoor = d;
	}
	if (dir == "west") {
		west = r;
		WestDoor = d;
	}
}
// return room that connected in some direction to calling room 
Room* Room::getLinked(string dir)
{
	transform(dir.begin(), dir.end(), dir.begin(), ::tolower);
	if (dir == "north")	return  north;
	if (dir == "south")	return  south;
	if (dir == "east")	return  east;
	if (dir == "west")	return  west;
	return NULL;
}
// print all rooms that connected to this room 
void Room::printLinked()
{
	cout << "You are in the : " << name << ", There is an exit to: " << endl;
	if (north != NULL)
		cout << "	>>North : " << north->name << endl;
	if (east != NULL)
		cout << "	>>East  : " << east->name << endl;
	if (west != NULL)
		cout << "	>>West  : " << west->name << endl;
	if (south != NULL)
		cout << "	>>South : " << south->name << endl;
	cout << endl;
}
void Room::enter(Agents *a)
{
	occupants[size++] = a;
}
void Room::leave(Agents *a)
{
	for (int i = 0; i < size; i++)
		if ((occupants[i]) == a && i != size - 1)
		{
			occupants[i] = occupants[size - 1];
			occupants[size - 1] = NULL;
			break;
		}
		else if (occupants[i] == a) {
			occupants[i] = NULL;
		}
		size--;
}
void Room::printOccupants()
{
		cout << " Occupants in the " <<name<< endl;
		for (int i = 0; i < size; i++) {
			if (occupants[i]->GetLife())
				cout <<"   "<<i+1<<" - "<< occupants[i]->getname() << endl;
		}
}
int Room::getsize() { 
	return size; 
}
bool Room::CheckPlayer(){
	for (int i = 0; i < size; i++)
		if (typeid(*occupants[i]) == typeid(player))
			return true;
	return false;
}
void Room::PrintObjects() {
	cout << "Objects in this Room : \n";
	for (int i = 0; i < (int)ObjectInRoom.size(); i++)
	{
		cout << "	>>" << ObjectInRoom[i]->getName()
			<< "  " << ObjectInRoom[i]->getDiscreption() << endl;
	}
	cout << endl;
}
void Room::AddObject(Object* O) {
	ObjectInRoom.push_back(O);
}
void Room::EraseObject(Object* O) {
	for (int i = 0; i < (int)ObjectInRoom.size();i++)
		if (ObjectInRoom[i] == O) {
			ObjectInRoom[i] = ObjectInRoom.back();
		}
	ObjectInRoom.pop_back();
}
int Room::TakeObject(string s) {
	transform(s.begin(), s.end(),s.begin(), ::tolower);
	string x;
	for (int i = 0; i < ObjectInRoom.size(); i++) {
		x = ObjectInRoom[i]->getName();
		transform(x.begin(), x.end(), x.begin(), ::tolower);
		if (x == s)
			return i;
	}
	return ObjectInRoom.size();
}
int Room::GetSizeOfObjects()
{
	return ObjectInRoom.size();
}
int Room::DropObject(string s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	string x;
	for (int i = 0; i < ObjectInRoom.size(); i++) {
		x = ObjectInRoom[i]->getName();
		transform(x.begin(), x.end(), x.begin(), ::tolower);
		if (x == s)
			return i;
	}
	return ObjectInRoom.size();
}
Object* Room::GetObject(int index){
	return ObjectInRoom[index];
}
Door* Room::getDoorLinked(string dir)
{
	transform(dir.begin(), dir.end(), dir.begin(), ::tolower);
	if (dir == "north")	return  NorthDoor;
	if (dir == "south")	return  SouthDoor;
	if (dir == "east")	return  EastDoor;
	if (dir == "west")	return  WestDoor;
	return NULL;
}
void Room::PutMap(Room* rd, int a) {
	rd->Map = min(rd->Map, a);
	if (rd->north != NULL && a <= rd->Map)
		rd->north->PutMap(rd->north, a + 1);
	if (rd->south != NULL&& a <= rd->Map)
		rd->south->PutMap(rd->south, a + 1);
	if (rd->east != NULL&& a <= rd->Map)
		rd->east->PutMap(rd->east, a + 1);
	if (rd->west != NULL&& a <= rd->Map)
		rd->west->PutMap(rd->west, a + 1);
}
int Room::getMap() {
	return Map;
}
Agents* Room::PlayerFind() {
	for (int i = 0; i < size; i++)
		if ((typeid(*occupants[i]) == typeid(player)) && occupants[i]->GetLife())
		{
			return (occupants[i]);
			cout << i << endl;
		}
	return NULL;
}
Agents* Room::MonsterFind() {
	for (int i = 0; i < size; i++)
		if ((typeid(*occupants[i]) == typeid(RandomMonster) || 
			(typeid(*occupants[i]) == typeid(ChasedMonster)))&& occupants[i]->GetLife())
		{
			return (occupants[i]);
			cout << i << endl;
		}
	return NULL;
}