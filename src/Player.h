#pragma once

#include "raylib.h"

struct Player {
    Vector2 position;
    bool focused = false;
};

Player createPlayer();
void updatePlayer(Player& player);
void drawPlayer(const Player& player, const Texture2D& texture);
