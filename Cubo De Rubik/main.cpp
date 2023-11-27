#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
#include "funciones.h"
#include "rlutil.h"
using namespace rlutil;

int colores[6][3][3]=
{
    {
        0,0,0,
        0,0,0,
        0,0,0
    },
    {
        1,1,1,
        1,1,1,
        1,1,1
    },
    {
        2,2,2,
        2,2,2,
        2,2,2
    },
    {
        3,3,3,
        3,3,3,
        3,3,3
    },
    {
        4,4,4,
        4,4,4,
        4,4,4
    },
    {
        5,5,5,
        5,5,5,
        5,5,5
    }
};

void cara_a(int ca, int x, int y)
{
    x+=1;
    y+=7;

    for(int i=2; i>=0; i--)
    {
        for(int j=2; j>=0; j--)
        {
            mostrar_cara_a(colores[ca][i][j], x, y);
            x+=6;
            y-=3;
        }
        x-=12;
        y+=12;
    }
}

void cara_i(int ci, int x, int y)
{
    y+=10;

    for(int i=2; i>=0; i--)
    {
        for(int j=2; j>=0; j--)
        {
            mostrar_cara_i(colores[ci][i][j], x, y);
            x+=6;
            y+=3;
        }
        x-=18;
        y-=1;
    }
}

void cara_d(int cd, int x, int y)
{
    x+=19;
    y+=16;
    for(int j=2; j>=0; j--)
    {
        for(int i=0; i<3; i++)
        {
            if(i==0)
            {
                mostrar_cara_d(colores[cd][i][j], x, y, 0);
            }
            else
            {
                mostrar_cara_d(colores[cd][i][j], x, y, 1);
            }
            x+=6;
            y-=3;
        }
        x-=18;
        y+=17;
    }
}

void cubo_de_rubik(int x, int y, int ca, int ci, int cd)
{
    mostrar_cubo(x, y);
    cara_a(ca, x, y);
    cara_i(ci, x, y);
    cara_d(cd, x, y);
}

void mezcla()
{
    int mov;
    mov = 1 + rand() % (12 - 1);
    mov_mezcla(mov, colores);
}

int main()
{

        system("mode con: cols=500 lines=500");
    srand(time(NULL));
    system("color B0");

    int mov;
    int x=20,y=10;
    int ca=5,ci=4,cd=1;

    gotoxy(20, 10);
    anykey("pulsa una tecla para empezar");
    cls();
    for(int i=1; i<=35; i++)
    {
        hidecursor();
        cubo_de_rubik(x, y, ca, ci, cd);
        mezcla();
    }
    while(true)
    {
        hidecursor();
        cubo_de_rubik(x, y, ca, ci, cd);
        mov=getkey();
        movimiento(mov, colores);
    }

}

