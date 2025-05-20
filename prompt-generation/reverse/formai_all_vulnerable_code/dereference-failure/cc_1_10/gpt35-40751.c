//FormAI DATASET v1.0 Category: Fractal Generation ; Style: detailed
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#define WIDTH 1000
#define HEIGHT 1000

typedef struct point_t {
    double x;
    double y;
} point;

// Function to calculate distance between two points
double distance(point a, point b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

// Function to get a random point within the boundary
point get_random_point() {
    point p;
    p.x = (double)(rand() % WIDTH);
    p.y = (double)(rand() % HEIGHT);
    return p;
}

// Function to get the mid-point between two points
point get_midpoint(point a, point b) {
    point mid;
    mid.x = (a.x + b.x) / 2.0;
    mid.y = (a.y + b.y) / 2.0;
    return mid;
}

// Function to check if a point lies within a circle
bool is_within_circle(point center, double radius, point p) {
    return distance(center, p) < radius;
}

// Function to generate the fractal
void fractal_generation(int iterations) {
    int i, j, k;
    bool is_within;
    point a, b, c, p;
    point vertices[] = {{0,0}, {WIDTH-1, 0}, {WIDTH/2, HEIGHT-1}};
    point center = {WIDTH/2, HEIGHT/2};
    double radius = (double)WIDTH / 2.0;
    
    // Allocate memory for the image buffer
    char *buffer = (char*)calloc(WIDTH * HEIGHT, sizeof(char));
    
    // Choose a random point within the triangle boundary
    p = get_random_point();

    // Perform iterations to generate the fractal
    for (i = 0; i < iterations; i++) {
        // Choose a random triangle vertex
        k = rand() % 3;
        if (k == 0) {
            a = vertices[0];
        } else if (k == 1) {
            a = vertices[1];
        } else {
            a = vertices[2];
        }
        // Choose the midpoint between the chosen vertex and the current point
        b = get_midpoint(a, p);
        // Check if the midpoint lies within the circle
        is_within = is_within_circle(center, radius, b);
        // If it is within the circle, choose it as the new point. 
        // If not, choose another vertex and repeat
        if (is_within) {
            p = b;
            // Mark the point in the buffer
            buffer[((int)p.y * WIDTH) + (int)p.x] = 1;
        }
    }
    
    // Print the image buffer (1 is represented by an asterisk, 0 by a space)
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (buffer[(i * WIDTH) + j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    // Free the buffer memory
    free(buffer);
}

int main() {
    // Set a random seed
    srand(time(NULL));
    
    // Call the fractal generation function
    fractal_generation(1000000);
    
    return 0;
}