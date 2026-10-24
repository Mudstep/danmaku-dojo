#pragma once

inline constexpr int GAME_WINDOW_WIDTH = 640;
inline constexpr int GAME_WINDOW_HEIGHT = 480;
inline constexpr int WIN_SCALE = 2;

inline constexpr int WIN_WIDTH = GAME_WINDOW_WIDTH * WIN_SCALE;
inline constexpr int WIN_HEIGHT = GAME_WINDOW_HEIGHT * WIN_SCALE;

inline constexpr int ARCADE_LEFT = 32;
inline constexpr int ARCADE_TOP = 16;
inline constexpr int ARCADE_WIDTH = 384;
inline constexpr int ARCADE_HEIGHT = 448;

inline constexpr int ARCADE_RIGHT = ARCADE_LEFT + ARCADE_WIDTH;
inline constexpr int ARCADE_BOTTOM = ARCADE_TOP + ARCADE_HEIGHT;
