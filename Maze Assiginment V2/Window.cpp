#include "Window.h"

Window::Window():FixedObject(){}
Window::Window(string n,string d):FixedObject(n,d){}
bool Window::act(player* p)
{
	return cout << "Window is Opened " << endl,true;
}