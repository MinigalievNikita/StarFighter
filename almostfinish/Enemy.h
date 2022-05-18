#pragma once
#include "Character.h"
#include "Map.h"
#include "Bullet.h"
class Enemy : public Character
{
public:
    const float delayShoot = 500;
    static int count;
    static float spawnPeriod; //10 sec
    static float lastSpawnTime;
    vector<Bullet> Bullets;
    int it;
    float prewTimeShoot = 0;
    Enemy(int velocity, int heath)
    {
        this->velocity = velocity;
        this->heath = heath;
    }
    Pistol pistol;
    void shoot(sf::Vector2f heroPosition, float curentTime){
        if(curentTime - pistol.timeLastShoot > pistol.delayShoot + delayShoot){
            ++it;
            pistol.timeLastShoot = curentTime;
            sf::Vector2f enemyPosition = getPosition();
            vector<Bullet> temp = pistol.shoot(enemyPosition,(sf::Vector2i)heroPosition);
            Bullets.insert(Bullets.end(), temp.begin(), temp.end());
        }
    }
};


Enemy createEnemy(Map structeres, int iterator){
    sf::Texture enemyTexture;
    if(!enemyTexture.loadFromFile("SpaceFighter.png")){
        cout << "Cant load hero";
    }
    Enemy enemy(0,3);
    enemy.it = 0;
    enemy.setScale(0.25f, 0.25f);
    enemy.radius = (enemyTexture.getSize().x)/2;
    enemy.setOrigin(enemy.radius, enemy.radius);
    enemy.radius = (enemyTexture.getSize().x * 0.25)/2;
    enemy.setTexture(enemyTexture);
    enemy.setPosition(100 * (2*iterator + 1), 100);
    return enemy;
}
