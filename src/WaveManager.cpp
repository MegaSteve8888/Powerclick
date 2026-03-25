#include "WaveManager.hpp"

WaveManager::WaveManager()
    : currentWave(1), currentDifficulty(1)
{
}

void WaveManager::startWave(int waveNumber, int difficulty)
{
    currentWave = waveNumber;
    currentDifficulty = difficulty;
    enemies.clear();
}

void WaveManager::nextWave()
{
    ++currentWave;
    enemies.clear();
}

int WaveManager::getCurrentWave() const
{
    return currentWave;
}

int WaveManager::getCurrentDifficulty() const
{
    return currentDifficulty;
}

std::vector<Enemy>& WaveManager::getEnemyList()
{
    return enemies;
}

const std::vector<Enemy>& WaveManager::getEnemyList() const
{
    return enemies;
}

void WaveManager::addEnemy(const Enemy& enemy)
{
    enemies.push_back(enemy);
}

void WaveManager::removeEnemy(int index)
{
    if (index >= 0 && index < static_cast<int>(enemies.size()))
    {
        enemies.erase(enemies.begin() + index);
    }
}

int WaveManager::getEnemyCount() const
{
    return static_cast<int>(enemies.size());
}

bool WaveManager::isWaveComplete() const
{
    return enemies.empty();
}

void WaveManager::reset()
{
    currentWave = 1;
    currentDifficulty = 1;
    enemies.clear();
}
