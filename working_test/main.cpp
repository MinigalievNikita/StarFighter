#include "Pistol.h"
#include "Shotgun.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include <math.h>
#include <SFML/Audio.hpp>
#include "Bullet.h"
#include "Scene.h"
#include "Map.h"
#include "Hero.h"
#include "Enemy.h"

float Enemy::spawnPeriod = 10;
float Enemy::lastSpawnTime = 0;
int Enemy::count = 0;


int main(int argc, const char * argv[]) {
    
    
    Map structures(1); // создание объектов на карте
    
    Scene scene(structures.width, structures.height); // создание экрана
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
    
    Hero hero(5, 50);
    hero.setScale(0.25f, 0.25f);
    hero.radius = (heroTexture.getSize().x)/2;
    hero.setOrigin(hero.radius, hero.radius);
    hero.radius = (heroTexture.getSize().x * 0.25)/2;
    hero.velocity = 10;
    hero.setTexture(heroTexture);
    hero.setPosition(500, 500);
    
//    sf::CircleShape square(200, 4);
//    square.setOrigin(200, 200);
//    square.setPosition(structures.obj[0].x, structures.obj[0].y);
//    square.setFillColor(sf::Color::Red);
//    square.setRotation(45);
    vector<Enemy> enemies;
    
    sf::Clock clock;
    while(scene.isOpen()){
        sf::Event event;
        while (scene.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                scene.close();
        }
        scene.clear();
        if(clock.getElapsedTime().asSeconds() - Enemy::lastSpawnTime > Enemy::spawnPeriod){
            Enemy::lastSpawnTime = clock.getElapsedTime().asSeconds();
            enemies.push_back(createEnemy(structures, ++Enemy::count));
        }
        
        scene.handleEvents(hero, sf::Mouse::getPosition(scene), enemies);
        scene.Draw(enemies, hero, structures, background);
        scene.display();
    }
    return 0;
}
