#pragma once
#include "Vector2.h"
#include <SFML/Graphics.hpp>

struct Bullet {
    float size;
    float velocity;
    float it;
    sf::Vector2f r0;
    sf::Vector2f direction;
    Bullet(){};
    Bullet(float size, float velocity){
        this->size = size;
        this->velocity = velocity;
    }
};
