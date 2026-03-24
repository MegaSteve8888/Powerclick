#include "Utilities.hpp"

// Generate a random integer between min and max
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Calculate distance between mouse click and enemies position
foat distance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}
