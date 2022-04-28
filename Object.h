#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>

struct Objects
{
    std::vector <sf::CircleShape> obj;
//    std::map <std::string, sf::Vector2f>;
    int width;
    int height;
    int sizeObj = 200;

    Objects(int i)
    {
        if (i == 1)
        {
            this->width  = 1920;
            this->height = 1080;
            
            sf::CircleShape square(sizeObj, 4);
            square.setOrigin(sizeObj, sizeObj);
            square.setPosition(width / 2, height / 2);
            square.setFillColor(sf::Color::Blue);
            square.setRotation(45);
        
            obj.push_back(square);
        }

//        if (i == 2)
//        {
//            this->width = 1920;
//            this->height = 1080;
//
//            sf::Vector2f temp = sf::Vector2f(width / 4, height / 2);
//            obj.push_back(temp);
//            temp = sf::Vector2f(3 * width / 4, height / 2);
//            obj.push_back(temp);
//        }
    }
};
