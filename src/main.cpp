#include "raylib.h"

int main()
{
    constexpr int GAME_WINDOW_WIDTH = 640;
    constexpr int GAME_WINDOW_HEIGHT = 480;
    constexpr int WIN_SCALE = 2;

    constexpr int WIN_WIDTH = GAME_WINDOW_WIDTH * WIN_SCALE;
    constexpr int WIN_HEIGHT = GAME_WINDOW_HEIGHT * WIN_SCALE;

    constexpr int ARCADE_LEFT = 32;
    constexpr int ARCADE_TOP = 16;
    constexpr int ARCADE_WIDTH = 384;
    constexpr int ARCADE_HEIGHT = 448;

    // keeping just in case it's needed later
    constexpr int ARCADE_RIGHT = ARCADE_LEFT + ARCADE_WIDTH;
    constexpr int ARCADE_BOTTOM = ARCADE_TOP + ARCADE_HEIGHT;

    constexpr Rectangle playfield = { ARCADE_LEFT, ARCADE_TOP, ARCADE_WIDTH, ARCADE_HEIGHT };

    InitWindow(WIN_WIDTH, WIN_HEIGHT, "Danmaku Dojo");
    SetTargetFPS(60);

    RenderTexture2D renderTexture = LoadRenderTexture(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
    SetTextureFilter(renderTexture.texture, TEXTURE_FILTER_POINT);

    while (!WindowShouldClose()) {
        BeginTextureMode(renderTexture);
            ClearBackground(DARKGRAY);

            DrawRectangleRec(playfield, GRAY);
            DrawRectangleLinesEx(playfield, 1.0f, WHITE);

            DrawText("DANMAKU DOJO", 450, 45, 20, WHITE);
            DrawFPS(512, 464 - 4); // ZUN draws it at the edge, I think it looks better with a little padding. Subtracted 4 rather than hardcoding just in case idk
        
        EndTextureMode();

        BeginDrawing();
            ClearBackground(BLACK);

            DrawTexturePro(
                renderTexture.texture,
                Rectangle{ 0, 0, GAME_WINDOW_WIDTH, -GAME_WINDOW_HEIGHT },
                Rectangle{ 0, 0, WIN_WIDTH, WIN_HEIGHT },
                Vector2{ 0, 0 },
                0.0f,
                WHITE
            );


        EndDrawing();
    }

    UnloadRenderTexture(renderTexture);
    CloseWindow();
    return 0;
}
