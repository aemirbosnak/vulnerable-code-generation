//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_WIDTH 10
#define CELL_HEIGHT 10

// Define the game of life rules
#define ALIVE 1
#define DEAD 0

// Structure to represent the grid
typedef struct {
    int cells[CELL_WIDTH][CELL_HEIGHT];
} grid_t;

// Function to create a new grid
grid_t* new_grid(void) {
    grid_t* g = malloc(sizeof(grid_t));
    for (int i = 0; i < CELL_WIDTH; i++) {
        for (int j = 0; j < CELL_HEIGHT; j++) {
            g->cells[i][j] = DEAD;
        }
    }
    return g;
}

// Function to draw the grid
void draw_grid(grid_t* g) {
    for (int i = 0; i < CELL_WIDTH; i++) {
        for (int j = 0; j < CELL_HEIGHT; j++) {
            if (g->cells[i][j] == ALIVE) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

// Function to update the grid based on the game of life rules
void update_grid(grid_t* g) {
    for (int i = 0; i < CELL_WIDTH; i++) {
        for (int j = 0; j < CELL_HEIGHT; j++) {
            // Check the neighbors of the current cell
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    if (g->cells[i + k][j + l] == ALIVE) {
                        alive_neighbors++;
                    }
                }
            }
            
            // Update the cell based on the game of life rules
            if (g->cells[i][j] == DEAD && alive_neighbors == 3) {
                g->cells[i][j] = ALIVE;
            } else if (g->cells[i][j] == ALIVE && alive_neighbors < 2) {
                g->cells[i][j] = DEAD;
            } else {
                g->cells[i][j] = DEAD;
            }
        }
    }
}

int main(void) {
    srand(time(NULL));
    
    // Create a new grid
    grid_t* g = new_grid();
    
    // Draw the grid
    draw_grid(g);
    
    // Update the grid multiple times
    for (int i = 0; i < 100; i++) {
        update_grid(g);
    }
    
    // Draw the final grid
    draw_grid(g);
    
    // Free the grid memory
    free(g);
    
    return 0;
}