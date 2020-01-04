#ifndef DRAWING_H
#define DRAWING_H
#include <iostream>
#include <curses.h>
#include <cctype>
#include <cstdlib>
#include <unistd.h>
#include <thread>
using namespace std;

struct snaketier
{
    int x;
    int y;
    int speed = 1;
    char texture = 'O'; 
    snaketier *next;
};

struct fruit
{
    int Fx;
    int Fy;
    int points = 10;
    int timeofexistance = 10;
    int MyNumber = 0;
};


class drawing
{
    private:
        const int X = 20, Y = 10;
        char skin;
    
    public:
        fruit *Fruit;
        snaketier *SnakeHead;
        bool IsFruitEaten;
        int Points = 0;
        

        drawing();

        char moveup(bool &_fruitflag);
        char moveleft(bool &_fruitflag);
        char movedown(bool &_fruitflag);
        char moveright(bool &_fruitflag);
        int RandomNumberGenerator(int _a);
        void showThecoordinates(bool &_fruitflag);
        void setSkin(char _ch);

        ~drawing();
};

#endif