#ifndef DRAWING_H
#define DRAWING_H
#include <iostream>
#include <curses.h>
#include <cctype>
#include <cstdlib>
#include <unistd.h>
#include <thread>
using namespace std;

class drawing
{
    private:
        const int X = 20, Y = 10;
        char skin;
    public:

        drawing();
        ~drawing();
        char moveup(int& _x, int& _y);
        char moveleft(int& _x, int& _y);
        char movedown(int& _x, int& _y);
        char moveright(int& _x, int& _y);
        int RandomNumberGenerator(int _a);
        void showThecoordinates(int _x, int _y);
        void setSkin(char _ch);

};

#endif