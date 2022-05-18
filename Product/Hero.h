#pragma once
#include "Character.h"
#include <SFML/Graphics.hpp>

class Hero : public Character
{
public:
    Hero(int velocity, int heath)
        {
            this->velocity = velocity;
            this->heath = heath;
        }
};



Hero createHero(sf::Texture &heroTexture){
    Hero hero(5,5);
    hero.setScale(0.25f, 0.25f);
    hero.radius = (heroTexture.getSize().x)/2;
    hero.setOrigin(hero.radius, hero.radius);
    hero.radius = (heroTexture.getSize().x * 0.25)/2;
    hero.velocity = 10;
    hero.setTexture(heroTexture);
    hero.setPosition(1000, 850);
    return hero;
}
