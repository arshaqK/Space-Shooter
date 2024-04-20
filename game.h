
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
#include "player.h"
#include "enemy.h"


#include<fstream>
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:
Sprite background; //Game background sprite
Texture bg_texture;
Sprite textBac;
Texture bg;
Sprite levelBg;
Texture lBg;
Sprite scoreBg;
Sprite hScoreBg;
Sprite LivesBg;
Texture pGame;
Sprite sGame;



Player* p; //player
Enemy** ptr = new Enemy*[5];


int enemyCount = 3;  
int eNum=0;
int number;
int level = 1;
int score = 0;
int count = 0;
bool check = false;
    int Lives = 3;
    int highscore = 0;
bool incCh = false;
bool pause = false;
// add other game attributes


Game()
{
    p=new Player("img/player_ship.png");
    eNum = rand() % 3; // temperory commented
    eNum = 1;
    number = 1; 
    ptr[0] = new Alpha[6]{Alpha(250, 0), Alpha(350, 0), Alpha(450, 0), Alpha(250, 100), Alpha(350, 100), Alpha(450, 100)};
    ptr[1] = new Beta[6]{Beta(300, 0), Beta(400, 0), Beta(200, 100), Beta(500, 100), Beta(100, 200), Beta(600, 200)};
    ptr[2] = new Gamma[6]{Gamma(200, 0), Gamma(300, 100), Gamma(400, 100), Gamma(500, 0), Gamma(200, 200), Gamma(500, 200)};
    ptr[3] = new Dragon[1]{Dragon(300,0)};
    ptr[4] = new Monster[1]{Monster(250,0)};
  
    bg_texture.loadFromFile("img/bgg.png");
    background.setTexture(bg_texture);

    Lives=3;
    lBg.loadFromFile("img/Level Bg.png");
    levelBg.setTexture(lBg);
    levelBg.setPosition(20,10);
    levelBg.setScale(0.4,0.6);
    
    scoreBg.setTexture(lBg);
    scoreBg.setPosition(625,10);
    scoreBg.setScale(0.4,0.65);
    
    hScoreBg.setTexture(lBg);
    hScoreBg.setPosition(610,80);
    hScoreBg.setScale(0.5,0.65);

    LivesBg.setTexture(lBg);
    LivesBg.setPosition(20,80);
    LivesBg.setScale(0.4,0.6);
    
    pGame.loadFromFile("img/pause.png");
    sGame.setTexture(pGame);
    sGame.setScale(0.4,0.4);

    ofstream create;
    create.open("Player_Details.txt");
    create.close();

    
    
}

void start_game(RenderWindow &window)
{    
    srand(time(0));
   
    Clock clock;
    float timer=0;

    int type = 0;
    int health = 0;
    int arrC = 0;
    // for(int i=0; i<6; i++){
    //         ptr[type][i].bomb->b.setPosition(0,0);   
    // }                 
    Text levelText;
    Text Score;
    Text Highscore;
    Text l;
    Text t;
    Text tr;
    Font font;
    if (!font.loadFromFile("fonts/Ayamikan.ttf"))
    {
        // Error loading font
        cout << "Error";
    }
    levelText.setFont(font); // set the font
    levelText.setCharacterSize(35); // set the character size
    levelText.setFillColor(Color::White); // set the fill color
    levelText.setPosition(40, 5); // set the position
    
    Score.setFont(font); // set the font
    Score.setCharacterSize(28); // set the character size
    Score.setFillColor(Color::White); // set the fill color
    Score.setPosition(640, 10); // set the position
    
    Highscore.setFont(font); // set the font
    Highscore.setCharacterSize(26); // set the character size
    Highscore.setFillColor(Color::White); // set the fill color
    Highscore.setPosition(620, 85); // set the position
    
    l.setFont(font); // set the font
    l.setCharacterSize(35); // set the character size
    l.setFillColor(Color::White); // set the fill color
    l.setPosition(40, 75); // set the position

    t.setFont(font); // set the font
    t.setCharacterSize(35); // set the character size
    t.setFillColor(Color::White); // set the fill color
    t.setPosition(30, 125); // set the position
    
    tr.setFont(font); // set the font
    tr.setCharacterSize(35); // set the character size
    tr.setFillColor(Color::White); // set the fill color
    tr.setPosition(30, 155); // set the position
    
    fstream myFile;
    myFile.open("Player_Details.txt", ios ::app);

    

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds(); 
        clock.restart();
        timer += time;  
        int counter = 0;
        incCh = false;
        //cout<<time<<endl; 
        levelText.setString("Level: " + to_string(level));   
        
        if(score > highscore)
            highscore = score;

        Score.setString("Score: " + to_string(score));
        Highscore.setString("High Score: " + to_string(highscore));
        l.setString("Lives: " + to_string(Lives));
        t.setString("Time: " + to_string(time));
        tr.setString("Timer: " + to_string(timer));


        myFile << "HighScore: " << highscore << endl;
        myFile << "Score: " << score;

        if(score > highscore)
            highscore = score;

        if(type<3){
            for(int j=0; j<6; j++)
            {
                if (p->bt1->bullet.getPosition().x > ptr[type][j].enemy.getPosition().x && p->bt1->bullet.getPosition().x < ptr[type][j].enemy.getPosition().x+50 && p->bt1->bullet.getPosition().y > ptr[type][j].enemy.getPosition().y && p->bt1->bullet.getPosition().y < ptr[type][j].enemy.getPosition().y+50)
                {
                    p->bt1->y = 0;
                    ptr[type][j].enemy.setPosition(-100, -100);
                    if(type == 0)
                        score += 10*level;
                    if(type == 1)
                        score += 20*level;
                    if(type == 2)
                        score += 30*level;
                }
            }
        }

        for(int i=0; i<6; i++){
            if(ptr[type][i].bomb->b.getPosition().x > p->sprite.getPosition().x && ptr[type][i].bomb->b.getPosition().x < p->sprite.getPosition().x+60 && ptr[type][i].bomb->b.getPosition().y > p->sprite.getPosition().y && ptr[type][i].bomb->b.getPosition().y > p->sprite.getPosition().y+50)
            {
                Lives--;     
                ptr[type][i].bomb->b.getPosition().x == -100;
                ptr[type][i].bomb->b.getPosition().y == -100;
                    
            }
            break;
            if(Lives == 0)
                window.close();
        }
            
        for(int i=0; i<6; i++)
        {
            if(ptr[type][i].enemy.getPosition().x == -100 && ptr[type][i].enemy.getPosition().y == -100)
                counter++;
        }

        if(counter == 6){
            type++;
           
        }
        if(type>=3)
        {
            for(int i=0; i<2; i++)
            if (p->bt1->bullet.getPosition().x > ptr[type][i].enemy.getPosition().x && p->bt1->bullet.getPosition().x < ptr[type][i].enemy.getPosition().x+200 && p->bt1->bullet.getPosition().y > ptr[type][i].enemy.getPosition().y && p->bt1->bullet.getPosition().y < ptr[type][i].enemy.getPosition().y+50)
                {
                    p->bt1->y = 0;
                    health++;
                    if(health > 3 || (int)timer%5 == 0)
                    {
                         ptr[type][i].enemy.setPosition(-100, -100);
                        health = 0;
                    }
                    
                }
            for(int i=0; i<2; i++)
            {
                if(ptr[type][i].enemy.getPosition().x == -100 && ptr[type][i].enemy.getPosition().y == -100)
                    counter++;
            }
            if(counter == 1){
                type++;
                counter = 0;
            }           

        }
        
 	Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game     	    
        }
          
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
    if (Keyboard::isKeyPressed(Keyboard::E)) // If down key is pressed
            p->rotateP("e");
    if (Keyboard::isKeyPressed(Keyboard::Q)) // If down key is pressed
            p->rotateP("q");
    if (Keyboard::isKeyPressed(Keyboard::R)) // If down key is pressed
            p->rotateP("r");
    if (Keyboard::isKeyPressed(Keyboard::P)) // If down key is pressed
    {
        p->ch = false;
        p->bt1->stop = false;
        for(int i=0; i<6; i++)
            ptr[type][i].bomb->chk = false;
        window.draw(sGame);
        
    }

    if (Keyboard::isKeyPressed(Keyboard::Space)) // If down key is pressed
    {
        p->ch = true;
        p->bt1->stop = true;
        for(int i=0; i<6; i++)
            ptr[type][i].bomb->chk = true;
    }
    
    


          //player will move downwards
    
	////////////////////////////////////////////////
	/////  Call your functions here            ////
    // for(int i=0; i<6; i++){
    //     ptr[type][i].bomb->b.setPosition(ptr[type][i].enemy.getPosition().x, ptr[type][i].enemy.getPosition().y);        
    // }
    
    p->fire();
    p->update();


       

    ////////////////////////////////////////////////
    window.clear(Color::Black); //clears the screen
    window.draw(background);  // setting background
    window.draw(levelBg);
    window.draw(levelText);
    window.draw(scoreBg);
    window.draw(hScoreBg);
    window.draw(Score);
    window.draw(Highscore);
    window.draw(LivesBg);
    window.draw(l);
    window.draw(p->sprite);   // setting player on screen
    window.draw(p->bt1->bullet);
    window.draw(t);
    window.draw(tr);

    if(type<3)
        for(int i=0; i<6; i++){
            ptr[type][i].bomb->move();
            int x = ptr[type][i].enemy.getPosition().x;
            int y = ptr[type][i].enemy.getPosition().y;
            if(level == 1)
                if((int)timer % 6 == 0 && x!=-100)
                    ptr[type][i].bomb->update(x+20, y);
            if(level == 3)
                if((int)timer % 3 == 0 && x!=-100)
                    ptr[type][i].bomb->update(x+25, y);
            
            window.draw(ptr[type][i].bomb->b);
            window.draw(ptr[type][i].enemy);
        }

     if(type >= 3){
    for(int i=0; i<1; i++){
        window.draw(ptr[type][i].enemy);
        for(int j=0; j<3; j++)
        {
            ptr[type][i].bomb[j].move();
            
            window.draw(ptr[type][i].bomb[j].b);  
        }
    }
     }
    
    //window.draw(ptr->enemy2);
    //window.draw(p->bt2->bullet);
            
    window.display();


    }
    
}


};
