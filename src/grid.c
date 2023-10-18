#include "../include/grid.h"
#include "../include/game.h"

bool is_mouse_over_grid(Grid *grid)
{
    if(GetMousePosition().x > grid->size.x + grid->pos.x ||
    GetMousePosition().x < grid->pos.x ||
    GetMousePosition().y < grid->pos.y ||
    GetMousePosition().y > grid->size.y + grid->pos.y)
        return false;
    return true;
}

void draw_grid(Grid *grid, Texture2D *tex)
{
    DrawTextureEx(*tex, grid->pos, 0, SIZE_MULTIPLIER, RAYWHITE);
}

void change_grid(Grid *grid, int index)
{
    grid->state = index;
}

bool is_grid_pressed(Grid *grid)
{
    if(!is_mouse_over_grid(grid))
    {
        if(grid->state == OVER) grid->state = EMPTY;
        return false;
    }
    if(IsMouseButtonPressed(0) && grid->state == EMPTY)
    {
        grid->state = OVER;
    }
    else if(IsMouseButtonReleased(0) && grid->state == OVER)
    {
        return true;
    }
    return false;
}