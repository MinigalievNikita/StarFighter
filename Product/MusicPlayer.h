#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
class MusicPlayer {
public:
    sf::Music music;
    
    void shoot() {
        music.openFromFile("BulletSound.ogg");
        music.play();
    }
    void enemyshoot(){
//        music.openFromFile("EnemyBulletsSound.ogg");
//        music.play();
    }
    void enemyDestrucntion(){
//        music.openFromFile("AlienDestruction.ogg");
//        music.play();
    }
    void gameOver(){
//        music.openFromFile("AlienDestruction.ogg");
//        music.play();
    }
};
