#include <iostream>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "movimientos.h"

// 43x38
void mostrar_cubo(int x, int y)
{
    char cubo[43][39]=
    {
        "------------------NN------------------",
        "----------------NN--NN----------------",
        "--------------NN------NN--------------",
        "------------NN----------NN------------",
        "----------NN--NN------NN--NN----------",
        "--------NN------NN--NN------NN--------",
        "------NN----------NN----------NN------",
        "----NN--NN------NN--NN------NN--NN----",
        "--NN------NN--NN------NN--NN------NN--",
        "NN----------NN----------NN----------NN",
        "N-NN------NN--NN------NN--NN------NN-N",
        "N---NN--NN------NN--NN------NN--NN---N",
        "N-----NN----------NN----------NN-----N",
        "N-----N-NN------NN--NN------NN-N-----N",
        "N-----N---NN--NN------NN--NN---N-----N",
        "N-----N-----NN----------NN-----N-----N",
        "N-----N-----N-NN------NN-N-----N-----N",
        "NN----N-----N---NN--NN---N-----N----NN",
        "N-NN--N-----N-----NN-----N-----N--NN-N",
        "N---NNN-----N-----N------N-----NNN---N",
        "N-----NN----N-----N------N----NN-----N",
        "N-----N-NN--N-----N------N--NN-N-----N",
        "N-----N---NNN-----N------NNN---N-----N",
        "N-----N-----NN----N-----NN-----N-----N",
        "N-----N-----N-NN--N---NN-N-----N-----N",
        "NN----N-----N---NNN-NN---N-----N----NN",
        "N-NN--N-----N-----NN-----N-----N--NN-N",
        "N---NNN-----N-----N------N-----NNN---N",
        "N-----NN----N-----N------N----NN-----N",
        "N-----N-NN--N-----N------N--NN-N-----N",
        "N-----N---NNN-----N------NNN---N-----N",
        "N-----N-----NN----N-----NN-----N-----N",
        "N-----N-----N-NN--N---NN-N-----N-----N",
        "NN----N-----N---NNN-NN---N-----N----NN",
        "--NN--N-----N-----NN-----N-----N--NN--",
        "----NNN-----N-----N------N-----NNN----",
        "------NN----N-----N------N----NN------",
        "--------NN--N-----N------N--NN--------",
        "----------NNN-----N------NNN----------",
        "------------NN----N-----NN------------",
        "--------------NN--N---NN--------------",
        "----------------NNN-NN----------------",
        "------------------NN------------------"
    };

    for (int i=0; i<43; i++)
    {
        for (int j=0; j<38; j++)
        {
            if(cubo[i][j]!='-')
            {
                gotoxy(j+x,i+y);
                switch (cubo[i][j])
                {
                case 'N':
                    setColor(BLACK);
                    break;
                }
                cout<<(char)219;
            }
        }
    }
}

void pintar(int color[][11], int fil, int col, int x, int y, int wea)
{
    for (int i=0; i<fil; i++)
    {
        for (int j=0; j<col; j++)
        {
            if(wea==0)
            {
                if(color[i][j]!=9)
                {
                    gotoxy(j+x,i+y);
                    switch (color[i][j])
                    {
                    case 0:
                        ///197,15,31
                        setColor(RED);
                        break;
                    case 1:
                        setColor(WHITE);
                        break;
                    case 2:
                        ///0,55,218
                        setColor(BLUE);
                        break;
                    case 3:
                        ///255,255,0
                        setColor(YELLOW);
                        break;
                    case 4:
                        ///22,198,12
                        setColor(LIGHTGREEN);
                        break;
                    case 5:
                        ///255,128,0
                        //setColor(LIGHTRED);
                        setColor(MAGENTA);
                        break;
                    }
                    cout<<(char)219;
                }
            }
            else if(j!=0)
            {
                if(color[i][j]!=9)
                {
                    gotoxy(j+x,i+y);
                    switch (color[i][j])
                    {
                    case 0:
                        setColor(RED);
                        break;
                    case 1:
                        setColor(WHITE);
                        break;
                    case 2:
                        setColor(BLUE);
                        break;
                    case 3:
                        setColor(YELLOW);
                        break;
                    case 4:
                        setColor(LIGHTGREEN);
                        break;
                    case 5:
                        //setColor(LIGHTRED);
                        setColor(MAGENTA);
                        break;
                    }
                    cout<<(char)219;
                }
            }
        }
    }
}

void mostrar_cara_a(int c, int x, int y)
{
    int fil=5,col=11;
    int color[5][11]=
    {
        {9,9,9,9,9,c,c,9,9,9,9},
        {9,9,9,c,c,c,c,c,c,9,9},
        {9,c,c,c,c,c,c,c,c,c,c},
        {9,9,9,c,c,c,c,c,c,9,9},
        {9,9,9,9,9,c,c,9,9,9,9},
    };

    pintar(color, fil, col, x, y, 1);
}

void mostrar_cara_i(int c, int x, int y)
{
    int fil=9,col=6;
    int color[9][11]=
    {
        {9,c,9,9,9,9},
        {9,c,c,c,9,9},
        {9,c,c,c,c,c},
        {9,c,c,c,c,c},
        {9,c,c,c,c,c},
        {9,c,c,c,c,c},
        {9,c,c,c,c,c},
        {9,9,c,c,c,c},
        {9,9,9,9,c,c},
    };

    pintar(color, fil, col, x, y, 0);
}

void mostrar_cara_d(int c, int x, int y, int wea)
{
    int fil=10,col=6;
    int color[10][11]=
    {
        {9,9,9,9,9,c},
        {9,9,9,c,c,c},
        {9,c,c,c,c,c},
        {c,c,c,c,c,c},
        {c,c,c,c,c,c},
        {c,c,c,c,c,c},
        {c,c,c,c,c,c},
        {c,c,c,c,c,9},
        {c,c,c,9,9,9},
        {c,9,9,9,9,9},
    };

    pintar(color, fil, col, x, y, wea);
}

void movimiento(int mov, int c[6][3][3])
{

    switch(mov)
    {
    case 106:
        mov_U(c);
        break;
    case 102:
        mov_u(c);
        break;
    case 97:
        mov_D(c);
        break;
    case 164:
        mov_d(c);
        break;
    case 118:
        mov_E(c);
        break;
    case 110:
        mov_e(c);
        break;
    case 115:
        mov_L(c);
        break;
    case 100:
        mov_l(c);
        break;
    case 107:
        mov_R(c);
        break;
    case 108:
        mov_r(c);
        break;
    case 103:
        mov_M(c);
        break;
    case 104:
        mov_m(c);
        break;
    case 109:
        mov_F(c);
        break;
    case 99:
        mov_f(c);
        break;
    case 101:
        mov_B(c);
        break;
    case 105:
        mov_b(c);
        break;

    case 14:
        mov_l(c);
        mov_m(c);
        mov_R(c);
        break;
    case 15:
        mov_L(c);
        mov_M(c);
        mov_r(c);
        break;
    case 16:
        mov_U(c);
        mov_e(c);
        mov_d(c);
        break;
    case 17:
        mov_u(c);
        mov_E(c);
        mov_D(c);
        break;
    }
}

void mov_mezcla(int mov, int c[6][3][3])
{
    switch(mov)
    {
    case 1:
        mov_U(c);
        break;
    case 2:
        mov_u(c);
        break;
    case 3:
        mov_D(c);
        break;
    case 4:
        mov_d(c);
        break;
    case 5:
        mov_L(c);
        break;
    case 6:
        mov_l(c);
        break;
    case 7:
        mov_R(c);
        break;
    case 8:
        mov_r(c);
        break;
    case 9:
        mov_F(c);
        break;
    case 10:
        mov_f(c);
        break;
    case 11:
        mov_B(c);
        break;
    case 12:
        mov_b(c);
        break;
    }
}
