#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
    static float spawnPeriod; //10 sec
    static float lastSpawnTime;
    Enemy(int velocity, int heath)
    {
        this->velocity = velocity;
        this->heath = heath;
    }
};
