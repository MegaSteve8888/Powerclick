#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP
#include <SFML/Audio.hpp>
#include <string>

class AudioManager {
    private:
        sf::SoundBuffer clickBuffer;
        sf::SoundBuffer hitBuffer;
        sf::SoundBuffer gameOverBuffer;
        sf::Sound clickSound;
        sf::Sound hitSound;
        sf::Music bgm;
        bool soundEnabled;
    public:
        AudioManager();
        bool int();
        void playClick();
        void playHit();
        void playGameOver();
        void playBGM();
        void stopBGM();
        void toggleSound();
        bool isSoundEnabled() const;
};

#endif