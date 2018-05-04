#include "FlashLight.h"



FlashLight::FlashLight() :PropObject() {}
FlashLight::FlashLight(string n, string d) : PropObject(n, d) {}

bool FlashLight::act(player* p)
{
	return true;
}