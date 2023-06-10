#include <stdio.h>
#include <stdlib.h>
#include "Ciupe_Bogdan_s11_minesweeper.h"



void print(int h, int w, char t[h][w])
{
    printf("  ");
    char s='A';
    for(int i=0; i<w; i++)
    {
        printf("%c",s);
        s+=1;
    }
    printf("  \n");
    int c=1;
    for(int i=0; i<h; i++)
    {
        printf("%d ",c);
        for(int j=0; j<w; j++)
        {
            printf("%c", t[i][j]);
        }
        printf(" %d\n",c);
        c++;
    }
    s='A';
    printf("  ");
    for(int i=0; i<w; i++)
    {
        printf("%c",s);
        s+=1;
    }

}

void create(int nr_bombs, char cols[], int rows[], int h, int w, char t[h][w])
{

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            t[i][j] = '.';
        }
    }

    for(int i=0; i<nr_bombs; i++)
    {
        int ii, jj;
        ii = rows[i] - 1;
        for(int j=0; j<26; j++)
        {
            if( ('A' + j)==cols[i] )
                jj = j;
        }
        t[ii][jj] = 'X';
    }

    char count = '0';
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            count = '0';
            if(i>0 && t[i-1][j] == 'X')
                count = count + 1;
            if(i>0 && j>0 && t[i-1][j-1] == 'X')
                count = count + 1;
            if(i>0 && j<w-1 && t[i-1][j+1] == 'X')
                count = count + 1;
            if(j>0 && t[i][j-1] == 'X')
                count = count + 1;
            if(j<w-1 && t[i][j+1] == 'X')
                count = count + 1;
            if(j>0 && i<h-1 && t[i+1][j-1] == 'X')
                count = count + 1;
            if(i<h-1 && t[i+1][j] == 'X')
                count = count + 1;
            if(j>0 && i<h-1 && t[i+1][j+1] == 'X') //era gresit
                count = count + 1;
            if(count != '0' && t[i][j] != 'X') //modificat
                t[i][j] = count;
        }
    }
}

char** init_state(int h, int w)
{
    char** s = (char**)malloc(h * sizeof(char*));

    for(int i = 0; i < h; i++)
    {
        s[i] = (char*)malloc(w * sizeof(char));
    }

    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            s[i][j] = '?';
        }
    }

    return s;

}

int discover(int i, int j, int h, int w, char t[h][w], char** s)
{
    int ss = 0;
    if(i < 0 || j < 0 || i > h-1 || j > w-1)
        return -2;
    if(t[i][j] == 'X')
        return -1;
    if(s[i][j] == '.')
        return 0;
    if(t[i][j] != '.') //daca e numar
    {
        s[i][j] = '.';
        return 1;

    }
    if(t[i][j] == '.')
    {
        s[i][j] = '.';
        discover(i-1, j, h, w, t, s);
        discover( i-1,  j-1,  h,  w,  t,  s);
        discover( i-1,  j+1,  h,  w,  t,  s);
        discover( i,  j-1,  h,  w,  t,  s);
        discover( i,  j+1,  h,  w,  t,  s);
        discover( i+1,  j,  h,  w,  t,  s);
        discover( i+1,  j-1,  h,  w,  t,  s);
        discover( i+1,  j+1,  h,  w,  t,  s);

        return 2;
    }
    return ss;
}


void print2(int h, int w, char** sss){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++)
        {
            printf("%c ", sss[i][j] );
        }
        printf("\n");
    }

}

typedef struct
{
   char ac,col;
   int rand;
}p;


void mark(int i, int j, int h, int w, char** s)
{
    if(i>=0 && i<h && j>=0 && j<w)
    {
        if(s[i][j]=='?')
            s[i][j]=='!';
        else if(s[i][j]=='!')
            s[i][j]='.';
    }

}

void player_view(int h, int w, char t[h][w], char** s)
{
    printf("  ");
    char c='A';
    for(int i=0; i<w; i++)
    {
        printf("%c",c);
        c+=1;
    }
    printf("  \n");
    int d=1;
    for(int i=0; i<h; i++)
    {
        printf("%d ",d);
        for(int j=0; j<w; j++)
        {
            if(s[i][j]=='.')
                printf("%c",t[i][j]);
            else
                printf("%c",s[i][j]);
        }
        printf(" %d\n",d);
        d++;
    }
    c='A';
    printf("  ");
    for(int i=0; i<w; i++)
    {
        printf("%c",c);
        c+=1;
    }
}
