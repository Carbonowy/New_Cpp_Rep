#include <iostream>
#include <curses.h>
#include <cctype>
#include <cstdlib>
#include "drawing.h"
using namespace std;

auto function = new drawing();

int main()
{
    

    snaketier *Head;
    Head = new snaketier;
    Head -> next = NULL;

    Head -> x = 10; 
    Head -> y = 5;

    function -> SnakeHead = Head;

    function -> Fruit -> Fx = function->RandomNumberGenerator(20);
    function -> Fruit -> Fy = function->RandomNumberGenerator(10);
    mvwaddch(function -> win, function -> Fruit -> Fy, function -> Fruit -> Fx, 'F');

    bool firstmove = false;

	char ch = 'o';
    
    function -> setSkin(ch);

    function -> showThecoordinates(firstmove);

    bool WasFruitEaten = false;
   
    initscr();
    function -> creating_the_map();

    noecho(); 
    
    while(true)
	{
        if(!firstmove)
        {
            ch = getch();
            noecho();
            cbreak();
            tolower(ch);
            firstmove = true;
        }

               

        switch(ch)
        {
            case 'w': ch = function->moveup(WasFruitEaten); break;
            case 's': ch = function->movedown(WasFruitEaten); break;
            case 'a': ch = function->moveleft(WasFruitEaten); break;
            case 'd': ch = function->moveright(WasFruitEaten); break;
            default: break;
        }

        if(WasFruitEaten == true)
        {

        }
    }

    endwin();
    return 0;
}

