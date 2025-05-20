//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: curious
#include <stdio.h>

// Structure to represent a cell in the game board
typedef struct cell {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to initialize the game board
void init_board(cell_t** board, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            board[i][j].alive = rand() % 2;
            board[i][j].neighbors_alive = 0;
        }
    }
}

// Function to update the game board
void update_board(cell_t** board, int size) {
    int i, j, neighbor_count;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // Count the number of alive neighbors
            neighbor_count = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    if (board[i + k][j + l].alive) {
                        neighbor_count++;
                    }
                }
            }

            // Update the cell's state based on its neighbors
            if (board[i][j].alive && neighbor_count < 2) {
                board[i][j].alive = 0;
            } else if (!board[i][j].alive && neighbor_count >= 2) {
                board[i][j].alive = 1;
            }
            board[i][j].neighbors_alive = neighbor_count;
        }
    }
}

// Function to print the game board
void print_board(cell_t** board, int size) {
    int i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (board[i][j].alive) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int size = 10; // Size of the game board
    cell_t** board = malloc(size * size * sizeof(cell_t));
    init_board(board, size);

    for (int i = 0; i < 100; i++) {
        update_board(board, size);
        print_board(board, size);
    }

    return 0;
}