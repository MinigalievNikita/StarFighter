#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>
enum MapName{
    SPACEWAY = 1,
    MILKYWAY = 2,
};

struct Map
{
    std::vector <sf::CircleShape> obj;
//    std::map <std::string, sf::Vector2f>;
    int width;
    int height;
    int sizeObj = 200;

//    Map(int i)
//    {
//        if (i == 1)
//        {
//            this->width  = 1920;
//            this->height = 1080;
//
//            sf::CircleShape square(sizeObj, 4);
//            square.setOrigin(sizeObj, sizeObj);
//            square.setPosition(width / 2, height / 2);
//            square.setFillColor(sf::Color::Blue);
//            square.setRotation(45);
//
//            obj.push_back(square);
//        }
//
//        if (i == 2)
//        {
//            this->width = 1920;
//            this->height = 1080;
//
//            sf::CircleShape square(sizeObj, 4);
//            square.setOrigin(sizeObj, sizeObj);
//            square.setPosition(width / 4, height / 2);
//            square.setFillColor(sf::Color::Blue);
//            square.setRotation(45);
//            obj.push_back(square);
//
//            square.setPosition(3 * width / 4, height / 2);
//            square.setFillColor(sf::Color::Blue);
//            square.setRotation(45);
//            obj.push_back(square);
//
//        }
//    }
};


Map mapCreator(enum MapName name){
    Map map;
    if (name == 1)
    {
        map.width  = 1920;
        map.height = 1080;
        map.sizeObj = 200;
        sf::CircleShape square(map.sizeObj, 4);
        square.setOrigin(map.sizeObj, map.sizeObj);
        square.setPosition(map.width / 2, map.height / 2);
        square.setFillColor(sf::Color::Blue);
        square.setRotation(45);
    
        map.obj.push_back(square);
    }

    if (name == 2)
    {
        map.width  = 1920;
        map.height = 1080;
        map.sizeObj = 200;
        sf::CircleShape square(map.sizeObj, 4);
        square.setOrigin(map.sizeObj, map.sizeObj);
        square.setPosition(map.width / 4, map.height / 2);
        square.setFillColor(sf::Color::Blue);
        square.setRotation(45);
        map.obj.push_back(square);
        
        square.setPosition(3 * map.width / 4, map.height / 2);
        square.setFillColor(sf::Color::Blue);
        square.setRotation(45);
        map.obj.push_back(square);

    }
    return map;
}
