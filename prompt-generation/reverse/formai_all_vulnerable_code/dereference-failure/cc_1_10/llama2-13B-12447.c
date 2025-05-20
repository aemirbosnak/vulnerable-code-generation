//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 10)

// Structure to represent a cell
typedef struct {
    int alive;
} cell_t;

// Function to generate a random number between 0 and 1
float random_float() {
    return (float)rand() / RAND_MAX;
}

// Function to draw the game board
void draw_board(cell_t** board, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (board[i][j].alive) {
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to update the game board
void update_board(cell_t** board, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // If the cell is alive and has two or three alive neighbors, leave it alive
            if (board[i][j].alive && (board[i][j - 1].alive || board[i][j + 1].alive || board[i - 1][j].alive || board[i + 1][j].alive)) {
                board[i][j].alive = 1;
            } else {
                // If the cell is alive and has fewer than two alive neighbors, die
                if (board[i][j].alive && !(board[i][j - 1].alive && board[i][j + 1].alive)) {
                    board[i][j].alive = 0;
                }
                // If the cell is dead and has exactly three alive neighbors, come to life
                else if (!board[i][j].alive && board[i][j - 1].alive && board[i][j + 1].alive && board[i - 1][j].alive && board[i + 1][j].alive) {
                    board[i][j].alive = 1;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // Initialize the game board
    cell_t** board = malloc(WINDOW_WIDTH * sizeof(cell_t *));
    for (int i = 0; i < WINDOW_WIDTH; i++) {
        board[i] = malloc(WINDOW_HEIGHT * sizeof(cell_t));
        for (int j = 0; j < WINDOW_HEIGHT; j++) {
            board[i][j].alive = random_float() < 0.5;
        }
    }

    // Draw the initial game board
    draw_board(board, WINDOW_WIDTH, WINDOW_HEIGHT);

    // Update the game board for a few generations
    for (int gen = 0; gen < 10; gen++) {
        update_board(board, WINDOW_WIDTH, WINDOW_HEIGHT);
    }

    // Draw the final game board
    draw_board(board, WINDOW_WIDTH, WINDOW_HEIGHT);

    // Free the game board memory
    for (int i = 0; i < WINDOW_WIDTH; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}