#include "Monsters.h"
Monsters::Monsters() :Agents() { Weapons = NULL; }
Monsters::Monsters(string n, Room* r, PropObject* p) : Agents(n, r) {
	Weapons = p;
}
PropObject* Monsters::getWeapons() {
	return Weapons;
}
void Monsters::Kill() {
	Agents* a = cur_room->PlayerFind();
	while (a != NULL && a->GetLife() && Life) {
			if (dynamic_cast<player*>(a)->searchforProp(Weapons) ==
			dynamic_cast<player*>(a)->getSize()) {
			a->setLife(false);
			cout << a->getname() << " is killed" << endl;
		}
		else {
			Life = false;
			cout << name << " is killed" << endl;
		}
	}
}

