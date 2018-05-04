#pragma once
/*#ifndef ROOM_H
#define ROOM_H*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
static const int maxsize = 5;
class Agents;
class Object;
class Door;
class player;
class Room
{
private:
	string name;
	string description;
	int size;
	int Map;
	Agents* occupants[maxsize];
	Room* north;
	Room* south;
	Room* west;
	Room* east;
	Door* NorthDoor;
	Door* SouthDoor;
	Door* EastDoor;
	Door* WestDoor;
	vector<Object*>ObjectInRoom;
public:
	Room();
	void copyRoom(const Room*);
	Room(string);
	Room(string, string);
	Room(string, string, vector<Object*>);
	string getName();
	int getsize();
	string getDescription();
	void link(Room *, string,Door*);
	Room* getLinked(string);
	void printLinked();
	void enter(Agents*);
	void leave(Agents*);
	void printOccupants();
	bool CheckPlayer();
	void PrintObjects();
	void AddObject(Object*);
	void EraseObject(Object*);
	int TakeObject(string);
	int DropObject(string);
	int GetSizeOfObjects();
	Object* GetObject(int);
	Door* getDoorLinked(string dir);
	void PutMap(Room*,int);
	int getMap();
	Agents* PlayerFind();//new
	Agents* MonsterFind();
//	string GetleastMap();
};
//#endif 