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

    function -> SnakeHead = Head;

    function -> Fruit -> Fx = function->RandomNumberGenerator(20);
    function -> Fruit -> Fy = function->RandomNumberGenerator(10);

    bool firstmove = false;

	char ch = 'o';
    
    function -> setSkin(ch);

    function -> showThecoordinates(firstmove);

    bool WasFruitEaten = false;

    while(true)
	{
        if(!firstmove)
        {
            initscr();
            ch = getch();
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

    return 0;
}

