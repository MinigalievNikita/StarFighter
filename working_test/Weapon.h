#pragma once
#include <iostream>
#include "Bullet.h"
#include "vector"
using namespace std;

class Weapon{
public:
    vector<Bullet> shoot();
    void  reload();
};
