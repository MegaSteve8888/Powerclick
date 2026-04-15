#include "AudioManager.hpp"
#include "Utilities.hpp"

AudioManager::AudioManager() : clickSound(clickBuffer), hitSound(hitBuffer), gameOverSound(gameOverBuffer) {
    soundEnabled = true;
}

bool AudioManager::init() {
    bool success = true;
    if (!clickBuffer.loadFromFile(getAssetPath("assets/sounds/click.wav"))) {
        success = false;
    } else {
        clickSound.setBuffer(clickBuffer);
    }

    if (!hitBuffer.loadFromFile(getAssetPath("assets/sounds/hit.wav"))) {
        success = false;
    } else {
        hitSound.setBuffer(hitBuffer);
    }
    if (!gameOverBuffer.loadFromFile(getAssetPath("assets/sounds/gameover.wav"))) {
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
void AudioManager::playHit() {
    if (soundEnabled) {
        hitSound.play();
    }
}
void AudioManager::playGameOver() {
    if (soundEnabled) {
        gameOverSound.play();
    }
}

void AudioManager::playBGM() {
    if (soundEnabled) {
        if (bgm.openFromFile(getAssetPath("assets/sounds/bgm.ogg"))) {
            bgm.setLooping(true);
            bgm.setVolume(50);
            bgm.play();
        }
    }
}

void AudioManager::stopBGM() {
    bgm.stop();
}

void AudioManager::toggleSound() {
    soundEnabled = !soundEnabled;
    if (!soundEnabled) {
        stopBGM();
    }
}

bool AudioManager::isSoundEnabled() const {
    return soundEnabled;
}