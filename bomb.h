#include <SFML/Graphics.hpp>
#include <iostream>
#include<string.h>
using namespace sf;

class Bomb
{
public:
Texture bombTex;
Sprite b;
Clock clock;
float timer = 0;
float speed=0.6;
float x, y;
int time = clock.getElapsedTime().asSeconds(); 
bool chk = true;
Bomb(){}
Bomb(float X, float Y)
{
    b.setPosition(780,780);
    bombTex.loadFromFile("img/enemy_laser.png");
    b.setTexture(bombTex);
    x = X;
    y = Y;
    b.setPosition(x,y);
    b.setScale(0.75,0.75);
    
}
void move()
{
    if(chk){
        y = (y+0.1);
        b.setPosition(x,y);
    }
}

void update(int X, int Y)
{
    if(y>780)
        y = Y;

    x = X;
}

~Bomb()
{
    delete this;
}


};