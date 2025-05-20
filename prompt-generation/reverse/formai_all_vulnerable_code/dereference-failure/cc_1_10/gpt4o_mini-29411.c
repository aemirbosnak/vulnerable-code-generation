//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a Point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Structure to represent a mathematical operation on Points
typedef struct {
    Point *points;
    size_t size;
} PointSet;

// Function to create a new Point
Point createPoint(double x, double y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

// Function to create a new PointSet
PointSet *createPointSet(size_t size) {
    PointSet *set = (PointSet *)malloc(sizeof(PointSet));
    set->points = (Point *)malloc(size * sizeof(Point));
    set->size = size;
    return set;
}

// Function to free the allocated memory for PointSet
void freePointSet(PointSet *set) {
    free(set->points);
    free(set);
}

// Function to display the Points in a PointSet
void displayPointSet(PointSet *set) {
    printf("Displaying Points:\n");
    for (size_t i = 0; i < set->size; i++) {
        printf("Point %zu: (%.2f, %.2f)\n", i + 1, set->points[i].x, set->points[i].y);
    }
}

// Function to calculate the distance between two Points
double calculateDistance(Point a, Point b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

// Function to find the centroid of Points in a PointSet
Point calculateCentroid(PointSet *set) {
    double sumX = 0.0;
    double sumY = 0.0;

    for (size_t i = 0; i < set->size; i++) {
        sumX += set->points[i].x;
        sumY += set->points[i].y;
    }

    Point centroid;
    centroid.x = sumX / set->size;
    centroid.y = sumY / set->size;
    
    return centroid;
}

// Function to find the nearest Point to a given Point
Point findNearestPoint(PointSet *set, Point target) {
    double minDistance = -1.0;
    Point nearestPoint;

    for (size_t i = 0; i < set->size; i++) {
        double distance = calculateDistance(set->points[i], target);
        if (minDistance < 0 || distance < minDistance) {
            minDistance = distance;
            nearestPoint = set->points[i];
        }
    }

    return nearestPoint;
}

// Main function demonstrating the use of data structures
int main() {
    size_t numberOfPoints = 5;
    PointSet *pointSet = createPointSet(numberOfPoints);
    
    // Initialize Points
    pointSet->points[0] = createPoint(1.0, 2.0);
    pointSet->points[1] = createPoint(3.0, 4.0);
    pointSet->points[2] = createPoint(5.0, 6.0);
    pointSet->points[3] = createPoint(7.0, 8.0);
    pointSet->points[4] = createPoint(2.0, 1.0);
    
    // Display the PointSet
    displayPointSet(pointSet);

    // Calculate centroid
    Point centroid = calculateCentroid(pointSet);
    printf("Centroid of the points: (%.2f, %.2f)\n", centroid.x, centroid.y);

    // Find nearest point to a given Point
    Point target = createPoint(3.5, 4.5);
    Point nearest = findNearestPoint(pointSet, target);
    printf("Nearest point to (%.2f, %.2f): (%.2f, %.2f)\n", target.x, target.y, nearest.x, nearest.y);

    // Free allocated memory
    freePointSet(pointSet);
    
    return 0;
}