//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 100
#define CELL_SIZE 20

// Structure to represent a cell in the game board
typedef struct {
    int alive; // Whether the cell is alive or not
    int neighbors_alive; // Number of alive neighbors
} cell_t;

// Function to generate the initial game board
void generate_board(cell_t** board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Generate a random value for the cell
            int random = rand() % 2;

            // Set the cell's alive status based on the random value
            board[i][j].alive = random;

            // Increment the number of alive neighbors for the cell
            if (i > 0) {
                board[i][j].neighbors_alive += board[i - 1][j].alive;
            }
            if (j > 0) {
                board[i][j].neighbors_alive += board[i][j - 1].alive;
            }
        }
    }
}

// Function to update the game board based on the current state
void update_board(cell_t** board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Calculate the number of alive neighbors for the cell
            int neighbors_alive = 0;
            if (i > 0) {
                neighbors_alive += board[i - 1][j].alive;
            }
            if (j > 0) {
                neighbors_alive += board[i][j - 1].alive;
            }

            // Update the cell's alive status based on the number of alive neighbors
            board[i][j].alive = (neighbors_alive >= 2) && (board[i][j].alive == 1);

            // Update the number of alive neighbors for the cell
            board[i][j].neighbors_alive = neighbors_alive;
        }
    }
}

// Function to draw the game board
void draw_board(cell_t** board, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int main() {
    int board_size = BOARD_SIZE;
    cell_t** board = malloc(board_size * sizeof(cell_t*));
    for (int i = 0; i < board_size; i++) {
        board[i] = malloc(board_size * sizeof(cell_t));
    }

    generate_board(board, board_size);

    while (1) {
        update_board(board, board_size);
        draw_board(board, board_size);

        // Wait for user input to continue or quit
        printf("Press enter to continue, or 'q' to quit\n");
        char input = getchar();
        if (input == 'q') {
            break;
        }
    }

    // Free memory for the game board
    for (int i = 0; i < board_size; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}