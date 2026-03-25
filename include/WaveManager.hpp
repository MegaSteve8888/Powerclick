#pragma once

#include <vector>

#include "Enemy.h"

class WaveManager
{
public:
    WaveManager();

    void startWave(int waveNumber, int difficulty);
    void nextWave();

    int getCurrentWave() const;
    int getCurrentDifficulty() const;

    std::vector<Enemy>& getEnemyList();
    const std::vector<Enemy>& getEnemyList() const;

    void addEnemy(const Enemy& enemy);
    void removeEnemy(int index);
    int getEnemyCount() const;

    bool isWaveComplete() const;
    void reset();

private:
    int currentWave;
    int currentDifficulty;
    std::vector<Enemy> enemies;
};
