#ifndef BUTTON_H
#define BUTTON_H
#include "raylib.h"
#include "game.h"

typedef enum BUTTON_STATE
{
    STILL,
    HOLD
} BUTTON_STATE;

typedef struct Button
{
    Vector2 size;
    Vector2 pos;
    Texture2D textures[2];
    BUTTON_STATE state;
} Button;

Button *init_button(Vector2 size, Vector2 pos, Texture tex_0, Texture tex_1);
bool is_button_pressed(Button *button);
void draw_button(Button *button);

#endif