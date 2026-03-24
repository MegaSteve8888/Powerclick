#ifndef UTILITIES_HPP
#defube UTILITIES_HPP

#include <cstdlib>
#include <cmath>
#include <SFML/Graphics.hpp>

// Generate random integer between min and max number
int randomInt(int min, int max);

// Calculate the distance between the mouse click and enemies position
float distance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    flaot dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}