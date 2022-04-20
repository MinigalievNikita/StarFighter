#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(int velocity, int heath)
	{
		this->velocity = velocity;
		this->heath = heath;
	}
};
