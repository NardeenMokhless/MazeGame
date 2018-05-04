#include "Agents.h"

Agents::Agents()
{
	name = "NONE";
	Life = true;//new
	cur_room = NULL;
}
Agents::Agents(string n,Room* r)
{
	name = n;
	Life = true;//new
	cur_room = r;

	cur_room->enter(this);
}
string Agents::getname()
{
	return name;
}
bool Agents::GetLife() {
	return Life;
}
void Agents::setLife(bool b) {
	Life = b;
}