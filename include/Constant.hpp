#ifndef CONSTANT_HPP
#define CONSTANT_HPP

//setting game window
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char GAME_TITLE[] = "Powerclick";
const int FRAME_RATE = 60;

//setting game player
const int PLAYER_LIVES = 5;
const int STRARTING_SCORE = 0;

//setting house
const float HOUSE_WIDTH = 120.0f;
const float HOUSE_HEIGHT = 100.0f;
const float HOUSE_X = (SCREEN_WIDTH - HOUSE_WIDTH) / 2.0f;
const float HOUSE_Y = (SCREEN_HEIGHT - HOUSE_HEIGHT) / 2.0f;

// setting game enemy
const float ENEMY_SIZE = 30.0f;
const float ENEMY_BASE_SPEED = 1.5f;
const float ENEMY_SPEED_INCREMENT = 0.2f;
// Temporary fast enemy tuning values - adjust or remove once fast enemy design is finalized.
const float FAST_ENEMY_SPEED_MULTIPLIER = 1.8f;
const int MAX_ENEMIES = 20;
const int POINTS_PER_KILL = 10;
const int FAST_ENEMY_SPAWN_CHANCE = 5; // one in five enemies is fast

// setting wave
const int ENEMIES_PER_WAVE_BASE = 3;
const int ENEMIES_PER_WAVE_INCREMENT = 2;
const float SPAWN_INTERVAL = 1.5f;

#endif