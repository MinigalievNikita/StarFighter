#pragma once
#include "Weapon.h"
#include "Bullet.h"
class Shotgun : Weapon{
public :
    Bullet shoot(sf::Vector2f position, sf::Vector2i mousePosition) {
        cout << "Im shooting pistol";
        Bullet newBullet;
        newBullet.it = 0;
        newBullet.velocity = 5;
        newBullet.r0 = position;
        newBullet.direction = position;
        newBullet.direction = sf::Vector2f(mousePosition.x, mousePosition.y) - newBullet.r0;
        newBullet.direction = sf::Vector2f(newBullet.direction.x / (sqrt (newBullet.direction.x * newBullet.direction.x + newBullet.direction.y * newBullet.direction.y)), newBullet.direction.y / (sqrt (newBullet.direction.x * newBullet.direction.x + newBullet.direction.y * newBullet.direction.y)));
        return newBullet;
    }
   void reload(int bullet) {
        cout<<"Iam reloadin shotgun";
    }
};
