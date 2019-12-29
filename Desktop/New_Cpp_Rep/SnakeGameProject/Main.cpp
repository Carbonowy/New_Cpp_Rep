#include <iostream>
#include <curses.h>
#include <cctype>
#include <cstdlib>
#include <vector> 
#include "drawing.h"
using namespace std;

auto function = new drawing();

int main()
{
    vector<snaketier> Snake;

    Snake.push_back({10, 5});
    
    function -> Fruit -> Fx = function->RandomNumberGenerator(20);
    function -> Fruit -> Fy = function->RandomNumberGenerator(10);

    bool firstmove = false;

	char ch = 'o';
    
    function -> setSkin(ch);

    function -> showThecoordinates(Snake.begin()->x,Snake.begin()->y);

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
            case 'w': ch = function->moveup(Snake.begin()->x, Snake.begin()->y); break;
            case 's': ch = function->movedown(Snake.begin()->x, Snake.begin()->y); break;
            case 'a': ch = function->moveleft(Snake.begin()->x,Snake.begin()->y); break;
            case 'd': ch = function->moveright(Snake.begin()->x, Snake.begin()->y); break;
            default: break;
        }    
    }

    return 0;
}

