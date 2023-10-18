#include "../include/game.h"
#include "raylib.h"

Texture2D textures[4];

Gridboard *gridboard = NULL;

int player_turn = 1;

GAME_STATE game_state = MAIN;

Button *start_button = NULL;
Button *replay_button = NULL;

Font font;

void start()
{
    textures[0] = LoadTexture("assets/grid_0.png");
    textures[1] = LoadTexture("assets/grid_1.png");
    textures[2] = LoadTexture("assets/grid_2.png");
    textures[3] = LoadTexture("assets/grid_3.png");

    gridboard = (Gridboard*)malloc(sizeof(Gridboard));    //malloc gridboard
    start_button = init_button((Vector2){ 8, 8 }, (Vector2){ WIDTH/2 - 32, HEIGHT/2 - 32 }, LoadTexture("assets/play_0.png"), LoadTexture("assets/play_1.png"));
    replay_button = init_button((Vector2){ 8, 8 }, (Vector2){ WIDTH/2 - 32, HEIGHT/2 - 32 + 96}, LoadTexture("assets/replay_0.png"), LoadTexture("assets/replay_1.png"));

    font = LoadFontEx("assets/PixelFont.ttf", 64, NULL, 95);

    init_gridboard(gridboard, GRID_SIZE, GRID_SPACE);
}

void update()
{
    if(game_state == MAIN)
    {
        if(is_button_pressed(start_button))
        {
            game_state = RUN;
        }
    }
    else if(game_state == RUN)
    {
        for(int i = 0; i < 9; i++)
        {
            if(gridboard->grids[i].state == X || gridboard->grids[i].state == O) continue;
            else if(is_grid_pressed(&(gridboard->grids[i])))
            {
                change_grid(&(gridboard->grids[i]), player_turn);
                if(check_win(gridboard))
                {
                    win(player_turn);
                }
                else
                    player_turn = (player_turn % 2) + 1;
            }
        }
    }
    else if(game_state == END)
    {
        if(is_button_pressed(replay_button))
        {
            for(int i = 0; i < 9; i++)
            {
                gridboard->grids[i].state = EMPTY;
            }
            game_state = RUN;
            player_turn = 1;
        }
    }
}

void late_update()
{
    if(game_state == MAIN)
    {
        draw_button(start_button);
    }
    else if(game_state == RUN)
    {
        draw_gridboard(gridboard, textures);
    }
    else if(game_state == END)
    {
        draw_end_screen(player_turn);
    }
}

void finish()
{
    free(gridboard);
    UnloadTexture(textures[0]);
    UnloadTexture(textures[1]);
    UnloadTexture(textures[2]);
    UnloadTexture(textures[3]);
}

void win(int player_index)
{
    printf("Player %d wins!\n", player_index);
    game_state = END;
}

void draw_end_screen(int player_index)
{
    char text[64];

    sprintf(text, "Player %d wins!", player_index);

    DrawTextEx(font ,text, (Vector2){128, 40}, 64, 0, RAYWHITE);
    // DrawText(text, 90, 40, 64, RAYWHITE);

    draw_button(replay_button);
}