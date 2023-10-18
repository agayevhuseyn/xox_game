#ifndef GRIDBOARD_H
#define GRIDBOARD_H
#include "grid.h"

typedef struct Gridboard
{
    Grid grids[9];   
} Gridboard;

void init_gridboard(Gridboard *gridboard, int grid_size, int grid_space);
void draw_gridboard(Gridboard *gridboard, Texture2D *textures);

bool check_win(Gridboard *gridboard);

#endif