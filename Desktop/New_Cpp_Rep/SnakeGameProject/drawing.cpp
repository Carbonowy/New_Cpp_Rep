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
        Fruit -> Fx = RandomNumberGenerator(20);
        Fruit -> Fy = RandomNumberGenerator(10);
        Points += 10;
        fruitflag_ = true;
    }
    
    for(int i=0; i<5; i++) cout<<' ';
    cout<<"Points: "<<Points;
    for(int i=0; i<6; i++) cout<<' ';

    cout<<"\n";
    
    for(int i=0; i<=X+1; i++) cout<<'#';
    
    cout<<"\n";
    
    for(int i=0; i<=Y; i++)
    {
       
        for(int i=0; i<=X+1; i++) cout<<'\b'; cout<<'#';
 
        if(i == SnakeHead -> y)
        {
            if(i == Fruit -> Fy && Fruit -> Fx != SnakeHead -> x)
            {
                for(int j=0; j<=X; j++)
                {
                    if(j == Fruit -> Fx) cout<<'F';
                    else if(j == SnakeHead -> x) cout<<skin;
                    else if( j != X ) cout<<" ";
                }
                cout<<"#";
            }
            else
            {
                for(int j=0; j<=X; j++)
                {
                    if(j == SnakeHead -> x) cout<<skin;
                    else if( j != X ) cout<<" ";
                    else cout<<"#";
                }
            }   
        }
        else
        {
            if(i == Fruit -> Fy && Fruit -> Fy != SnakeHead -> y)
            {
                for(int j=0; j<=X; j++)
                {
                    if(j == Fruit -> Fx) cout<<'F';
                    else if( j != X ) cout<<" ";
                    else cout<<"#";
                }
            }
            else
            {
                for(int j=0; j<=X; j++)
                {
                    if(j != X) cout<<" ";
                    else cout<<'#';
                }
            }
        }

        
        cout<<"\n";
    }

    for(int i=0; i<=X+1; i++) cout<<'\b';

    for(int i=0; i<=X+1; i++) cout<<'#';

    cout<<"\n";

    
}

char drawing::moveup(bool &fruitflag_)
{   
    static bool f = false;
    char ch;

    if(SnakeHead -> y - 1 >= 0)
    {
        thread wait([&](){
              
                while(!f && SnakeHead -> y - 1 >= 0)
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
            
                while(!f && SnakeHead -> y + 1 <= Y)
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
            

                while(!f && SnakeHead -> x + 1 < X)
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
