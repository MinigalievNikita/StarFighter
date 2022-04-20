#include <SFML\Graphics.hpp>
#include <math.h>
#include <iostream>
#include <Vector>
#include <map>
#include <string>

class Character : public sf::Sprite
{
public:
	float velocity;
	sf::Vector2f ro;
	int heath;
	int size;
};
