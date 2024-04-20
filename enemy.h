#include <SFML/Graphics.hpp>
#include <iostream>
#include<string.h>
#include "bomb.h"
using namespace sf;
using namespace std;


class Enemy
{
public:
    Texture eTex;
    Sprite enemy;
    // Sprite enemy2;
    float speed=0.4;
    float x,y;
    Bomb* bomb;
    Enemy()
    { 

    }
    ~Enemy()
    {
        enemy.setPosition(-100,-100);
    }
};


class Invader : public Enemy{
public:
    
    Invader() : Enemy(){
        
    }
};

class Alpha : public Invader {
public:
    Alpha() : Invader () {}
    Alpha(int x, int y) : Invader()
    {
        eTex.loadFromFile("img/enemy_1.png");
        enemy.setTexture(eTex);
        enemy.setScale(0.6,0.45);
        enemy.setPosition(x,y);
        bomb = new Bomb[2]{Bomb(x+25, y+50),  Bomb(x+25, y+50)};
    }

    
   
};

class Beta : public Invader {
public:
Beta() : Invader(){}
    Beta(int x, int y) : Invader()
    {
        eTex.loadFromFile("img/enemy_2.png");
        enemy.setTexture(eTex);
        enemy.setScale(0.45,0.45);
        enemy.setPosition(x,y);
        bomb = new Bomb[2]{Bomb(x+25, y+50), Bomb(x+25, y+50)};
    }
   
};

class Gamma : public Invader {
public:
    Gamma() : Invader(){}
    Gamma(int x, int y) : Invader()
    {
        eTex.loadFromFile("img/enemy_3.png");
        enemy.setTexture(eTex);
        enemy.setPosition(x,y);
        enemy.setScale(0.35,0.35);
        bomb = new Bomb[2]{Bomb(x+25, y+50), Bomb(x+25, y+50)};
    }   

};

class Dragon : public Enemy {
public:
    Dragon() : Enemy(){}
    Dragon(int x, int y) : Enemy()
    {
        eTex.loadFromFile("img/dragon.png");
        enemy.setTexture(eTex);
        enemy.setScale(1,1);
        enemy.setPosition(x,y);
        bomb = new Bomb[3]{Bomb(x+25, y+50), Bomb(x+25, y+70), Bomb(x+25, y+90)};
        
    }
   
};

class Monster : public Enemy {
public:
    Monster() : Enemy(){}
    Monster(int x, int y) : Enemy()
    {
        eTex.loadFromFile("img/monster1.png");
        enemy.setTexture(eTex);
        enemy.setScale(0.4,0.4);
        enemy.setPosition(x+100,y);
       bomb = new Bomb[3]{Bomb(x+25, y+50), Bomb(x+25, y+70), Bomb(x+25, y+90)};
    }
   
};
