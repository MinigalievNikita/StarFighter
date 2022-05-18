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
#include <unistd.h>

int Enemy::positionIt = 0;
float Enemy::spawnPeriod = 1; //in sec
float Enemy::lastSpawnTime = 0;
int Enemy::count = 0;
const float timeOfUpdateFrame = 5; //in millisec

int main(int argc, const char * argv[]) {
    
    // creating objects on map
    Map map = mapCreator(MILKYWAY);
    
    // creating scene - window
    Scene scene(map.width, map.height);
    scene.setFramerateLimit(60);
    
    sf::Texture mapTexture;
    if(!mapTexture.loadFromFile("Space.jpg")){
        cout << "Cant load map";
    }
    
    sf::Sprite background;
    background.setTexture(mapTexture);
    
    sf::Texture enemyTexture;
    if(!enemyTexture.loadFromFile("Alien.png")){
        cout << "Cant load hero";
    }
    
    sf::Texture heroTexture;
    if(!heroTexture.loadFromFile("SpaceFighter.png")){
        cout << "Cant load hero";
    }
    Hero hero = createHero(heroTexture);

    vector<Enemy> enemies;
    
    sf::Texture finish;
    if(!finish.loadFromFile("GO.png")){
        cout << "Cant load map";
    }
    sf::Sprite GO;
    GO.setTexture(finish);
    
    sf::Clock clock;
    float prevFrame = 0;
    
    while(scene.isOpen()){
        sf::Event event;
        while (scene.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                scene.close();
        }
        scene.clear();
        if(hero.heath > 0){
            if(clock.getElapsedTime().asSeconds() - Enemy::lastSpawnTime > Enemy::spawnPeriod){
                Enemy::lastSpawnTime = clock.getElapsedTime().asSeconds();
                enemies.push_back(createEnemy(++Enemy::count, enemyTexture, scene.width, scene.height));
            }
            
            scene.handleEvents(hero, sf::Mouse::getPosition(scene), map, enemies);
            scene.Draw(enemies, hero, map, background, GO);
            scene.display();
            
            while(clock.getElapsedTime().asMilliseconds() - prevFrame < timeOfUpdateFrame){}
            prevFrame = clock.getElapsedTime().asMilliseconds();
            
        } else {
            scene.GameOver(GO);
            scene.display();
        }
    }
    return 0;
}
