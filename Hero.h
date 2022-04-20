#pragma once
#include "Character.h"

class Hero : public Character
{
public:
	Hero(int velocity, int heath)
	{
		this->velocity = velocity;
		this->heath = heath;
	}
};
