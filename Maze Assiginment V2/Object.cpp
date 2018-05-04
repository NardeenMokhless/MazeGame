#include "Object.h"

Object::Object(){
	name = "NONE";
	discreption = "NONE";
}
Object::Object(string n, string d){
	name = n;
	discreption = d;
}
string Object::getName(){
	return name;
}
string Object::getDiscreption() {
	return discreption;
}

