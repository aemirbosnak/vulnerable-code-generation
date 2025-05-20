//FormAI DATASET v1.0 Category: Data structures visualization ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Define a Circle struct with a center point and radius
typedef struct Circle {
    int x;
    int y;
    int r;
} Circle;

// Create a dynamically allocated array of Circles
void create_circle_array(Circle **circles, int size) {
    *circles = malloc(sizeof(Circle) * size);
    for (int i = 0; i < size; i++) {
        (*circles)[i].x = i * 10;
        (*circles)[i].y = i * 10;
        (*circles)[i].r = i * 5;
    }
}

// Print the Circle array in a visually appealing way
void print_circle_array(Circle *circles, int size) {
    // Define the size of the grid and margin size
    int grid_size = 20;
    int margin_size = 2;

    // Create the grid
    char grid[grid_size][grid_size];
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            grid[i][j] = '-';
        }
    }

    // Add each Circle to the grid
    for (int i = 0; i < size; i++) {
        Circle circle = circles[i];
        int x = circle.x / 10 + margin_size;
        int y = circle.y / 10 + margin_size;
        int r = circle.r / 10;

        for (int j = y - r; j <= y + r; j++) {
            for (int k = x - r; k <= x + r; k++) {
                if (j >= margin_size && j < grid_size - margin_size && k >= margin_size && k < grid_size - margin_size) {
                    if ((k - x) * (k - x) + (j - y) * (j - y) <= r * r) {
                        grid[j][k] = 'o';
                    }
                }
            }
        }
    }

    // Print the grid
    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Circle *circles;
    create_circle_array(&circles, 10);
    print_circle_array(circles, 10);
    free(circles);
    return 0;
}