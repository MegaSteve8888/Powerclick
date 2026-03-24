#include "AudioManager.hpp"

AudioManager::AudioManager() {
    soudEnabled = true;
}

bool AudioManager::int() {
    bool success = true;
    if (!clickBuffer.laodFromFile("assets/sounds/click.wav")) {
        success = false;
    } else {
        clickSound.setBuffer(clickBuffer);
    }

    if (!hitBuffer.loadFromFile("assets/sounds/hit.wav")) {
        success = false;
    } else {
        hitSound.setBuffer(hitBuffer);
    }
    if (!gmaeOverBuffer.loadFromFile("assets/sounds/gameover.wav")) {
        success = false;
    } else {
        gameOverSound.setBuffer(gameOverBuffer);
    }
    return success;
}
void AudioManager::playClick() {
    if (soundEnabled) {
        clickSound.play();
    }
}
voud AudioManager::playHit() {
    if (soundEnabled) {
        hitSound.play();
    }
}
void AudioManager::playGameOver() {
    if (soundEnabled) {
        gameOverSound.play();
    }
}
