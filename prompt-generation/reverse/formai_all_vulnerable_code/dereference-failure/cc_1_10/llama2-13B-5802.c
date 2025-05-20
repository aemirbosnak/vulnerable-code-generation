//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORLD_WIDTH 20
#define WORLD_HEIGHT 20
#define CELL_SIZE 5
#define GENERATIONS 50

// Structure to represent a world
typedef struct world {
    int width;
    int height;
    int cells[WORLD_HEIGHT][WORLD_WIDTH];
} world;

// Function to create a new world
world *new_world(void) {
    world *w = malloc(sizeof(world));
    w->width = WORLD_WIDTH;
    w->height = WORLD_HEIGHT;
    for (int i = 0; i < WORLD_HEIGHT; i++) {
        for (int j = 0; j < WORLD_WIDTH; j++) {
            w->cells[i][j] = 0;
        }
    }
    return w;
}

// Function to iterate over a world and apply the game of life rules
void apply_rules(world *w) {
    for (int i = 0; i < WORLD_HEIGHT; i++) {
        for (int j = 0; j < WORLD_WIDTH; j++) {
            // Count the number of alive neighbors
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;
                    if (w->cells[i + k][j + l] == 1) alive_neighbors++;
                }
            }
            
            // Apply the game of life rules
            if (w->cells[i][j] == 1 && alive_neighbors < 2 && alive_neighbors > 0) {
                w->cells[i][j] = 0; // die of loneliness
            } else if (w->cells[i][j] == 0 && alive_neighbors >= 2) {
                w->cells[i][j] = 1; // reproduction
            }
        }
    }
}

// Function to draw a world
void draw_world(world *w) {
    for (int i = 0; i < WORLD_HEIGHT; i++) {
        for (int j = 0; j < WORLD_WIDTH; j++) {
            if (w->cells[i][j] == 1) {
                printf("O ");
            } else {
                printf(" .");
            }
        }
        printf("\n");
    }
}

int main(void) {
    srand(time(NULL)); // seed the random number generator
    
    // Create a new world
    world *w = new_world();
    
    // Initialize the world with random values
    for (int i = 0; i < WORLD_HEIGHT; i++) {
        for (int j = 0; j < WORLD_WIDTH; j++) {
            w->cells[i][j] = rand() % 2;
        }
    }
    
    // Run the game of life for GENERATIONS generations
    for (int g = 0; g < GENERATIONS; g++) {
        apply_rules(w);
    }
    
    // Draw the final world
    draw_world(w);
    
    // Free the world
    free(w);
    
    return 0;
}