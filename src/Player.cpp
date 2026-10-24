#include "Player.h"
#include "Global.h"

#include <algorithm>
#include <cmath>

namespace
{
    constexpr int HITBOX_SIZE = 4;

    constexpr float NORMAL_SPEED = 4.0f;
    constexpr float FOCUSED_SPEED = 2.0f;
    constexpr float DIAGONAL_SCALE = 0.70710678118f; // 1/sqrt(2)

    constexpr float PLAYER_BOUNDS_X = 8.0f;
    constexpr float PLAYER_BOUNDS_TOP = 32.0f;
    constexpr float PLAYER_BOUNDS_BOTTOM = 16.0f;
}

Player createPlayer()
{
    Player player;

    player.position = { 
        ARCADE_WIDTH / 2.0f,
        ARCADE_HEIGHT - 48.0f
    };

    return player;
}

void updatePlayer(Player& player)
{
    float move_x = 0.0f;
    float move_y = 0.0f;

    if (IsKeyDown(KEY_LEFT)) {
        move_x -= 1.0f;
    }
    else if (IsKeyDown(KEY_RIGHT)) {
        move_x += 1.0f;
    }
    else if (IsKeyDown(KEY_UP)) {
        move_y -= 1.0f;
    }
    else if (IsKeyDown(KEY_DOWN)) {
        move_y += 1.0f;
    }

    player.focused = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);

    if (move_x != 0.0f && move_y != 0.0f) {
        move_x *= DIAGONAL_SCALE;
        move_y *= DIAGONAL_SCALE;
    }

    const float speed = player.focused ? FOCUSED_SPEED : NORMAL_SPEED;

    player.position.x += move_x * speed;
    player.position.y += move_y * speed;

    player.position.x = std::clamp(player.position.x, PLAYER_BOUNDS_X, ARCADE_WIDTH - PLAYER_BOUNDS_X);
    player.position.y = std::clamp(player.position.y, PLAYER_BOUNDS_TOP, ARCADE_HEIGHT - PLAYER_BOUNDS_BOTTOM);
}

void drawPlayer(const Player& player, const Texture2D& texture) {
    const int x = ARCADE_LEFT + (int)std::round(player.position.x);
    const int y = ARCADE_TOP + (int)std::round(player.position.y);

    const Rectangle source = { 1.0f, 1.0f, 30.0f, 46.0f };

    const Rectangle dest = {
        (float)x,
        (float)y,
        source.width,
        source.height
    };

    const Vector2 origin = { source.width / 2.0f, source.height / 2.0f };

    DrawTexturePro(texture, source, dest, origin, 0.0f, WHITE);

    if (player.focused) {
        DrawRectangle(x - HITBOX_SIZE / 2, y - HITBOX_SIZE / 2, HITBOX_SIZE, HITBOX_SIZE, RED);
    }
}