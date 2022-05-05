#pragma once
#include "Character.h"
#include "Object.h"
#include "Bullet.h"
class Enemy : public Character
{
public:
    
    static int count;
    static float spawnPeriod; //10 sec
    static float lastSpawnTime;
    vector<Bullet> Bullets;
    int it_Bullets = 0;
    Enemy(int velocity, int heath)
    {
        this->velocity = velocity;
        this->heath = heath;
    }
    Pistol pistol;
    void shoot(sf::Vector2f heroPosition, float curentTime){
        if(curentTime - pistol.timeLastShoot > pistol.delayShoot){
            pistol.timeLastShoot = curentTime;
            it_Bullets++;
            sf::Vector2f enemyPosition = getPosition();
            Bullets.push_back(pistol.shoot(enemyPosition,(sf::Vector2i)heroPosition));
        }
    }
};


Enemy createEnemy(Objects structeres, int iterator){
    sf::Texture enemyTexture;
    if(!enemyTexture.loadFromFile("SpaceFighter.png")){
        cout << "Cant load hero";
    }
    Enemy enemy(0,3);
    enemy.setScale(0.25f, 0.25f);
    enemy.radius = (enemyTexture.getSize().x)/2;
    enemy.setOrigin(enemy.radius, enemy.radius);
    enemy.radius = (enemyTexture.getSize().x * 0.25)/2;
    enemy.setTexture(enemyTexture);
    enemy.setPosition(100 * (2*iterator + 1), 100);
    return enemy;
}
