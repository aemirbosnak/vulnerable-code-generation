//GEMINI-pro DATASET v1.0 Category: Educational ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A simple struct to represent a point in 2D space
typedef struct {
    int x;
    int y;
} Point;

// Initialize a point to a given coordinate
Point newPoint(int x, int y) {
    Point point;
    point.x = x;
    point.y = y;
    return point;
}

// Generate a random point within a given range
Point randomPoint(int minX, int minY, int maxX, int maxY) {
    int rangeX = maxX - minX;
    int rangeY = maxY - minY;
    int randX = rand() % rangeX + minX;
    int randY = rand() % rangeY + minY;
    return newPoint(randX, randY);
}

// Calculate the distance between two points
double distance(Point p1, Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

// Find the closest point to a given point from a list of points
Point closestPoint(Point target, Point* points, int numPoints) {
    Point closest;
    double minDistance = -1;
    for (int i = 0; i < numPoints; i++) {
        double curDistance = distance(target, points[i]);
        if (minDistance < 0 || curDistance < minDistance) {
            minDistance = curDistance;
            closest = points[i];
        }
    }
    return closest;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a list of random points
    int numPoints = 1000;
    Point* points = malloc(sizeof(Point) * numPoints);
    for (int i = 0; i < numPoints; i++) {
        points[i] = randomPoint(-1000, -1000, 1000, 1000);
    }

    // Find the closest point to the origin
    Point target = newPoint(0, 0);
    Point closest = closestPoint(target, points, numPoints);

    // Print the closest point
    printf("Closest point to the origin: (%d, %d)\n", closest.x, closest.y);

    // Free the allocated memory
    free(points);

    return 0;
}