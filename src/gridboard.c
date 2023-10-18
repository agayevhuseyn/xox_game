#include "../include/gridboard.h"
#include "../include/game.h"
#include <stdio.h>

void init_gridboard(Gridboard *gridboard, int grid_size, int grid_space)
{
    Vector2 grid_pos = { WIDTH/2 - (grid_size * SIZE_MULTIPLIER * 3/2) - grid_space, HEIGHT/2 - (grid_size * SIZE_MULTIPLIER * 3/2) - grid_space };
    for(int i = 0; i < 9; i++)
    {
        gridboard->grids[i].size = (Vector2){ grid_size * SIZE_MULTIPLIER, grid_size * SIZE_MULTIPLIER };
        gridboard->grids[i].state = EMPTY;
        gridboard->grids[i].pos = grid_pos;

        grid_pos.x += grid_size * SIZE_MULTIPLIER + grid_space;
        if((i + 1) % 3 == 0)
        {
            grid_pos.x = WIDTH/2 - (grid_size * SIZE_MULTIPLIER * 3/2) - grid_space;
            grid_pos.y += grid_size * SIZE_MULTIPLIER + grid_space;
        }
    }
}

void draw_gridboard(Gridboard *gridboard, Texture2D *textures)
{
    for(int i = 0; i < 9; i++)
    {
        draw_grid(&(gridboard->grids[i]), &(textures[gridboard->grids[i].state]));
    }
}

bool check_win(Gridboard *gridboard)
{
    for(int i = 0; i < 9; i++)
    {
        if(gridboard->grids[i].state == EMPTY || gridboard->grids[i].state == OVER) continue;

        switch (i + 1)
        {
        case 5:
            continue;
        case 6:
            continue;
        case 8:
            continue;
        case 9:
            continue;
        case 1:
        {
            if((gridboard->grids[i].state == gridboard->grids[i + 1].state) && (gridboard->grids[i + 1].state == gridboard->grids[i + 2].state))
            {
                return true;
            }
            else if((gridboard->grids[i].state == gridboard->grids[i + 3].state) && (gridboard->grids[i + 3].state == gridboard->grids[i + 6].state))
            {
                return true;
            }
            else if((gridboard->grids[i].state == gridboard->grids[i + 4].state) && (gridboard->grids[i + 4].state == gridboard->grids[i + 8].state))
            {
                return true;
            }
            break;
        }
        case 2:
        {
            if((gridboard->grids[i].state == gridboard->grids[i + 3].state) && (gridboard->grids[i + 3].state == gridboard->grids[i + 6].state))
            {
                return true;
            }
            break;
        }
        case 3:
        {
            if((gridboard->grids[i].state == gridboard->grids[i + 3].state) && (gridboard->grids[i + 3].state == gridboard->grids[i + 6].state))
            {
                return true;
            }
            else if((gridboard->grids[i].state == gridboard->grids[i + 2].state) && (gridboard->grids[i + 2].state == gridboard->grids[i + 4].state))
            {
                return true;
            }
            break;
        }
        case 4:
        {
            if((gridboard->grids[i].state == gridboard->grids[i + 1].state) && (gridboard->grids[i + 1].state == gridboard->grids[i + 2].state))
            {
                return true;
            }
            break;
        }
        case 7:
        {
            if((gridboard->grids[i].state == gridboard->grids[i + 1].state) && (gridboard->grids[i + 1].state == gridboard->grids[i + 2].state))
            {
                return true;
            }
            break;
        }
        }
    }
    printf("No win!(yet)\n");
    return false;
}