//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the grid
#define GRID_SIZE 10

// Define the number of cars
#define NUM_CARS 10

// Define the maximum speed of a car
#define MAX_SPEED 5

// Define the probability of a car turning left or right
#define TURN_PROBABILITY 0.1

// Define the structure of a car
typedef struct car {
    int x;
    int y;
    int speed;
    int direction; // 0 = up, 1 = right, 2 = down, 3 = left
} car;

// Define the structure of the grid
typedef struct grid {
    car **cells;
} grid;

// Create a new grid
grid *create_grid() {
    grid *g = malloc(sizeof(grid));
    g->cells = malloc(sizeof(car *) * GRID_SIZE);
    for (int i = 0; i < GRID_SIZE; i++) {
        g->cells[i] = malloc(sizeof(car) * GRID_SIZE);
    }
    return g;
}

// Free the grid
void free_grid(grid *g) {
    for (int i = 0; i < GRID_SIZE; i++) {
        free(g->cells[i]);
    }
    free(g->cells);
    free(g);
}

// Initialize the grid
void init_grid(grid *g) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            g->cells[i][j].x = i;
            g->cells[i][j].y = j;
            g->cells[i][j].speed = 0;
            g->cells[i][j].direction = 0;
        }
    }
}

// Print the grid
void print_grid(grid *g) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (g->cells[i][j].speed > 0) {
                printf("%d", g->cells[i][j].speed);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Update the grid
void update_grid(grid *g) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            car *c = &g->cells[i][j];

            // Update the car's speed
            c->speed += 1;
            if (c->speed > MAX_SPEED) {
                c->speed = MAX_SPEED;
            }

            // Update the car's direction
            if (rand() % 100 < TURN_PROBABILITY) {
                c->direction = rand() % 4;
            }

            // Move the car
            switch (c->direction) {
                case 0: // Up
                    c->y -= c->speed;
                    break;
                case 1: // Right
                    c->x += c->speed;
                    break;
                case 2: // Down
                    c->y += c->speed;
                    break;
                case 3: // Left
                    c->x -= c->speed;
                    break;
            }

            // Wrap the car around the grid
            if (c->x < 0) {
                c->x = GRID_SIZE - 1;
            } else if (c->x >= GRID_SIZE) {
                c->x = 0;
            }
            if (c->y < 0) {
                c->y = GRID_SIZE - 1;
            } else if (c->y >= GRID_SIZE) {
                c->y = 0;
            }
        }
    }
}

// Main function
int main() {
    // Create a new grid
    grid *g = create_grid();

    // Initialize the grid
    init_grid(g);

    // Print the grid
    print_grid(g);

    // Update the grid
    update_grid(g);

    // Print the grid
    print_grid(g);

    // Free the grid
    free_grid(g);

    return 0;
}