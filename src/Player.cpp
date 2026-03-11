#include "Player.hpp"
#include "Constant.hpp"

//constructors
Player::player() {
    score = STRARTING_SCORE;
    lives = PLAYER_LIVES;
}

//add points when player click the enemy
void Player::addScore(int points) {
    score += points;
}

//get current score
int Player::getScore() const {
    return score;
}

//when enemy reached house lose one life
void Player::loseLife() {
    if (lives > 0) {
        lives--;
    }
}

//get current lives
int Player::getLives() const {
    return lives;
}

