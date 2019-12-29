#include <iostream>
#include <curses.h>
#include <cctype>
#include <cstdlib>
#include <vector> 
#include "drawing.h"
using namespace std;

auto function = new drawing();

struct snaketier
{
    int x;
    int y;
    int speed = 1;
    char texture = 'O'; 
};

struct fruit
{
    int Fx;
    int Fy;
    int points = 10;
    int timeofexistance = 10;
    int MyNumber = 0;
};

int main()
{
    vector<snaketier> Snake;
    vector<fruit> Fruits; 

    Snake.push_back({10, 5});
    Fruits.push_back({function->RandomNumberGenerator(20), function->RandomNumberGenerator(10)});
     



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
            case 'w': ch = function->moveup(Snake.begin()->x,Snake.begin()->y); break;
            case 's': ch = function->movedown(Snake.begin()->x, Snake.begin()->y); break;
            case 'a': ch = function->moveleft(Snake.begin()->x,Snake.begin()->y); break;
            case 'd': ch = function->moveright(Snake.begin()->x, Snake.begin()->y); break;
            default: break;
        }    


    }

 

    return 0;
}

