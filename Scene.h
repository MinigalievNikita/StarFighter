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
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
              itBullets++;
              Bullets.push_back(pistol.shoot(hero.getPosition(), mousePosition));
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
              itBullets++;
              Bullets.push_back(shotgun.shoot(hero.getPosition(), mousePosition));
          }
          
    }
    
    void renderEvents(float curtime, float& prevtime){
        //считаем пути пулям;
    }
    
    
    void Draw()
    {
        
    }
};
