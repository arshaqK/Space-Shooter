#include <SFML/Graphics.hpp>
#include<string.h>
#include "bullet.h"
using namespace sf;
class Player{
public:
Texture tex;
Sprite sprite;
float speed=0.4;
int x,y;
bool canFire = true;
Bullet *bt1;
// Bullet *bt2;
// Bullet *bt3;
int z=0;
bool ch = true;

Player(std::string png_path)
{
tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=340;y=700;
sprite.setPosition(x,y);
sprite.setScale(0.75,0.75);
bt1 = new Bullet("img/bullet.png", sprite.getPosition().x-65, sprite.getPosition().y+200);
// bt2 = new Bullet("img/bullet.png", sprite.getPosition().x-65, sprite.getPosition().y+100);
// bt3 = new Bullet("img/bullet.png", sprite.getPosition().x-65, sprite.getPosition().y);
}

void move(std::string s){
if(ch){
float delta_x=0,delta_y=0;
if(s=="l")
	delta_x=-1;
else if(s=="r")
	delta_x=1;
if(s=="u")
	delta_y=-1;
else if(s=="d")
	delta_y=1;

delta_x*=speed;
delta_y*=speed;
sprite.move(delta_x, delta_y);
float x_c=sprite.getPosition().x, y_c=sprite.getPosition().y;

if(x_c>780)
	x_c = x_c - 780;
if(x_c<0)
	x_c = x_c + 780;
if(y_c>780)
	y_c = y_c - 780;
if(y_c<0)
	y_c = y_c + 780;

	sprite.setPosition(x_c, y_c);
}	
}

void fire()
{
    bt1->move();
}

void update()
{   
    if (bt1->bullet.getPosition().y <= 0) 
    {
        bt1->x = sprite.getPosition().x+30;
        bt1->y = sprite.getPosition().y;    
    }
}


void rotateP(std::string s)
{
    if(s=="e")
        sprite.setRotation(45);   
    if(s=="q")
        sprite.setRotation(-45);
    if(s=="r")
        sprite.setRotation(0);
}
};
// ~Player()
// {
// 	if(bullet != nullptr)
// 		delete bullet;
// }


