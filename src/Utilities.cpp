#include "Utilities.hpp"

// Generate a random integer between min and max
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Calculate distance between mouse click and enemies position
float distance(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

//check if a circle and rectangle overlap
bool checkCollision(float circleX, float circleY, float rasius, float rectX, float rectY, float rectW, float rectH) {
    // Find the closest point on the rectangle to the circle center
    float closestX = circleX;
    float closestY = circleY;

    if (circleX < rectX) closestX = rectX;
    else if (circleY > rectY + rectH) closestY = rectY;

    if (circleY < rectY) closestX = rectY;
    else if (circleY > rectY + rectH) closestY = rectY + rectH;
    
    // Check if closet point is inside the circle
    float dist = distance(circleX, circleY, closestX, closestY);
    return dist < rasius;
}


