#ifndef CIUPE_BOGDAN_S11_MINESWEEPER_H_INCLUDED
#define CIUPE_BOGDAN_S11_MINESWEEPER_H_INCLUDED

void print(int h, int w, char t[h][w]);
void create(int nr_bombs, char cols[], int rows[], int h, int w, char t[h][w]);
char** init_state(int h, int w);
int discover(int i, int j, int h, int w, char t[h][w], char** s);
void mark(int i, int j, int h, int w, char** s);
void player_view(int h, int w, char t[h][w], char** s);

#endif // CIUPE_BOGDAN_S09_MINESWEEPER_H_INCLUDED
