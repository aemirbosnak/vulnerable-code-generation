//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KINGDOM_SIZE 100
#define KINGDOM_WIDTH 10
#define KINGDOM_HEIGHT 10

// Structure to represent a cell in the kingdom
typedef struct cell {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the kingdom
void init_kingdom(cell_t **kingdom) {
    int i, j;
    for (i = 0; i < KINGDOM_HEIGHT; i++) {
        for (j = 0; j < KINGDOM_WIDTH; j++) {
            kingdom[i][j].alive = (i % 2 == 0) && (j % 2 == 0);  // Initialize cells with a 50% chance of being alive
            kingdom[i][j].neighbors_alive = 0;
        }
    }
}

// Function to iterate over the kingdom and apply the Game of Life rules
void update_kingdom(cell_t **kingdom) {
    int i, j;
    for (i = 0; i < KINGDOM_HEIGHT; i++) {
        for (j = 0; j < KINGDOM_WIDTH; j++) {
            // Calculate the number of alive neighbors
            kingdom[i][j].neighbors_alive = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) continue;  // Skip diagonals
                    if (kingdom[i + k][j + l].alive) {
                        kingdom[i][j].neighbors_alive++;
                    }
                }
            }
            // Apply the Game of Life rules
            if (kingdom[i][j].alive && kingdom[i][j].neighbors_alive < 2) {
                kingdom[i][j].alive = 0;  // If a cell is alive and has fewer than 2 alive neighbors, it dies
            } else if (!kingdom[i][j].alive && kingdom[i][j].neighbors_alive >= 3) {
                kingdom[i][j].alive = 1;  // If a cell is dead and has exactly 3 alive neighbors, it becomes alive
            }
        }
    }
}

// Function to display the kingdom
void display_kingdom(cell_t **kingdom) {
    int i, j;
    for (i = 0; i < KINGDOM_HEIGHT; i++) {
        for (j = 0; j < KINGDOM_WIDTH; j++) {
            if (kingdom[i][j].alive) {
                printf("O");  // Living cell
            } else {
                printf("_");  // Dead cell
            }
        }
        printf("\n");
    }
}

int main() {
    cell_t **kingdom;  // Kingdom of cells
    srand(time(NULL));  // Seed the random number generator
    init_kingdom(&kingdom);

    for (int i = 0; i < 100; i++) {
        update_kingdom(kingdom);
        display_kingdom(kingdom);
        printf("Generation %d\n", i);
    }

    return 0;
}