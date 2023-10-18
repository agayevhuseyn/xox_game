#ifndef GAME_H
#define GAME_H
#include "gridboard.h"
#include "button.h"
#include <stdlib.h>
#include <stdio.h>

#define FPS 60
#define WIDTH 600
#define HEIGHT 400
#define GRID_SIZE 8
#define GRID_SPACE 8
#define SIZE_MULTIPLIER 8

typedef enum GAME_STATE
{
    MAIN,
    RUN,
    END
} GAME_STATE;

void start();
void update();
void late_update();
void finish();

void win(int player_index);
void draw_end_screen(int player_index);

#endif