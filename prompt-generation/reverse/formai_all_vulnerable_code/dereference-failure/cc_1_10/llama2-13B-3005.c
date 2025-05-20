//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define CELL_SIZE 10
#define BOARD_SIZE (CELL_SIZE * CELL_SIZE)

// Structure to represent a cell in the game of life
typedef struct {
    int alive; // Whether the cell is alive or not
    int born; // Whether the cell was born in the current generation
} cell_t;

// Function to initialize the game of life board with random cells
void init_board(cell_t** board) {
    int i, j;
    for (i = 0; i < CELL_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            board[i][j].alive = rand() % 2;
            board[i][j].born = 0;
        }
    }
}

// Function to apply the game of life rules to the board
void update_board(cell_t** board) {
    int i, j;
    for (i = 0; i < CELL_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            if (board[i][j].alive && board[i][j].born == 0) {
                // If the cell is alive and has not been born before, it is born
                board[i][j].born = 1;
            }
            if (board[i][j].alive && board[i][j].born == 1) {
                // If the cell is alive and has been born before, it dies
                board[i][j].alive = 0;
            }
            if (!board[i][j].alive && board[i][j].born == 1) {
                // If the cell is dead and has been born before, it revives
                board[i][j].alive = 1;
            }
        }
    }
}

// Function to print the game of life board
void print_board(cell_t** board) {
    int i, j;
    for (i = 0; i < CELL_SIZE; i++) {
        for (j = 0; j < CELL_SIZE; j++) {
            printf("%d ", board[i][j].alive);
        }
        printf("\n");
    }
}

int main() {
    cell_t** board = (cell_t**) malloc(CELL_SIZE * sizeof(cell_t*));
    for (int i = 0; i < CELL_SIZE; i++) {
        board[i] = (cell_t*) malloc(CELL_SIZE * sizeof(cell_t));
    }
    init_board(board);

    int generations = 100;
    for (int i = 0; i < generations; i++) {
        update_board(board);
        print_board(board);
        printf("Generation %d\n", i + 1);
        sleep(1); // Simulate time passing
    }

    return 0;
}