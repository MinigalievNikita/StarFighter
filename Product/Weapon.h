#pragma once
#include <iostream>
#include "Bullet.h"
#include "vector"
#include "MusicPlayer.h"
using namespace std;

class Weapon{
public:
    vector<Bullet> shoot();
    void  reload();
    int numberOfBullets;
};
