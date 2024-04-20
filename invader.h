#include <SFML/Graphics.hpp>
#include <iostream>
#include<string.h>
#include "bomb.h"
#include "enemy.h"
using namespace sf;
using namespace std;

class Invader : public Enemy
{
public:

Invader(std::string imagePath)
{
    eTex.loadFromFile(imagePath);
    enemy.setTexture(eTex);
    x=340;y=-200;
    enemy.setPosition(x,y);
    enemy.setScale(0.75,0.75);
    move();
}

};