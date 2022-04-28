#pragma once
#include <SFML/Graphics.hpp>
#include "Pistol.h"
#include "Shotgun.h"
#include "Hero.h"
#include <vector>
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
    float prevTimeShoot = 0;
    float renderTimeShoot = 50;
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

    void handleEvents(Hero& hero, sf::Vector2i mousePosition)
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
            Bullets.push_back(pistol.shoot(hero.getPosition(), mousePosition));
        }
        time = clock.getElapsedTime();
        curTime = time.asMilliseconds();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && curTime - shotgun.timeLastShoot > shotgun.delayShoot){
            shotgun.timeLastShoot = curTime;
            itBullets++;
            Bullets.push_back(shotgun.shoot(hero.getPosition(), mousePosition));
        }
        
          
    }
    
    
    void Draw()
    {
        
        
        
        
        
        
        
        // drawing bullets
        if(itBullets > 0) {
            handleBullets();
            for(int k = 0; k < itBullets; ++k)
                draw(counterWayBullet(k));
        }
    }
    
   
    
    
    
    void handleBullets(){
        time = clock.getElapsedTime();
        curTime1 = time.asMilliseconds();
        if(curTime1 - prevTimeShoot > renderTimeShoot){
            prevTimeShoot = curTime1;
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
    
    
    sf::VertexArray counterWayBullet(int k){
        sf::VertexArray b(sf::Lines,2);
        b[0] = Bullets[k].r0 +  Bullets[k].it * Bullets[k].velocity * Bullets[k].direction;
        b[1] = Bullets[k].r0 + Bullets[k].size * Bullets[k].direction + Bullets[k].it * Bullets[k].velocity * Bullets[k].direction;
        b[0].color = sf::Color::Black;
        b[1].color = sf::Color::Black;
        return b;
    }
    
};



















//if(itBullets > 0) {
//    time = clock.getElapsedTime();
//    curTime1 = time.asMilliseconds();
//    if(curTime1 - prevTimeShoot > renderTimeShoot){
//        prevTimeShoot = curTime1;
//            for(int k = 0; k < itBullets; ++k) {
//                Bullets[k].it += 5;
//                if(Bullets[k].it  > width){
//                    Bullet temp;
//                    temp = Bullets[k];
//                    Bullets[k] = Bullets[itBullets - 1];
//                    Bullets[itBullets - 1] = temp;
//                    itBullets--;
//                    Bullets.resize(itBullets);
//                }
//                draw(counterWayBullet(k));
//             }
//    } else {
//        for(int k = 0; k < itBullets; ++ k){
//            draw(counterWayBullet(k));
//        }
//    }
//}
