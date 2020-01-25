#include "drawing.h"
#include <thread>

drawing::drawing()
{
    Fruit = new fruit;
    IsFruitEaten = false;

    initscr();
    win = newwin(Y,X,0,0);
}

void drawing::creating_the_map()
{
    string s = "POINTS:";

    for(int i=5; i<=11; i++)
    {
        mvwaddch(win, 0, i, s[i-5]);
    }

    for(int i=0; i<20; i++)
    {
        mvwaddch(win, 2, i, '#');
    }
    
    for(int i=0; i<20; i++)
    {
        mvwaddch(win, 11, i, '#');
    }

    for(int i=3; i<=11; i++)
    {
        mvwaddch(win, i, 0, '#');
        mvwaddch(win, i, 19, '#');
    }
}

void drawing::showThecoordinates(bool &fruitflag_)
{
    if(SnakeHead -> x == Fruit -> Fx && SnakeHead -> y == Fruit -> Fy)
    {
        mvwaddch(win, Fruit -> Fy, Fruit -> Fx, ' ');

        Fruit -> Fx = RandomNumberGenerator(19);
        Fruit -> Fy = RandomNumberGenerator(9);

        mvwaddch(win, Fruit -> Fy, Fruit -> Fx, 'F');

        Points += 10;
        fruitflag_ = true;
    }
    
    snaketier *tmp = SnakeHead;
    
    while(tmp != NULL) tmp = tmp -> next;

    mvwaddch(win, tmp -> y, SnakeHead -> x, 'o');

    
    mvwaddch(win, SnakeHead -> y, SnakeHead -> x, 'o');
    wrefresh(win);
    
}

char drawing::moveup(bool &fruitflag_)
{   
    static bool f = false;
    char ch;
    snaketier *tmp;
    tmp = SnakeHead;

    
    if(SnakeHead -> y - 1 >= 0)
    {
        thread wait([&](){

                while(!f && SnakeHead -> y - 1 > 0)
                {       
                    tmp = SnakeHead;

                    while(tmp != NULL)
                    {

                        tmp -> y--;
                        tmp = tmp -> next;
                    }
                    
                    showThecoordinates(fruitflag_);
                    fruitflag_ = addingnextsnaketier(fruitflag_, 'w');
                    sleep(1);
                }
                
            });

        initscr();
   
        ch = getch();
                
            BendsPointX = SnakeHead -> x;
            BendsPointY = SnakeHead -> y;
        
            f = true;
            wait.join();

        f = false;

    }
    else    showThecoordinates(fruitflag_);
   

    return ch;
}

char drawing::movedown(bool &fruitflag_)
{
    static bool f = false;
    static char ch;
    snaketier *tmp;
    tmp = SnakeHead;


    if(SnakeHead -> y + 1 <= Y)
    {
        thread wait([&](){
            
                while(!f && SnakeHead -> y + 1 < Y-1)
                {       
                    tmp = SnakeHead;

                    while(tmp != NULL)
                    {
                        

                        tmp -> y++;
                        tmp = tmp -> next;
                    }

                    showThecoordinates(fruitflag_);
                    fruitflag_ = addingnextsnaketier(fruitflag_, 's');
                    sleep(1);
                }
           
            
            });

        initscr();

        ch = getch();

            BendsPointX = SnakeHead -> x;
            BendsPointY = SnakeHead -> y;
        
            f = true;
            wait.join();
        
        f = false;
    }
    else    showThecoordinates(fruitflag_);
    
    
    return ch;
}

char drawing::moveleft(bool &fruitflag_)
{
    static bool f = false;
    static char ch;
    snaketier *tmp;
    tmp = SnakeHead;

    if(SnakeHead -> x - 1 > 0)
    {
        thread wait([&](){

            while(!f && SnakeHead -> x - 1 > 0)
            {       
                tmp = SnakeHead;

                while(tmp != NULL)
                {
                    
                    tmp -> x--;
                    tmp = tmp -> next;
                }
                
                showThecoordinates(fruitflag_);
                fruitflag_ = addingnextsnaketier(fruitflag_, 'a');
                sleep(1);
            
            }
        
            
            });

        initscr();

        ch = getch();

            BendsPointX = SnakeHead -> x;
            BendsPointY = SnakeHead -> y;
       
            f = true;
            wait.join();

        f = false;

    }
    else   showThecoordinates(fruitflag_);
    

    return ch;
}

char drawing::moveright(bool &fruitflag_)
{
    static bool f = false;
    static char ch;
    snaketier *tmp;
    tmp = SnakeHead;

    if(SnakeHead -> x + 1 < X)
    {
        thread wait([&](){

                while(!f && SnakeHead -> x + 1 < X-1)
                {       
                    tmp = SnakeHead;

                    while(tmp != NULL)
                    {
                        
                        tmp -> x++;
                        tmp = tmp -> next;
                    }

                    showThecoordinates(fruitflag_);
                    fruitflag_ = addingnextsnaketier(fruitflag_, 'd');
                    sleep(1);
                }
            
            });

        initscr();
        
        ch = getch();

            BendsPointX = SnakeHead -> x;
            BendsPointY = SnakeHead -> y;
        
            f = true;
            wait.join();

        \
        f = false;

    }
    else   showThecoordinates(fruitflag_); 

    return ch;
}

bool drawing::addingnextsnaketier(bool WasFruitEaten, char direction_)
{

    if(WasFruitEaten == true)
    {
        snaketier *tmp1, *tmp2;

        tmp2 = SnakeHead;

        while(tmp2 -> next != NULL)
        {
            tmp2 = tmp2 -> next;
        }


        tmp1 = new snaketier;
        tmp2 -> next = tmp1;
        tmp1 -> next = NULL;
            
        switch (direction_)
        {
            case 'w': tmp1 -> y = tmp2 -> y + 1; tmp1->x = tmp2->x; break;
            case 's': tmp1 -> y = tmp2 -> y - 1; tmp1->x = tmp2->x; break;
            case 'a': tmp1 -> x = tmp2 -> x + 1; tmp1->y = tmp2->y; break;
            case 'd': tmp1 -> x = tmp2 -> x - 1; tmp1->y = tmp2->y; break;
            default: break;
        }
            
        tmp2 = tmp1;

        WasFruitEaten = false;   
    }
    return WasFruitEaten;
}

void drawing::setSkin(char ch_)
{
    skin = ch_;
}

int drawing::RandomNumberGenerator(int a_)
{
    int a;

    srand(time(NULL));

    a = rand()%a_;

    if(a == 0) a++;
 
    return a;
}

drawing::~drawing()
{

}
