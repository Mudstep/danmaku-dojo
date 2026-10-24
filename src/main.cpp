#include "Game.h"
#include "Global.h"

#include "raylib.h"

int main()
{
    InitWindow(WIN_WIDTH, WIN_HEIGHT, "Danmaku Dojo");
    SetTargetFPS(60);

    runGame();

    CloseWindow();
    return 0;
}
