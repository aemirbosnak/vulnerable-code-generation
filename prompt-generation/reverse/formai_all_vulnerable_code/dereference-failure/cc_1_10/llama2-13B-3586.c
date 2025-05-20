//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

// Structure to represent a cell in the game board
typedef struct {
    char state; // 0 for empty, 1 for alive, 2 for dead
    char next; // Next state (only relevant for alive cells)
} cell_t;

// Global variables for the game board and the current state
cell_t** board; // Game board, 2D array of size WIDTH x HEIGHT
int curr_state; // Current state of the game

// Function to print the game board
void print_board() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%c", board[i][j].state == 1 ? 'X' : ' ');
        }
        printf("\n");
    }
}

// Function to update the game board based on the current state
void update_board() {
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // If the cell is alive and has no living neighbors, it dies
            if (board[i][j].state == 1 && !alive_neighbors(i, j)) {
                board[i][j].state = 2;
            }
            // If the cell is alive and has living neighbors, it reproduces
            else if (board[i][j].state == 1 && alive_neighbors(i, j)) {
                board[i][j].state = 1;
                board[i][j].next = (board[i][j].state == 1) ? 2 : 1;
            }
            // If the cell is dead, it stays dead
            else {
                board[i][j].state = 0;
            }
        }
    }
}

// Function to check if a cell has living neighbors
int alive_neighbors(int i, int j) {
    int count = 0;
    int k;
    for (k = -1; k <= 1; k++) {
        if (k == 0 || abs(k) == 1) {
            if (board[i + k][j + k].state == 1) {
                count++;
            }
        }
    }
    return count;
}

// Main game loop
int main() {
    srand(time(NULL));
    // Initialize the game board with random values
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            board[i][j].state = (rand() % 3) + 1;
        }
    }

    while (1) {
        // Print the game board
        print_board();

        // Update the game board based on the current state
        update_board();

        // Check if the game is over
        if (curr_state == 2) {
            printf("Game Over! The X's won.\n");
            break;
        } else if (curr_state == 1) {
            printf("Game Over! The O's won.\n");
            break;
        }
    }

    return 0;
}