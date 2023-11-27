#include <iostream>
using namespace std;

int vf[2];
int vc[3];

void mov_U(int c[6][3][3])
{
    //costado
    int j=0;
    for(int i=2; i>=0; i--)
    {
        vc[i]=c[1][i][2];
        c[1][i][2]=c[2][2][j];
        c[2][2][j]=c[3][j][0];
        c[3][j][0]=c[4][2][j];
        c[4][2][j]=vc[i];
        j++;
    }
    //frente
    j=2;
    for(int i=0; i<2; i++)
    {
        vf[i]=c[5][0][i];
        c[5][0][i]=c[5][j][0];
        c[5][j][0]=c[5][2][j];
        c[5][2][j]=c[5][i][2];
        c[5][i][2]=vf[i];
        j--;
    }
}
void mov_u(int c[6][3][3])
{
    //costado
    int j=0;
    for(int i=2; i>=0; i--)
    {
        vc[i]=c[1][i][2];
        c[1][i][2]=c[4][2][j];
        c[4][2][j]=c[3][j][0];
        c[3][j][0]=c[2][2][j];
        c[2][2][j]=vc[i];
        j++;
    }
    //frente
    j=2;
    for(int i=0; i<2; i++)
    {
        vf[i]=c[5][0][i];
        c[5][0][i]=c[5][i][2];
        c[5][i][2]=c[5][2][j];
        c[5][2][j]=c[5][j][0];
        c[5][j][0]=vf[i];
        j--;
    }
}

void mov_D(int c[6][3][3])
{
    //costados
    int j=2;
    for(int i=0; i<3; i++)
    {
        vc[i]=c[1][i][0];
        c[1][i][0]=c[4][0][j];
        c[4][0][j]=c[3][j][2];
        c[3][j][2]=c[2][0][j];
        c[2][0][j]=vc[i];
        j--;
    }
    //frente
    j=2;
    for(int i=0; i<2; i++)
    {
        vf[i]=c[0][0][i];
        c[0][0][i]=c[0][j][0];
        c[0][j][0]=c[0][2][j];
        c[0][2][j]=c[0][i][2];
        c[0][i][2]=vf[i];
        j--;
    }
}
void mov_d(int c[6][3][3])
{
    //costados
    int j=2;
    for(int i=0; i<3; i++)
    {
        vc[i]=c[1][i][0];
        c[1][i][0]=c[2][0][j];
        c[2][0][j]=c[3][j][2];
        c[3][j][2]=c[4][0][j];
        c[4][0][j]=vc[i];
        j--;
    }
    //frente
    j=2;
    for(int i=0; i<2; i++)
    {
        vf[i]=c[0][0][i];
        c[0][0][i]=c[0][i][2];
        c[0][i][2]=c[0][2][j];
        c[0][2][j]=c[0][j][0];
        c[0][j][0]=vf[i];
        j--;
    }
}

void mov_E(int c[6][3][3])
{
    int j=2;
    for(int i=0; i<3; i++)
    {
        vc[i]=c[1][i][1];
        c[1][i][1]=c[4][1][j];
        c[4][1][j]=c[3][j][1];
        c[3][j][1]=c[2][1][j];
        c[2][1][j]=vc[i];
        j--;
    }
}
void mov_e(int c[6][3][3])
{
    int j=2;
    for(int i=0; i<3; i++)
    {
        vc[i]=c[1][i][1];
        c[1][i][1]=c[2][1][j];
        c[2][1][j]=c[3][j][1];
        c[3][j][1]=c[4][1][j];
        c[4][1][j]=vc[i];
        j--;
    }
}

void mov_L(int c[6][3][3])
{
    //costado
    int j=0;
    for(int i=2; i>=0; i--)
    {
        vc[i]=c[4][i][2];
        c[4][i][2]=c[5][2][j];
        c[5][2][j]=c[2][j][0];
        c[2][j][0]=c[0][2][j];
        c[0][2][j]=vc[i];
        j++;
    }
    //frente
    j=2;
    for(int i=0; i<2; i++)
    {
        vf[i]=c[3][0][i];
        c[3][0][i]=c[3][j][0];
        c[3][j][0]=c[3][2][j];
        c[3][2][j]=c[3][i][2];
        c[3][i][2]=vf[i];
        j--;
    }
}
void mov_l(int c[6][3][3])
{
    //costado
    int j=0;
    for(int i=2; i>=0; i--)
    {
        vc[i]=c[4][i][2];
        c[4][i][2]=c[0][2][j];
        c[0][2][j]=c[2][j][0];
        c[2][j][0]=c[5][2][j];
        c[5][2][j]=vc[i];
        j++;
    }
    //frente
    j=2;
    for(int i=0; i<2; i++)
    {
        vf[i]=c[3][0][i];
        c[3][0][i]=c[3][i][2];
        c[3][i][2]=c[3][2][j];
        c[3][2][j]=c[3][j][0];
        c[3][j][0]=vf[i];
        j--;
    }
}

void mov_R(int c[6][3][3])
{
    //costados
    int j=2;
    for(int i=0; i<3; i++)
    {
        vc[i]=c[4][i][0];
        c[4][i][0]=c[0][0][j];
        c[0][0][j]=c[2][j][2];
        c[2][j][2]=c[5][0][j];
        c[5][0][j]=vc[i];
        j--;
    }
    //frente
    j=2;
    for(int i=0; i<2; i++)
    {
        vf[i]=c[1][0][i];
        c[1][0][i]=c[1][j][0];
        c[1][j][0]=c[1][2][j];
        c[1][2][j]=c[1][i][2];
        c[1][i][2]=vf[i];
        j--;
    }
}
void mov_r(int c[6][3][3])
{
    //costados
    int j=2;
    for(int i=0; i<3; i++)
    {
        vc[i]=c[4][i][0];
        c[4][i][0]=c[5][0][j];
        c[5][0][j]=c[2][j][2];
        c[2][j][2]=c[0][0][j];
        c[0][0][j]=vc[i];
        j--;
    }
    //frente
    j=2;
    for(int i=0; i<2; i++)
    {
        vf[i]=c[1][0][i];
        c[1][0][i]=c[1][i][2];
        c[1][i][2]=c[1][2][j];
        c[1][2][j]=c[1][j][0];
        c[1][j][0]=vf[i];
        j--;
    }
}

void mov_M(int c[6][3][3])
{
    int j=0;
    for(int i=2; i>=0; i--)
    {
        vc[i]=c[4][i][1];
        c[4][i][1]=c[5][1][j];
        c[5][1][j]=c[2][j][1];
        c[2][j][1]=c[0][1][j];
        c[0][1][j]=vc[i];
        j++;
    }
}
void mov_m(int c[6][3][3])
{
    int j=0;
    for(int i=2; i>=0; i--)
    {
        vc[i]=c[4][i][1];
        c[4][i][1]=c[0][1][j];
        c[0][1][j]=c[2][j][1];
        c[2][j][1]=c[5][1][j];
        c[5][1][j]=vc[i];
        j++;
    }
}

void mov_F(int c[6][3][3])
{
    //costados
    int j=2;
    for(int i=0; i<3; i++)
    {
        vc[i]=c[0][i][0];
        c[0][i][0]=c[1][0][j];
        c[1][0][j]=c[5][j][2];
        c[5][j][2]=c[3][0][j];
        c[3][0][j]=vc[i];
        j--;
    }
    //frente
    j=2;
    for(int i=0; i<2; i++)
    {
        vf[i]=c[4][0][i];
        c[4][0][i]=c[4][j][0];
        c[4][j][0]=c[4][2][j];
        c[4][2][j]=c[4][i][2];
        c[4][i][2]=vf[i];
        j--;
    }
}
void mov_f(int c[6][3][3])
{
    //costados
    int j=2;
    for(int i=0; i<3; i++)
    {
        vc[i]=c[0][i][0];
        c[0][i][0]=c[3][0][j];
        c[3][0][j]=c[5][j][2];
        c[5][j][2]=c[1][0][j];
        c[1][0][j]=vc[i];
        j--;
    }
    //frente
    j=2;
    for(int i=0; i<2; i++)
    {
        vf[i]=c[4][0][i];
        c[4][0][i]=c[4][i][2];
        c[4][i][2]=c[4][2][j];
        c[4][2][j]=c[4][j][0];
        c[4][j][0]=vf[i];
        j--;
    }
}

void mov_B(int c[6][3][3])
{
    //costado
    int j=0;
    for(int i=2; i>=0; i--)
    {
        vc[i]=c[0][i][2];
        c[0][i][2]=c[3][2][j];
        c[3][2][j]=c[5][j][0];
        c[5][j][0]=c[1][2][j];
        c[1][2][j]=vc[i];
        j++;
    }
    //frente
    j=2;
    for(int i=0; i<2; i++)
    {
        vf[i]=c[2][0][i];
        c[2][0][i]=c[2][j][0];
        c[2][j][0]=c[2][2][j];
        c[2][2][j]=c[2][i][2];
        c[2][i][2]=vf[i];
        j--;
    }
}
void mov_b(int c[6][3][3])
{
    //costado
    int j=0;
    for(int i=2; i>=0; i--)
    {
        vc[i]=c[0][i][2];
        c[0][i][2]=c[1][2][j];
        c[1][2][j]=c[5][j][0];
        c[5][j][0]=c[3][2][j];
        c[3][2][j]=vc[i];
        j++;
    }
    //frente
    j=2;
    for(int i=0; i<2; i++)
    {
        vf[i]=c[2][0][i];
        c[2][0][i]=c[2][i][2];
        c[2][i][2]=c[2][2][j];
        c[2][2][j]=c[2][j][0];
        c[2][j][0]=vf[i];
        j--;
    }
}
