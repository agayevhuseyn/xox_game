#ifndef GRID_H
#define GRID_H
#include "raylib.h"

typedef enum GRID_STATE
{
    EMPTY,
    X,
    O,
    OVER
} GRID_STATE;

typedef struct Grid
{
    Vector2 pos;
    Vector2 size;
    GRID_STATE state;
} Grid;

bool is_mouse_over_grid(Grid *grid);
void draw_grid(Grid *grid, Texture2D *tex);
void change_grid(Grid *grid, int index);
bool is_grid_pressed(Grid *grid);


#endif