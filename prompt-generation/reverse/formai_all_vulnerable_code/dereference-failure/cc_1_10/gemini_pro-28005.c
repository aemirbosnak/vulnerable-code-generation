//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_POINTS 10000

// Define the point structure
typedef struct {
    float x;
    float y;
    float z;
} Point;

// Create a new point
Point *new_point(float x, float y, float z) {
    Point *point = malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    point->z = z;
    return point;
}

// Free a point
void free_point(Point *point) {
    free(point);
}

// Print a point
void print_point(Point *point) {
    printf("(%f, %f, %f)\n", point->x, point->y, point->z);
}

// Main function
int main() {
    // Create an array of points
    Point *points[NUM_POINTS];

    // Initialize the points
    for (int i = 0; i < NUM_POINTS; i++) {
        points[i] = new_point(i, i, i);
    }

    // Print the points
    for (int i = 0; i < NUM_POINTS; i++) {
        print_point(points[i]);
    }

    // Free the points
    for (int i = 0; i < NUM_POINTS; i++) {
        free_point(points[i]);
    }

    return 0;
}