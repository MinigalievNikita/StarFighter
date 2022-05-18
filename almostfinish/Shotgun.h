#pragma once
#include "Weapon.h"
#include "Bullet.h"
#include <math.h>
const float Pi = 3.1415;
class Shotgun : Weapon{
public :
    float delayShoot = 1000; //mili sec
    float timeLastShoot = 0;
    vector<Bullet> shoot(sf::Vector2f position, sf::Vector2i mousePosition) {
        cout << "Im shooting shotgun";
        vector<Bullet> bullets;
        float angle = Pi/6;
        Bullet newBullet;
        newBullet.it = 0;
        newBullet.size = 100;
        newBullet.velocity = 10;
        newBullet.r0 = position;
        newBullet.direction = position;
        newBullet.direction = sf::Vector2f(mousePosition.x, mousePosition.y) - newBullet.r0;
        newBullet.direction = sf::Vector2f(newBullet.direction.x / (sqrt (newBullet.direction.x * newBullet.direction.x + newBullet.direction.y * newBullet.direction.y)), newBullet.direction.y / (sqrt (newBullet.direction.x * newBullet.direction.x + newBullet.direction.y * newBullet.direction.y)));
        bullets.push_back(newBullet);
        newBullet.direction = sf::Vector2f(newBullet.direction.x * cosf(angle) - newBullet.direction.y * sinf(angle), newBullet.direction.y * cosf(angle) + newBullet.direction.x * sinf(angle));
        bullets.push_back(newBullet);
        newBullet.direction = sf::Vector2f(newBullet.direction.x * cosf(-2*angle) - newBullet.direction.y * sinf(-2*angle), newBullet.direction.y * cosf(-2*angle) + newBullet.direction.x * sinf(-2*angle));
        bullets.push_back(newBullet);
        return bullets;
    }
   void reload(int bullet) {
        cout<<"Iam reloadin shotgun";
    }
};




