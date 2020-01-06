#include "drawing.h"
#include <thread>

drawing::drawing()
{
    Fruit = new fruit;
    IsFruitEaten = false;
}

void drawing::showThecoordinates(bool &fruitflag_)
{
    if(SnakeHead -> x == Fruit -> Fx && SnakeHead -> y == Fruit -> Fy)
    {
        Fruit -> Fx = RandomNumberGenerator(19);
        Fruit -> Fy = RandomNumberGenerator(9);
        Points += 10;
        fruitflag_ = true;
    }

    for(int i=0; i<5; i++) cout<<' ';
    cout<<"Points: "<<Points;
    for(int i=0; i<6; i++) cout<<' ';

    cout<<"\n";

    snaketier *tmp;
    tmp = SnakeHead;


    char charmap[Y][X];

    for(int i=0; i<Y; i++)
    {
        for(int j=0; j<X; j++) 
        {
            charmap[i][j] = ' ';
        }
    }


    for(int i=0; i<X; i++) charmap[0][i] = '#'; 

    for(int i=1; i<Y-1; i++)
    {
        charmap[i][0] = '#';
        charmap[i][X-1] = '#';
    } 

    for(int i=0; i<X; i++) charmap[Y-1][i] = '#'; 
 
   
    charmap[SnakeHead->y][SnakeHead->x] = 'o';
    charmap[Fruit->Fy][Fruit->Fx] = 'F';
    
    /*
    while(tmp != NULL)
    {  
        tmp = tmp -> next;
    }
    */
   
    for(int i=0; i<Y; i++)
    {
        for(int i=0; i<=X+1; i++) cout<<'\b';

        for(int j=0; j<X; j++)
        {
            cout<<charmap[i][j];
        }
        cout<<"\n";
    }
    

    for(int i=0; i<=X+1; i++) cout<<'\b';

    //for(int i=0; i<=X; i++) cout<<'#';

    cout<<"\n";

    
}

char drawing::moveup(bool &fruitflag_)
{   
    static bool f = false;
    char ch;

    if(SnakeHead -> y - 1 >= 0)
    {
        thread wait([&](){

                while(!f && SnakeHead -> y - 1 > 0)
                {        
                    SnakeHead -> y--;
                    system("clear");
                    showThecoordinates(fruitflag_);
                    sleep(1);
                }
                
            });

        initscr();
   
        ch = getch();
        
            f = true;
            wait.join();

        f = false;

        system("clear");
    }
    else
    {
        system("clear");
        showThecoordinates(fruitflag_);
    }

    return ch;
}

char drawing::movedown(bool &fruitflag_)
{
    static bool f = false;
    static char ch;

    if(SnakeHead -> y + 1 <= Y)
    {
        thread wait([&](){
            
                while(!f && SnakeHead -> y + 1 < Y-1)
                {       
                    SnakeHead -> y++;
                    system("clear");
                    showThecoordinates(fruitflag_);
                    sleep(1);
                }
           
            
            });

        initscr();

        ch = getch();
        
            f = true;
            wait.join();
        
        system("clear");
        f = false;
    }
    else
    {
        system("clear");
        showThecoordinates(fruitflag_);
    }
    
    return ch;
}

char drawing::moveleft(bool &fruitflag_)
{
    static bool f = false;
    static char ch;

    if(SnakeHead -> x - 1 > 0)
    {
        thread wait([&](){
            

            while(!f && SnakeHead -> x - 1 > 0)
            {       
                SnakeHead -> x--;
                system("clear");
                showThecoordinates(fruitflag_);
                sleep(1);
            
            }
        
            
            });

        initscr();

        ch = getch();
       
            f = true;
            wait.join();

        system("clear");
        f = false;

    }
    else
    {
        system("clear");
        showThecoordinates(fruitflag_);
    }

    return ch;
}

char drawing::moveright(bool &fruitflag_)
{
    static bool f = false;
    static char ch;

    if(SnakeHead -> x + 1 < X)
    {
        thread wait([&](){
            

                while(!f && SnakeHead -> x + 1 < X-1)
                {       
                    SnakeHead -> x++;
                    system("clear");
                    showThecoordinates(fruitflag_);
                    sleep(1);
                }
            
            });

        initscr();
        
        ch = getch();
        
            f = true;
            wait.join();

        system("clear");
        f = false;

    }
    else
    {
        system("clear");
        showThecoordinates(fruitflag_);
    }

    return ch;
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
