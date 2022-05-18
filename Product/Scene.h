#pragma once
#include <SFML/Graphics.hpp>
#include "Pistol.h"
#include "Shotgun.h"
#include "Hero.h"
#include <vector>
#include "Enemy.h"
#include "Map.h"
enum fraction{
    Evil = 0,
    Good = 1,
};

const float renderTimeShoot = 85;

using namespace std;
struct Scene: public sf::RenderWindow{
    int width, height;
    Scene(int width, int height): sf::RenderWindow(sf::VideoMode(width, height), "Star Fighter"){
        this->width = width;
        this->height = height;
    }
    sf::Clock clock;
    
    MusicPlayer MusicPlayer;
    
    float curTime;
    float curTime1;
    float prevTime = 0;
    float prev = 0;
    float prevTimeShoot = 0;
    
    Pistol pistol;
    Shotgun shotgun;
    vector<Bullet> Bullets;
    int itBullets = 0;
    
    //cheking position of hero wirh position of objects
    int handleBarier(Hero& hero, Map& objects)
    {
        for (size_t i = 0; i < objects.obj.size(); ++i)
        {
            if ((abs(hero.getPosition().y - objects.obj[i].getPosition().y) <= objects.sizeObj / sqrt(2) + hero.radius) &&
                (abs(hero.getPosition().x - objects.obj[i].getPosition().x) <= objects.sizeObj / sqrt(2) + hero.radius))
                return i;
        }
        return -1;
    }
    
    //handling keyboard presses
    void handleEvents(Hero& hero, sf::Vector2i mousePosition, Map& objects, vector<Enemy> &enemies){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if ((hero.getPosition().x > hero.radius) && (handleBarier(hero, objects) == -1))
            hero.move(-hero.velocity, 0);
        else
            if ((hero.getPosition().x > hero.radius) && (objects.obj[handleBarier(hero, objects)].getPosition().x + objects.sizeObj / sqrt(2) > hero.getPosition().x))
                hero.move(-hero.velocity, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if ((hero.getPosition().x < width - hero.radius) && (handleBarier(hero, objects) == -1))
            hero.move(hero.velocity, 0);
        else
            if((hero.getPosition().x < width - hero.radius) && (objects.obj[handleBarier(hero, objects)].getPosition().x - objects.sizeObj / sqrt(2) < hero.getPosition().x))
                hero.move(hero.velocity, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if ((hero.getPosition().y > hero.radius) && (handleBarier(hero, objects) == -1))
                hero.move(0, -hero.velocity);
        else
            if ((hero.getPosition().y > hero.radius) && (objects.obj[handleBarier(hero, objects)].getPosition().y + objects.sizeObj / sqrt(2) > hero.getPosition().y))
                hero.move(0, -hero.velocity);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if ((hero.getPosition().y < height - hero.radius) && (handleBarier(hero, objects) == -1))
            hero.move(0, hero.velocity);
        else
            if ((hero.getPosition().y < height - hero.radius) && (objects.obj[handleBarier(hero, objects)].getPosition().y - objects.sizeObj / sqrt(2) < hero.getPosition().y))
                hero.move(0, hero.velocity);
    }
    curTime = clock.getElapsedTime().asMilliseconds();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && curTime - pistol.timeLastShoot > pistol.delayShoot){
        pistol.timeLastShoot = curTime;
        itBullets++;
        vector<Bullet> temp = pistol.shoot(hero.getPosition(), mousePosition);
        Bullets.insert(Bullets.end(), temp.begin(), temp.end());
        if(pistol.numberOfBullets == 0)
            pistol.reload();
    }
    curTime = clock.getElapsedTime().asMilliseconds();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && curTime - shotgun.timeLastShoot > shotgun.delayShoot){
        shotgun.timeLastShoot = curTime;
        itBullets += 3;
        vector<Bullet> temp = shotgun.shoot(hero.getPosition(), mousePosition);
        Bullets.insert(Bullets.end(), temp.begin(), temp.end());
        if(shotgun.numberOfBullets == 0)
            shotgun.reload();
    }
    if(curTime - prev > EnemyPistol::delayShoot) {
        prev = curTime;
        for(int l = 0; l < Enemy::count; ++l){
            if(l == 0) MusicPlayer.enemyshoot();
            enemies[l].shoot(hero.getPosition(), curTime);
            }
        }
    }
    
    

    void Draw(vector<Enemy> &enemies, Hero &hero, Map map, sf::Sprite background, sf::Sprite GO)
    {
        //drawing word
        draw(background);
        for(int i = 0; i < map.obj.size(); ++i)
            draw(map.obj[i]);
        draw(hero);

        // drawing bullets of enemies
        for(int l = 0; l < Enemy::count; ++l) {
            if(enemies[l].bulletIt > 0) {
                handleBullets(enemies[l].Bullets, enemies, map, hero, enemies[l].prewTimeShoot, enemies[l].bulletIt, Evil);
                for(int k = 0; k < enemies[l].bulletIt; ++k) {
                    draw(counterWayBullet(enemies[l].Bullets[k]));
                }
            }
            moveEnemy(enemies[l], map);
            draw(enemies[l]);
        }

        // drawing bullets of hero
        if(itBullets > 0) {
            handleBullets(Bullets, enemies, map, hero, prevTimeShoot, itBullets, Good);
            for(int k = 0; k < itBullets; ++k)
                draw(counterWayBullet(Bullets[k]));
        }
    }
    
    //handling movement of all bullets
    void handleBullets(vector<Bullet>& Bullets, vector<Enemy>& enemies, Map& objects, Hero& hero, float& prevTimeShoot, int& itBullets, fraction name)
        {
            curTime1 = clock.getElapsedTime().asMilliseconds();
            if (curTime1 - prevTimeShoot > renderTimeShoot)
            {
                prevTimeShoot = curTime1;

                for (int k = 0; k < itBullets; ++k) //Ïðîâåðêà íà âûõîä ïóëè çà ïðåäåë ýêðàíà
                {
                    Bullets[k].it += 5;

                    if (Bullets[k].it * Bullets[k].velocity > sqrt(width * width + height * height))
                    {
                        Bullet temp;
                        temp = Bullets[k];
                        Bullets[k] = Bullets[itBullets - 1];
                        Bullets[itBullets - 1] = temp;
                        itBullets--;
                        Bullets.resize(itBullets);
                    }
                }

                for (int k = 0; k < itBullets; ++k) //Проверка на попадение пули во врага
                {
                    for (int l = 0; l < Enemy::count; ++l)
                    {
                        float t_x = abs((Bullets[k].r0 + Bullets[k].size * Bullets[k].direction + Bullets[k].it * Bullets[k].velocity * Bullets[k].direction).x - enemies[l].getPosition().x);
                        float t_y = abs((Bullets[k].r0 + Bullets[k].size * Bullets[k].direction + Bullets[k].it * Bullets[k].velocity * Bullets[k].direction).y - enemies[l].getPosition().y);

                        if ((t_x < enemies[l].radius) && (t_y < enemies[l].radius) && (name == Good))
                        {
                            Bullet temp;
                            temp = Bullets[k];
                            Bullets[k] = Bullets[itBullets - 1];
                            Bullets[itBullets - 1] = temp;
                            itBullets--;
                            Bullets.resize(itBullets);

                            enemies[l].heath--;
                        
                            if (enemies[l].heath == 0)
                            {
                                Enemy temp = enemies[l];
                                enemies[l] = enemies[Enemy::count - 1];
                                enemies[Enemy::count - 1] = temp;
                                Enemy::count--;
                                MusicPlayer.enemyDestrucntion();
                                enemies.erase(enemies.end() - 1);
                            }
                        }

                        if (itBullets == k) //Чтобы не случилось выхода за пределы вектора
                        {
                            break;
                        }
                    }
                }

                for (int k = 0; k < itBullets; ++k) //Ïðîâåðêà ïóëè íà ïîïàäåíèå â ïðåïÿòñòâèå
                {
                    for (size_t i = 0; i < objects.obj.size(); ++i)
                    {
                        float t_x = abs((Bullets[k].r0 + Bullets[k].size * Bullets[k].direction + Bullets[k].it * Bullets[k].velocity * Bullets[k].direction).x - objects.obj[i].getPosition().x);
                        float t_y = abs((Bullets[k].r0 + Bullets[k].size * Bullets[k].direction + Bullets[k].it * Bullets[k].velocity * Bullets[k].direction).y - objects.obj[i].getPosition().y);

                        if ((t_x < objects.sizeObj / sqrt(2)) && (t_y < objects.sizeObj / sqrt(2)))
                        {
                            Bullet temp;
                            temp = Bullets[k];
                            Bullets[k] = Bullets[itBullets - 1];
                            Bullets[itBullets - 1] = temp;
                            itBullets--;
                            Bullets.resize(itBullets);
                        }

                        if (itBullets == k) //Чтобы не случилось выхода за пределы вектора
                        {
                            break;
                        }
                    }
                }

                for (int k = 0; k < itBullets; ++k) //Проверка на попадение пули в героя
                {
                    float t_x = abs((Bullets[k].r0 + Bullets[k].size * Bullets[k].direction + Bullets[k].it * Bullets[k].velocity * Bullets[k].direction).x - hero.getPosition().x);
                    float t_y = abs((Bullets[k].r0 + Bullets[k].size * Bullets[k].direction + Bullets[k].it * Bullets[k].velocity * Bullets[k].direction).y - hero.getPosition().y);

                    if ((t_x < hero.radius) && (t_y < hero.radius))
                    {
                        Bullet temp;
                        temp = Bullets[k];
                        Bullets[k] = Bullets[itBullets - 1];
                        Bullets[itBullets - 1] = temp;
                        itBullets--;
                        Bullets.resize(itBullets);

                        hero.heath--;
                    }

                    if (itBullets == k) //Чтобы не случилось выхода за пределы вектора
                    {
                        break;
                    }
                }
            }
        }
    
    //preparation all bullets for drawing
    sf::VertexArray counterWayBullet(Bullet Bullet){
        sf::VertexArray b(sf::Lines,2);
        b[0] = Bullet.r0 +  Bullet.it * Bullet.velocity * Bullet.direction;
        b[1] = Bullet.r0 + Bullet.size * Bullet.direction + Bullet.it * Bullet.velocity * Bullet.direction;
        b[0].color = sf::Color::White;
        b[1].color = sf::Color::White;
        return b;
    }

    void GameOver(sf::Sprite GO){
        draw(GO);
        MusicPlayer.gameOver();
    }
};

