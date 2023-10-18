#include "../include/game.h"

int main()
{
    InitWindow(WIDTH, HEIGHT, "XOX");

    SetTargetFPS(60);

    SetExitKey(KEY_NULL);
    
    start(); // call start void before loop 


    while(!WindowShouldClose())
    {

        update();

        BeginDrawing();
        ClearBackground(DARKGRAY);

        late_update();

        EndDrawing();
    }

    finish();

    CloseWindow();

    return 0;
}