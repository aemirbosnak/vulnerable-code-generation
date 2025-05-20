//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

// Function to initialize the game board
void initializeBoard(bool *board) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        board[i] = true;
    }
}

// Function to update the board state
void updateBoard(bool *board, int *next) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        next[i] = board[i];
    }

    // Count the number of live neighbors for each cell
    int neighbors = 0;
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int row = i / WIDTH;
        int col = i % WIDTH;

        neighbors += board[i]? board[i - WIDTH] : 0;
        neighbors += board[i]? board[i + 1] : 0;
        neighbors += board[i]? board[i + WIDTH] : 0;
        neighbors += board[i]? board[i - 1] : 0;
        neighbors += board[i]? board[i - WIDTH + 1] : 0;
        neighbors += board[i]? board[i + 1 + WIDTH] : 0;
        neighbors += board[i]? board[i + WIDTH - 1] : 0;
        neighbors += board[i]? board[i + WIDTH - 1 + 1] : 0;
    }

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (board[i]) {
            if (neighbors == 2 || neighbors == 3) {
                next[i] = true;
            } else if (neighbors == 3) {
                next[i] = true;
            } else {
                next[i] = false;
            }
        } else {
            if (neighbors == 3) {
                next[i] = true;
            } else {
                next[i] = false;
            }
        }
    }
}

// Function to print the board
void printBoard(bool *board) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%d", board[i]? 1 : 0);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Allocate memory for the board
    bool *board = (bool *)malloc(WIDTH * HEIGHT * sizeof(bool));

    // Initialize the board
    initializeBoard(board);

    // Update the board for a certain number of generations
    for (int i = 0; i < 10; i++) {
        // Update the board state
        updateBoard(board, board);

        // Print the current board state
        printBoard(board);
    }

    // Free the memory allocated for the board
    free(board);

    return 0;
}