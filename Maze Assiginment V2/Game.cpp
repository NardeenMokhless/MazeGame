#include "Game.h"
Game::Game(vector<Agents*> a) {
	for (int i = 0; i < a.size(); i++)
		Agent.push_back(a[i]);
}
void Game::fun () {
	string x;
	while (true) {
		for (int i = 0; i < Agent.size(); i++) {
			ShiftAgents();
			x = CheckForWinner();
			if (x != "NONE")
				cout << "\a\a\a\n\n!!!!! " << x << " is winner !!!!!!\a\a\a" << endl, exit(0);
			bool ok = Agent[i]->Act();
			if (x != "NONE")
				cout << "\a\a\a\n\n!!!!! " << x << " is winner !!!!!!\a\a\a" << endl, exit(0);
			ShiftAgents();
			if (!ok) {
				cout << endl << "!!! The other player wins !!!" << endl << endl;
				exit(0);
			}
		}
	}
}
void Game::ShiftAgents() {
	for (int i = 0; i < Agent.size(); i++)
	{
		if (Agent[i]->GetLife() == false)
			Agent[i] = NULL;
	}
	EraseAgent();
}
void Game::EraseAgent() {
	for (int i = 0; i<Agent.size(); i++)
		if (Agent[i] == NULL)
			Agent.erase(Agent.begin()+i);
}
string Game::CheckForWinner() {
	int count = 0;
	string x;
	for (int i = 0; i < Agent.size(); i++)
		if (typeid(*Agent[i]) == typeid(player))
			count++,x=Agent[i]->getname();
	if (count == 1)
		return x;
	else return "NONE";
}

