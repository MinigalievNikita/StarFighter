#pragma once
#include "Pistol.h"
#include "Shotgun.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include <math.h>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include "Scene.h"


int main(int argc, const char * argv[]) {
    Scene scene(1920, 1080);
    scene.setFramerateLimit(60);
//    scene.initializeTexture();
    
    sf::Texture mapTexture;
    if(!mapTexture.loadFromFile("Space.jpg")){
        cout << "Cant load map";
    }
    mapTexture.setSmooth(true);
    sf::Sprite background;
    background.setTexture(mapTexture);
    
    sf::Texture heroTexture;
    if(!heroTexture.loadFromFile("SpaceFighter.png")){
        cout << "Cant load hero";
    }
    sf::Sprite circle(heroTexture);
    circle.setScale(0.5f, 0.5f);
    
    //Map map(1); создание карты
    //Hero hero(...); создание героя класс героя наследуется от sf::Sprite
    
    sf::Clock clock;
    
    while(scene.isOpen()){
        sf::Event event;
        while (scene.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                scene.close();
        }
        scene.clear();
        
        
        scene.handleEvents(hero, scene);
        scene.draw(background);
        scene.draw(circle);
        scene.display();
    }
    return 0;
}
