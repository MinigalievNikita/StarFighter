#pragma once
#include "Weapon.h"
#include "Bullet.h"
#include <math.h>
#include <SFML/Graphics.hpp>

class Pistol : public Weapon{
public :
    float delayShoot = 200; //mili sec
    float timeLastShoot = 0;
    vector<Bullet> shoot(sf::Vector2f position, sf::Vector2i mousePosition) {
        cout << "Im shooting pistol";
        vector<Bullet> bullet;
        Bullet newBullet;
        newBullet.it = 0;
        newBullet.size = 100;
        newBullet.velocity = 10;
        newBullet.r0 = position;
        newBullet.direction = position;
        newBullet.direction = sf::Vector2f(mousePosition.x, mousePosition.y) - newBullet.r0;
        newBullet.direction = sf::Vector2f(newBullet.direction.x / (sqrt (newBullet.direction.x * newBullet.direction.x + newBullet.direction.y * newBullet.direction.y)), newBullet.direction.y / (sqrt (newBullet.direction.x * newBullet.direction.x + newBullet.direction.y * newBullet.direction.y)));
        bullet.push_back(newBullet);
        return bullet;
    }
    
    void reload(int bullet) {
        cout<<"Iam reloadin pistol";
    }
};

