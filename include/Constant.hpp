#ifndef CONSTANT_HPP
#define CONSTANTS_HPP

//setting game window
const int SCREEN_WIDRH = 800;
const int SCREEN_HEIGHT = 600;
const char GAME_TITLE[] = "Powerclick";
const int FRAME_RATE = 60;

//setting game player
const int PLAYER_LIVES = 5;
const int STRARTING_SCORE = 0;

//setting house
const float HOUSE_WIDTH = 120.0f;
const float HOUSE_HEIGHT = 100.0f;
const float HOUSE_X = (SCREEN_WIDRH - HOUSE_WIDTH) / 2.0f;
const float HOUSE_Y = (SCREEN_HEIGHT - HOUSE_HEIGHT) / 2.0f;

// setting game enemy
const float ENEMY_SIZE = 30.0f;
const float ENEMY_BASE_SPEED = 1.5f;


#endif