#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        int score;
        int lives;
    public:
        Player();

        // score functions
        void addScore(int points);
        int getScore() const;

        // lives functions
        void loseLife();
        int getLives() const;
        bool isALive() const;

        //Reset for new game
        void reset();
};

#endif