#include "Game.h"
#include "Global.h"
#include "Player.h"

#include "raylib.h"

void runGame()
{
    constexpr Rectangle playfield = { ARCADE_LEFT, ARCADE_TOP, ARCADE_WIDTH, ARCADE_HEIGHT };

    Texture2D playerTexture = LoadTexture("assets/placeholder/reimu/pl00.anm.texture-0.png");
    SetTextureFilter(playerTexture, TEXTURE_FILTER_POINT);

    RenderTexture2D renderTexture = LoadRenderTexture(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
    SetTextureFilter(renderTexture.texture, TEXTURE_FILTER_POINT);

    Player player = createPlayer();

    while (!WindowShouldClose()) {
        updatePlayer(player);

        BeginTextureMode(renderTexture);
            ClearBackground(DARKGRAY);

            DrawRectangleRec(playfield, GRAY);

            BeginScissorMode(ARCADE_LEFT, ARCADE_TOP, ARCADE_WIDTH, ARCADE_HEIGHT);
                drawPlayer(player, playerTexture);
            EndScissorMode();

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

    UnloadTexture(playerTexture);
    UnloadRenderTexture(renderTexture);
}
