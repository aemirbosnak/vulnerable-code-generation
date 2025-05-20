//LLAMA2-13B DATASET v1.0 Category: Geometric algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the size of the grid
#define GRID_SIZE 10

// Define the range of x and y coordinates
#define X_RANGE 0, GRID_SIZE - 1
#define Y_RANGE 0, GRID_SIZE - 1

// Define the range of angles in degrees
#define ANGLE_RANGE 0, 360

// Define the step size for the algorithm
#define STEP_SIZE 1

// Define a struct to represent a point on the grid
typedef struct {
    int x;
    int y;
} point_t;

// Define a function to generate a random point on the grid
point_t* random_point(void) {
    int x = rand() % GRID_SIZE;
    int y = rand() % GRID_SIZE;
    point_t* p = malloc(sizeof(point_t));
    p->x = x;
    p->y = y;
    return p;
}

// Define a function to calculate the distance between two points
int distance(point_t* p1, point_t* p2) {
    int dx = p1->x - p2->x;
    int dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}

// Define a function to find the closest point on a line segment
point_t* closest_point(point_t* p1, point_t* p2, point_t* p3) {
    int dx = p2->x - p1->x;
    int dy = p2->y - p1->y;
    int d = distance(p1, p3);
    if (d < 0) {
        // Point 1 is closer to point 3 than point 2
        return p1;
    } else if (d > distance(p2, p3)) {
        // Point 2 is closer to point 3 than point 1
        return p2;
    } else {
        // Point 1 and point 2 are equally close to point 3
        return p1;
    }
}

// Define the main function
int main(void) {
    // Create a grid of size GRID_SIZE x GRID_SIZE
    point_t** grid = calloc(GRID_SIZE, sizeof(point_t*));
    for (int i = 0; i < GRID_SIZE; i++) {
        grid[i] = calloc(GRID_SIZE, sizeof(point_t));
    }

    // Generate a random point on the grid
    point_t* start = random_point();

    // Find the closest point on the line segment formed by start and the
    //  bottom-right corner of the grid
    point_t* closest = closest_point(start, grid[GRID_SIZE - 1], start);

    // Print the coordinates of the closest point
    printf("Closest point: (%d, %d)\n", closest->x, closest->y);

    // Free the memory allocated for the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}