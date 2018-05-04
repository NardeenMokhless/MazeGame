#include "player.h"
#include "PropObject.h"
#include "Monsters.h"
#include "Door.h"
player::player(string n, Room* r) :Agents(n, r) { 
	int a = 0; 
	cur_room->PutMap(cur_room, a);
}
bool player::Act()
{
	Kill();
	string direc, choice, TakeObject;
	cout << "Hi " << name << "," << endl;
	cout << "You are in the " << cur_room->getName() << " now." << endl;
	cout << cur_room->getDescription() << endl << endl;
	if (cur_room->GetSizeOfObjects())
	{
		cur_room->PrintObjects();
		cout << "1->  '1'   for using Object from room" << endl;
		cout << "2-> 'else' for nothing " << endl << endl;
		cout << "Your choice: ";
		cin >> choice;
		cout << endl;
		if (choice == "1") {
			cout << "Please choose a name of your object you want to use it: ";
			cin >> TakeObject;
			cout << endl;
			int x = cur_room->TakeObject(TakeObject);
			if (x == cur_room->GetSizeOfObjects())
				cout << "This Object is not found in the room !!" << endl << endl;
			else {
				(cur_room->GetObject(x))->act(this);
			}
		}
		else cout << "You choose nothing." << endl << endl;
	}
	if (cur_room->getsize() == 1)
		cout << endl << "You see no other creatures here." << endl << endl;
	else {
		cur_room->printOccupants();
	}
	cur_room->printLinked();
	cout << ">>>>Which exit? (or 'quit'): ";
	cin >> direc;
	transform(direc.begin(), direc.end(), direc.begin(), ::tolower);
	if (direc == "quit")
		return false;
	else if (cur_room->getLinked(direc) != NULL && cur_room->getLinked(direc)->getsize() < 6)
	{
		int a = 0;
		if ((cur_room->getDoorLinked(direc))->act(this)) {
			cur_room->leave(this);
			cur_room = cur_room->getLinked(direc);
			cur_room->enter(this);
			cur_room->PutMap(cur_room, a);
		}
	}
	else
		cout << ">>>There is No Rooms there or that room is full !!!! " << endl << endl;
	Kill();
	cout << "------------------------------------------------------------------------------" << endl;
	return true;
}
bool player::PickUp(PropObject *p)
{
	if (VofPropObject.size() < PlayerMaxSize) {
		VofPropObject.push_back(p);
		return cout << "You pick it up. ", true;
	}
	return cout << "You can not pick it up. ",false;
}

bool player::DropDown(PropObject *p)
{
	if (VofPropObject.size() != 0) {
		int x = 0;
		for (int i = 0; i < (int)VofPropObject.size(); i++)
		{
			if (p == VofPropObject[i]) { x = i; break; }
		}
		VofPropObject[x] = VofPropObject.back();
		VofPropObject.pop_back();
		return true;
	}
	return false;
}

int player::searchforProp(PropObject* p){
	for (int i = 0; i < (int)VofPropObject.size(); i++)
		if (p == VofPropObject[i])
			return i;
	return VofPropObject.size();
}
void player::PrintPropWithPlayer() {
	cout << "Properties you have : \n";
	for (int i = 0; i < (int)VofPropObject.size(); i++)
		cout << " " << i + 1 << " >> " << VofPropObject[i]->getName()
		<< " " << VofPropObject[i]->getDiscreption() << endl;
}
Object* player::getObject(int x) {
	return (VofPropObject[x]);
}
void player::addObject(PropObject* p) {
	VofPropObject.push_back(p);
}
int player::getSize() {
	return VofPropObject.size();
}
void player::Kill() {
	Agents* a = cur_room->MonsterFind();
	while (a != NULL && a->GetLife() && Life) {
			if (searchforProp((dynamic_cast<Monsters*>(a)->getWeapons())) == getSize())
		{
			Life = false;
			cout << endl << endl << name << " is killed." << endl;
		}
		else
		{
			a->setLife(false);
			cout << endl << endl << a->getname() << " is killed." << endl;
		}
		a = cur_room->MonsterFind();
	}
}