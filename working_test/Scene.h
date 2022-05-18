#pragma once
#include <SFML/Graphics.hpp>
#include "Pistol.h"
#include "Shotgun.h"
#include "Hero.h"
#include <vector>
#include "Enemy.h"
const float renderTimeShoot = 50;

using namespace std;
struct Scene: public sf::RenderWindow{
    int width, height;
    Scene(int width, int height): sf::RenderWindow(sf::VideoMode(width, height), "Star Fighter"){
        this->width = width;
        this->height = height;
    }
    sf::Clock clock;
    sf::Time time;
    float curTime;
    float curTime1;
    float prevTime = 0;
    float prev = 0;
    float prevTimeShoot = 0;
    Pistol pistol;
    Shotgun shotgun;
    vector<Bullet> Bullets;
    int itBullets = 0;

//    sf::Sprite background;
//    void initializeTexture(){
//        sf::Texture mapTexture;
//        if(!mapTexture.loadFromFile("Space.jpg")){
//            cout << "Cant load map";
//        }
//        mapTexture.setSmooth(true);
//        background.setTexture(mapTexture);
//
//    }
    //  bool IsForceApplied(size_t birdIndex, const World&) const
    //  {
    //  }

    void handleEvents(Hero& hero, sf::Vector2i mousePosition, vector<Enemy> &enemies)
    {

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if(hero.getPosition().x > hero.velocity + 0.1 + hero.radius)
                hero.move(-hero.velocity,0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if(hero.getPosition().x < width - hero.velocity - 0.1 - hero.radius)
                hero.move(hero.velocity,0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if(hero.getPosition().y > hero.velocity + 0.1 + hero.radius)
                hero.move(0,-hero.velocity);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if(hero.getPosition().y < height - hero.velocity - 0.1 - hero.radius)
                hero.move(0,hero.velocity);
        }

        time = clock.getElapsedTime();
        curTime = time.asMilliseconds();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && curTime - pistol.timeLastShoot > pistol.delayShoot){
            pistol.timeLastShoot = curTime;
            itBullets++;
            vector<Bullet> temp = pistol.shoot(hero.getPosition(), mousePosition);
            Bullets.insert(Bullets.end(), temp.begin(), temp.end());
        }

        time = clock.getElapsedTime();
        curTime = time.asMilliseconds();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && curTime - shotgun.timeLastShoot > shotgun.delayShoot){
            shotgun.timeLastShoot = curTime;
            itBullets += 3;
            vector<Bullet> temp = shotgun.shoot(hero.getPosition(), mousePosition);
            Bullets.insert(Bullets.end(), temp.begin(), temp.end());
        }
        if(curTime - prev > pistol.delayShoot) {
            prev = curTime;
        for(int l = 0; l < Enemy::count; ++l){
            enemies[l].shoot(hero.getPosition(), curTime);
        }
        }
    }

    float prevTimeShoot1 = 0;
    void Draw(vector<Enemy> &enemies, Hero hero, Map structers, sf::Sprite background)
    {
        //        draw(background);
                draw(structers.obj[0]);
                draw(hero);


        for(int l = 0; l < Enemy::count; ++l) {
            if(enemies[l].it > 0) {
                handleBullets(enemies[l].Bullets, enemies[l].prewTimeShoot, enemies[l].it);
                for(int k = 0; k < enemies[l].it; ++k) {
                    draw(counterWayBullet(enemies[l].Bullets[k]));
                }
            }
            draw(enemies[l]);
        }


        // drawing bullets
        if(itBullets > 0) {
            handleBullets(Bullets, prevTimeShoot, itBullets);
            for(int k = 0; k < itBullets; ++k)
                draw(counterWayBullet(Bullets[k]));
        }
    }





    void handleBullets(vector<Bullet> &Bullets, float &prevTimeShoott, int &itBullets){
        time = clock.getElapsedTime();
        curTime1 = time.asMilliseconds();
        if(curTime1 - prevTimeShoott > renderTimeShoot){
            prevTimeShoott = curTime1;
                for(int k = 0; k < itBullets; ++k) {
                    Bullets[k].it += 5;
                    if(Bullets[k].it  > width){
                        Bullet temp;
                        temp = Bullets[k];
                        Bullets[k] = Bullets[itBullets - 1];
                        Bullets[itBullets - 1] = temp;
                        itBullets--;
                        Bullets.resize(itBullets);
                    }
                 }
        }
    }


    sf::VertexArray counterWayBullet(Bullet Bullet){
        sf::VertexArray b(sf::Lines,2);
        b[0] = Bullet.r0 +  Bullet.it * Bullet.velocity * Bullet.direction;
        b[1] = Bullet.r0 + Bullet.size * Bullet.direction + Bullet.it * Bullet.velocity * Bullet.direction;
        b[0].color = sf::Color::White;
        b[1].color = sf::Color::White;
        return b;
    }

};



