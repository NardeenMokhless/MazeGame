#include "Chest.h"

Chest::Chest():FixedObject(){}

Chest::Chest(string n, string d, PropObject *p):FixedObject(n,d,p){}

bool Chest::act(player *p)
{
	if (p->searchforProp(prop) != p->getSize())
	{
		cout << "You open the box." << endl << endl;
		for (int i = 0; i < (int)ObjectsInChest.size(); i++)
		{
			if (typeid(TreasureObject) == typeid(*ObjectsInChest[i]))
			{
				cout << "You find the treasure !!" << endl;
				cout << ObjectsInChest[i]->getDiscreption();
				cout << endl << endl << "!!! You are the winner !!!" << endl;
				exit(0);
			}
		}
		string boxChoise;
		if (ObjectsInChest.size() == 0)
		{
			cout << "The box is empty" << endl << endl;
		}
		else {
			PrintObjectsInChest();
			cout << "	>> '1' for take an object from  the box." << endl;
		}
		cout << "	>> '2' for put  an object in the box." << endl;
		cout << "	>> '3' for nothing" << endl;
		cin >> boxChoise;
		if (boxChoise == "1")
		{
			int no_object1 = 0;
			cout << "Choose the number of this object: ";
			cin >> no_object1;
			removeIt(ObjectsInChest[no_object1 - 1], p);
		}
		else if (boxChoise == "2")
		{
			int no_object2 = 0;
			p->PrintPropWithPlayer();
			cout << "Choose the number of this object: ";
			cin >> no_object2;
			putIn(p->getObject(no_object2 - 1));
		}
		return true;
	}
	return cout << "You can not open this Box" << endl << endl, false;
}
bool Chest::putIn(Object* o)
{
	if ((int)ObjectsInChest.size() < SizeOfChest)
	{
		ObjectsInChest.push_back(o);
		return cout << "The " << o->getName() << " has been put in the box." << endl << endl, true;
	}
	return cout << "The box is full." << endl << endl, false;
}
bool Chest::removeIt(Object *o, player* p)
{
	if ((int)ObjectsInChest.size() == 0) return false;
	for (int i = 0; i < (int)ObjectsInChest.size(); i++)
		if (ObjectsInChest[i] == o)
		{
			ObjectsInChest[i] = ObjectsInChest.back();
			break;
		}
	cout << "The " << o->getName() << " is out of the box." << endl << endl;
	ObjectsInChest.pop_back();
	return true;
}
void Chest::PrintObjectsInChest()
{
	cout << "Objects in the box:" << endl;
	for (int i = 0; i < ObjectsInChest.size(); i++)
	{
		cout << "	" << i + 1 << " >> " << ObjectsInChest[i]->getName()
			<< "  " << ObjectsInChest[i]->getDiscreption() << endl;
	}
	cout << endl;
}

void Chest::addObjects(PropObject* p)
{
	ObjectsInChest.push_back(p);
}