#include <stdio.h>
#include <stdlib.h>
#include "Ciupe_Bogdan_s11_minesweeper.c"
#include "Ciupe_Bogdan_s11_minesweeper.h"



int main()
{
    int h = 3,w = 6;
    char t[3][6] = {{'.', '2', 'X'}, {'.', '2', 'X'}, {'.', '1', '1'}};
    char sir1[2] = {'B', 'D'};
    int sir2[2] = {1, 3};

    create(2, sir1, sir2, 3, 6, t);
    char** sss = init_state(3, 6);

    print(h,w,t);

    int ss = discover(1, 5, 3, 6, t, sss);
    printf("\n");


    char str[]="A1  !B2!B2 A1A1 a103";


    print2(3, 6, sss);
    //player_view(3,6,t,sss);

    return 0;
}

