#include "drawing.h"
#include <thread>

drawing::drawing()
{
    
}

void drawing::showThecoordinates(int x_, int y_)
{
    for(int i=0; i<=X+1; i++) cout<<'#';
    
    cout<<"\n";
    
    for(int i=0; i<=Y; i++)
    {
       
        for(int i=0; i<=X+1; i++) cout<<'\b'; cout<<'#';
 
        if(i == y_)
        {
            for(int j=0; j<=X; j++)
            {
                if(j == x_) cout<<skin;
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

        

        cout<<"\n";
    }

    for(int i=0; i<=X+1; i++) cout<<'\b';

    for(int i=0; i<=X+1; i++) cout<<'#';

    cout<<"\n";
}

char drawing::moveup(int& x_, int& y_)
{   
    static bool f = false;
    char ch;

    if(y_-1 >= 0)
    {
        thread wait([&](){
              
                while(!f && y_-1 >= 0)
                {        
                  
                    y_--;
                    system("clear");
                    showThecoordinates(x_, y_);
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
        showThecoordinates(x_, y_);
    }

    return ch;
}

char drawing::movedown(int& x_, int& y_)
{
    static bool f = false;
    static char ch;

    if(y_+1 <= Y)
    {
        thread wait([&](){
            
                while(!f && y_+1 <= Y)
                {       
                    y_++;
                    system("clear");
                    showThecoordinates(x_, y_);
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
        showThecoordinates(x_, y_);
    }
    
    return ch;
}

char drawing::moveleft(int& x_, int& y_)
{
    static bool f = false;
    static char ch;

    if(x_-1 > 0)
    {
        thread wait([&](){
            

            while(!f && x_-1 > 0)
            {       
                x_--;
                system("clear");
                showThecoordinates(x_, y_);
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
        showThecoordinates(x_, y_);
    }

    return ch;
}

char drawing::moveright(int& x_, int& y_)
{
    static bool f = false;
    static char ch;

    if(x_+1 < X)
    {
        thread wait([&](){
            

                while(!f && x_+1 < X)
                {       
                    x_++;
                    system("clear");
                    showThecoordinates(x_, y_);
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
        showThecoordinates(x_, y_);
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

    a = rand()%a_+1;

    return a;
}

drawing::~drawing()
{

}
