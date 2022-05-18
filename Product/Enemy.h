#pragma once
#include "Character.h"
#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include "EnemyPistol.h"
#include "Scene.h"
#include "Map.h"
class Enemy : public Character
{
public:
    static int positionIt;
    static int count;
    
    float prewTimeShoot = 0;
    static float spawnPeriod; //10 sec
    static float lastSpawnTime;
    
    vector<Bullet> Bullets;
    int bulletIt;
    
    bool down = true;
    
    Enemy(int velocity, int heath)
    {
        this->velocity = velocity;
        this->heath = heath;
    }
    EnemyPistol pistol;
    void shoot(sf::Vector2f heroPosition, float curentTime){
        if(curentTime - pistol.timeLastShoot > pistol.delayShoot){
            ++bulletIt;
            pistol.timeLastShoot = curentTime;
            sf::Vector2f enemyPosition = getPosition();
            vector<Bullet> temp = pistol.shoot(enemyPosition,(sf::Vector2i)heroPosition);
            Bullets.insert(Bullets.end(), temp.begin(), temp.end());
        }
    }
};

int counter = 0;

Enemy createEnemy(int iterator, sf::Texture &enemyTexture, int width, int height){
    int tempx = 100, tempy = 100;
    Enemy enemy(5,1);
    enemy.bulletIt = 0;
    enemy.setScale(0.25f, 0.25f);
    enemy.radius = (enemyTexture.getSize().x)/2;
    enemy.setOrigin(enemy.radius, enemy.radius);
    enemy.radius = (enemyTexture.getSize().x * 0.25)/2;
    enemy.setTexture(enemyTexture);
    tempx = 100 * ( 2 * Enemy::positionIt + 1);
    if(tempx < width && counter == 0) {
        enemy.setPosition(tempx, tempy);
    } else if(counter == 0){
        counter = 1;
        cout<<counter;
        Enemy::positionIt = 0;
    } else if(tempx < width){
        tempx = 100 * ( 2 * Enemy::positionIt + 1);
        tempy = height - 100;
        enemy.setPosition(tempx, tempy);
    } else if(1){
        Enemy::positionIt = 0;
        cout<<counter;
        counter = 0;
        enemy.setPosition(100, 500);
    }
    
    Enemy::positionIt++;
    return enemy;
}

Enemy& moveEnemy(Enemy& enemy, Map structures)
{
    if ((enemy.getPosition().y < structures.height * 1 / 3) && (enemy.down == true))
    {
        enemy.move(0, enemy.velocity);
    }
    else
    {
        enemy.down = false;

        if (enemy.getPosition().y > 2 * enemy.radius)
        {
            enemy.move(0, - enemy.velocity);
        }
        else
        {
            enemy.down = true;
        }
    }

    return enemy;
}
