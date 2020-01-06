#include <iostream>
#include <curses.h>
#include <cctype>
#include <cstdlib>
#include "drawing.h"
using namespace std;

auto function = new drawing();

int main()
{
    snaketier *Head, *tmp1, *tmp2;
    Head = new snaketier;
    Head -> next = NULL;

    Head -> x = 10; 
    Head -> y = 5;

    tmp1 = Head;
    tmp2 = Head;

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
            tmp1 = new snaketier;
            tmp2 -> next = tmp1;
            tmp1 -> next = NULL;
            
            switch (ch)
            {
                case 'w': tmp1 -> y = tmp2 -> y--; break;
                case 's': tmp1 -> y = tmp2 -> y++; break;
                case 'a': tmp1 -> x = tmp2 -> x--; break;
                case 'd': tmp1 -> x = tmp2 -> x++; break;
                default: break;
            }
            
            tmp2 = tmp1;

            WasFruitEaten = false;   
        }

    }

    return 0;
}

