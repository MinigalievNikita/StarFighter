#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

class Character : public sf::Sprite{
public:
    float velocity;
    sf::Vector2f r0;
    int heath;
    int size;
    int radius;
};
