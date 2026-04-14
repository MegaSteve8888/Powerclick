#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <cstdlib>
#include <cmath>
#include <string>
#include <SFML/Graphics.hpp>

// Resolve asset path from either repo root or build directory
std::string getAssetPath(const std::string& relativePath);

// Generate random integer between min and max number
int randomInt(int min, int max);

// Calculate the distance between the mouse click and enemies position
float distance(float x1, float y1, float x2, float y2);

// Check if a circle and rectangle overlap
bool checkCollision(float circleX, float circleY, float radius, float rectX, float rectY, float rectW, float rectH);

#endif