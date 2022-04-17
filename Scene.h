#pragma once
#include <SFML/Graphics.hpp>
#include "Pistol.h"
#include "Shotgun.h"
struct Scene: public sf::RenderWindow{
    Scene(int width, int height): sf::RenderWindow(sf::VideoMode(width, height), "Star Fighter"){}
    Pistol pistol;
    Shotgun shotgun;
    
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

      void handleEvents(Hero& hero, Scene scene)
      {
          sf::Vector2i mousePosition = sf::Mouse::getPosition(scene);
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
          {
              if(current.x > velocity + 0.1 + radius)
                  circle.move(-velocity,0);
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
          {
              if(current.x < width - velocity - 0.1 - radius)
                  circle.move(velocity,0);
          }
          else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
          {
              if(current.y > velocity + 0.1 + radius)
              circle.move(0,-velocity);
          }
         else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
          {
              if(current.y < height - velocity - 0.1 - radius)
              circle.move(0,velocity);
          }
          
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
    
              Bullet bullets = pistol.shoot(hero, mousePosition);
          }
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
    
              Bullet bullets2 = shotgun.shoot(hero, mousePosition);
          }
      }

    void Draw()
    {
        
    }
};
