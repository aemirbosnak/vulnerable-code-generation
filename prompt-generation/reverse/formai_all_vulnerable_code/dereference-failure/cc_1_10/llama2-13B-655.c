//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: satisfied
#include <stdio.h>

// Structure to represent a cell in the game board
typedef struct cell {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the game board with random values
void init_board(cell_t *board, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            board[i * size + j].alive = rand() % 2;
            board[i * size + j].neighbors_alive = 0;
        }
    }
}

// Function to apply the game of life rules to the game board
void apply_rules(cell_t *board, int size) {
    int i, j, alive_neighbors;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            alive_neighbors = 0;

            // Count the number of alive neighbors
            for (int k = -1; k <= 1; k++) {
                if (k == 0) {
                    continue;
                }
                alive_neighbors += board[(i + k) * size + j].alive;
            }

            // Apply the game of life rules
            if (board[i * size + j].alive && alive_neighbors < 2) {
                board[i * size + j].alive = 0; // If alive and has fewer than 2 alive neighbors, die
            } else if (!board[i * size + j].alive && alive_neighbors == 3) {
                board[i * size + j].alive = 1; // If dead and has 3 alive neighbors, come to life
            }

            // Update the number of alive neighbors
            board[i * size + j].neighbors_alive = alive_neighbors;
        }
    }
}

// Main function
int main() {
    int size = 10; // Size of the game board
    cell_t *board = malloc(size * size * sizeof(cell_t));
    init_board(board, size);

    for (int gen = 0; gen < 100; gen++) {
        apply_rules(board, size);
        printf("Generation %d:\n", gen);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i * size + j].alive) {
                    printf("Alive cell at (%d, %d)\n", i, j);
                }
            }
        }
    }

    free(board);
    return 0;
}