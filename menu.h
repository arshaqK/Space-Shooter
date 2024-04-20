
#include "game.h"
const char title2[] = "OOP-Proj, Spring-2023";
class Menu{
public:
    Texture mTex;
    Sprite menu;
    Texture iTex;
    Sprite inst;
//add menu attributes here
Menu()
{
    mTex.loadFromFile("img/menu1.png");
    menu.setTexture(mTex);
    menu.setScale(0.24,0.24);

//constructors body
}

void display_menu()

{
    RenderWindow window(VideoMode(780, 780), title);
    while (window.isOpen()){
        window.clear(Color::Black);
        window.draw(menu); 

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::S))
        {   Game g; 
            g.start_game(window);
        }
        if(Keyboard::isKeyPressed(Keyboard::I))
        {   
            iTex.loadFromFile("img/instructions.png");
            inst.setTexture(iTex);
            inst.setScale(1.01,1.01);
            
        }
        
window.draw(inst);
        window.display();
    }
//display menu screen here
    
// add functionality of all the menu options here

//if Start game option is chosen 
         




}


};
