#include<iostream>
#include "Game.h"
#include<time.h>
//using namespace std;
int main()
{
	srand(time(NULL));

	//Main 5 Rooms
	Room *Living_room, *kitchen, *library, *garden, *bedroom;

	//keys of doors
	Key K1("Key 1", "to open door 1"), K2("Key 2", "to open door 2"),
		K3("Key 3", "to oper door 3"), K4("Key 4", "to open door 4"),
		K5("Key 5", "to open door 5"), K6("Key 6", "to open door 6"),
		K7("Ker 7", "to open door 7"), K8("Key 8", "to open door 8");

	//key of boxes
	Key CH1("key 1", "to the living room box."), CH2("key 2", "to the garden box."),
		CH3("key 3", "to the kitchen box."), CH4("key 4", "to the library box."),
		CH5("key 5", "to the bedroom box.");

	//doors for rooms
	Door D1("Door 1", "to enter the room", &K1), D2("Door 2", "to enter the room", &K2),
		D3("Door 3", "to enter the room", &K3), D4("Door 4", "to enter the room", &K4),
		D5("Door 5", "to enter the room", &K5), D6("Door 6", "to enter the room", &K6),
		D7("Door 7", "to enter the room", &K7), D8("Door 8", "to enter the room", &K8);

	//boxes for rooms
	Chest Chest1("Box1", " for the living room", &CH1);
	Chest Chest2("Box2", " for the garden", &CH2);
	Chest Chest3("Box3", " for the kitchen", &CH3);
	Chest Chest4("Box4", " for the library", &CH4);
	Chest Chest5("Box5", " for the bedroom", &CH5);

	//windows for rooms
	Window w1("Window", "in the living room"), w3("Window", "in the kitchen"),
		w4("Window", "in the library"), w5("Window", "in the bedroom");

	//vectors of the fixed objects inside the room
	vector<Object*>LR, KT, Gd, Bd, LB;
	LR.push_back(&Chest1);        Gd.push_back(&Chest2);
	LR.push_back(&w1);

	KT.push_back(&Chest3);        LB.push_back(&Chest4);
	KT.push_back(&w3);            LB.push_back(&w4);

	Bd.push_back(&Chest5);
	Bd.push_back(&w5);

	//Full the 5 Rooms
	Living_room = new Room("Living Room", "There are chairs,table,tv,vase,carpet and lamps.", LR),
		kitchen = new Room("Kitchen", "There are a cooker,spoons,knives, pots and refrigerator.", KT),
		library = new Room("Library", "There are a lot of books everywhere of all fields. ", LB),
		garden = new Room("Garden", "There are trees,plants,flowers,grass and swimming pool.", Gd),
		bedroom = new Room("Bedroom", "There are a bed,a desk and a blanket.", Bd);

	//Rooms links
	Living_room->link(garden, "North", &D1);        kitchen->link(garden, "North", &D2);
	Living_room->link(library, "South", &D6);       kitchen->link(Living_room, "West", &D5);
	Living_room->link(bedroom, "West", &D4);       kitchen->link(library, "South", &D8);
	Living_room->link(kitchen, "East", &D5);

	bedroom->link(Living_room, "East", &D4);        garden->link(Living_room, "South", &D1);
	bedroom->link(garden, "North", &D3);           garden->link(bedroom, "West", &D3);
	bedroom->link(library, "South", &D7);          garden->link(kitchen, "East", &D2);

	library->link(Living_room, "North", &D6);
	library->link(kitchen, "East", &D8);
	library->link(bedroom, "West", &D7);

	//weapons for killing the monsters
	Gun gun("Gun", "for killing the monster");
	FlashLight flashLight("Flash light", "for killing the monster");

	//treasure for the winner
	TreasureObject t("Treasure","There are a lot of gold and jewelleries."); 

	//2 players and 2 monsters
	Monsters* monster1 = new RandomMonster("Dracula", library, &flashLight);
	Monsters* monster2 = new ChasedMonster("Vampire", library, &gun);
	player* player1 = new player("Player 1", garden);
	player* player2 = new player("Player 2", bedroom);


	//adding prop for both players
	player1->addObject(&CH2);          player2->addObject(&CH2);
	player1->addObject(&K2);           player2->addObject(&K4);
	player1->addObject(&K3);           player2->addObject(&K7);
	player1->addObject(&CH3);          player2->addObject(&CH4);
	player1->addObject(&CH5);          player2->addObject(&CH1);
	player1->addObject(&flashLight);   player2->addObject(&gun);

	//filling the boxes in the rooms
	Chest2.addObjects(&K1);            Chest5.addObjects(&CH2);
	Chest2.addObjects(&CH1);           Chest5.addObjects(&CH3);
	Chest2.addObjects(&t);             Chest5.addObjects(&K3);

	Chest1.addObjects(&K5);            Chest4.addObjects(&CH3);
	Chest1.addObjects(&K6);            Chest4.addObjects(&CH5);
	Chest1.addObjects(&CH4);           Chest4.addObjects(&K8);
	  
	Chest3.addObjects(&K5);             
	Chest3.addObjects(&K1);           
	Chest3.addObjects(&CH4);           

	//agents vector
	vector<Agents*>agents(4);  
	agents[0] = player1;
	agents[1] = player2;
	agents[2] = monster1;
	agents[3] = monster2;     

	//start game
	Game g(agents);
	g.fun();

	//deleting 
	delete kitchen, garden, library, bedroom, monster1, player1, player2, monster2, LR, KT, Gd, Bd, LB, agents;
	return 0;
}