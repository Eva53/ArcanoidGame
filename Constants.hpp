#pragma once
#include "Project.hpp"

static int const XNUMBRICKS = 10;
static int const YNUMBRICKS = 8;

static float const FRAMERATE_LIMIT = 60.0;
static float const BALL_RADIUS = 5.0;
static float const WIDTH = 1.0;
static float const WIDTH_ = 2.0;
static float const WIDTH_BRICK = 80.0;
static float const HEIGHT_BRICK = 30.0;
static float const WIDTH_WINDOW = (WIDTH_BRICK + WIDTH_) * (XNUMBRICKS + 2);
static float const HEIGHT_WINDOW = HEIGHT_BRICK * 10 * 2.5 + 2 * 10 * WIDTH + 120;
static float const SPEED = 2.0;
static float const PADDLE_FRAME = 1.0;
static float const PADDLE_WIDTH = 100.0;
static float const PADDLE_HEIGHT = 10.0;
static float const PADDLE_X = WIDTH_WINDOW / 2.0 - PADDLE_WIDTH / 2.0;
static float const PADDLE_Y = HEIGHT_WINDOW - 100.0;
static float const BALL_X = PADDLE_X + 35.0;
static float const BALL_Y = PADDLE_Y + 2 - 3 * BALL_RADIUS;
static float const SIZE_FONT = 30.0;
static float const TEXT_HEALTH_X = WIDTH_WINDOW - 160.0;
static float const TEXT_X = 10.0;
static float const TEXT_Y = 10.0;
static float const TEXT_GAME_OVER_X = WIDTH_WINDOW / 3.0;
static float const TEXT_GAME_OVER_Y = HEIGHT_WINDOW / 2.0 - 40.0;
static float const SPEED_CHANGE = 0.2;
static float const MAX_SPEED = 2.0;
static float const BONUS_FALL_SPEED = 3.0;
static float const WIDTH_RECT = 2.0 * BALL_RADIUS;
static float const HEIGHT_RECT = 2.0 * BALL_RADIUS;
static float const FRAME = 40.0;
static float const NEW_PADDLE_WIDTH = PADDLE_WIDTH * 1.5;
static float const FLOOR_SIZE_X = WIDTH_WINDOW;
static float const FLOOR_SIZE_Y = 2.f;
static float const FLOOR_POSITION_Y = PADDLE_Y + PADDLE_HEIGHT;
static int const MOVING_CHANCE = 20;
static int const MOVING_PROBABILITY = 18;
static int const BONUS_CHANCE = 20;
static int const BONUS_PROBABILITY = 1000;
static int const BONUSES_PROBABILITY = 6;
static float const START_BONUS_POSX = WIDTH_BRICK / 2.0 - WIDTH_ - WIDTH;
static float const START_BONUS_POSY = HEIGHT_BRICK / 2.0 - WIDTH_ - WIDTH;

typedef struct speed_t {
    float vx;
    float vy;
} speed_t;

enum class STATE_GAME {
    GAME_PLAY,
    GAME_OVER
};

enum class COLLISION_TYPE {
    ANGLES,
    ANGLE,
    SIDE0,
    SIDE1,
    SIDE2,
    SIDE3,
    PADDLE,
    NO_COLLISION
};

enum class TYPE_BRICK {
    SPEED_UP_BALL,
    BONUS
};

enum class TYPE_BONUS {
    CHANGE_SIZE_PADDLE,
    MOVING_BRICK,
    SPEED_UP,
    STICKY_BALL,
    SET_BOTTOM,
    CHANGE_DIRECTION,
    LAST_BONUS
};

enum COLOR_TYPE_BRICK {
    WHITE,
    CYAN,
    RED,
    GREY,
};
