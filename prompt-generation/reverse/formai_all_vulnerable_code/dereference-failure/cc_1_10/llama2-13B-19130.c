//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define BOARD_SIZE 100

// Structure to represent a cell in the game of life
typedef struct {
    int alive;  // Whether the cell is alive or not
    int neighbors_alive;  // Number of alive neighbors
} cell_t;

// Function to initialize the game of life board
void init_board(cell_t** board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            // Initialize cell as alive with 2 alive neighbors
            board[i][j].alive = 1;
            board[i][j].neighbors_alive = 2;
        }
    }
}

// Function to update the game of life board
void update_board(cell_t** board) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            // Update cell based on its alive state and neighbors
            if (board[i][j].alive) {
                // If cell is alive and has 2 alive neighbors, keep it alive
                if (board[i][j].neighbors_alive == 2) {
                    board[i][j].alive = 1;
                }
                // If cell is alive and has 3 alive neighbors, die
                else if (board[i][j].neighbors_alive == 3) {
                    board[i][j].alive = 0;
                }
                // If cell is alive and has less than 2 alive neighbors, die
                else {
                    board[i][j].alive = 0;
                }
            }
            // If cell is dead and has 3 alive neighbors, come to life
            else {
                if (board[i][j].neighbors_alive == 3) {
                    board[i][j].alive = 1;
                }
            }
        }
    }
}

int main() {
    cell_t** board = (cell_t**) malloc(BOARD_SIZE * sizeof(cell_t*));
    init_board(board);

    // Loop the game of life for 10 generations
    for (int gen = 0; gen < 10; gen++) {
        update_board(board);
        printf("Generation %d: \n", gen + 1);
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j].alive) {
                    printf("Cell %d, %d is alive\n", i, j);
                } else {
                    printf("Cell %d, %d is dead\n", i, j);
                }
            }
        }
        printf("\n");
    }

    free(board);
    return 0;
}