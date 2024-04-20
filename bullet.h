#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;


class Bullet{
public:
    Sprite bullet;
    Texture texture;
    float x;
    float y;
    float speed = 0.4;
    bool stop = true;

Bullet(std::string png_path)
{
    texture.loadFromFile(png_path);
    bullet.setTexture(texture);
    bullet.setScale(0.4,0.4);
    bullet.setRotation(270);

}


Bullet(std::string png_path, float x, float y)
{
    texture.loadFromFile(png_path);
    bullet.setTexture(texture);
    this->x = x+100;
    this->y = y;
    bullet.setPosition(this->x, this->y);
    bullet.setScale(0.07,0.07);
    bullet.setRotation(270);
}

// void update(float deltaTime) {
//     bullet.move(0.f, -speed*deltaTime);
// }

// void draw(sf::RenderWindow& window) {
//     window.draw(bullet);
// }


void move() {
    // Move the bullet
    if(stop){
    y -= speed;
    bullet.setPosition(x, y);
    }
}

// void draw(sf::RenderWindow& window){
// 	window.draw(bullet);
// }

// void move(float x, float y)
// {
//     this->bullet.move(x*speed, y*speed);
// }

};