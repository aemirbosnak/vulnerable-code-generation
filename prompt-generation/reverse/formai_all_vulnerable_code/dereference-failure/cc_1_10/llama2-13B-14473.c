//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25

// Structure to represent a cell in the game of life
typedef struct cell {
    int state; // 0 for dead, 1 for alive
    int neighbors; // number of alive neighbors
} cell_t;

// Function to create the game board
cell_t* create_board() {
    cell_t* board = malloc(WIDTH * HEIGHT * sizeof(cell_t));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        board[i].state = rand() % 2; // Initialize cells randomly
        board[i].neighbors = 0;
    }
    return board;
}

// Function to update the game board
void update_board(cell_t* board) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int alive_neighbors = 0;
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                if (i + j >= 0 && i + j < WIDTH && board[i + j].state == 1) {
                    alive_neighbors++;
                }
                if (i + k >= 0 && i + k < WIDTH && board[i + k].state == 1) {
                    alive_neighbors++;
                }
            }
        }
        board[i].neighbors = alive_neighbors;
        if (board[i].state == 0 && alive_neighbors > 1) {
            board[i].state = 1; // Alive cell becomes alive
        } else if (board[i].state == 1 && alive_neighbors < 2) {
            board[i].state = 0; // Alive cell becomes dead
        }
    }
}

// Function to display the game board
void display_board(cell_t* board) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (board[i * HEIGHT + j].state == 1) {
                printf("| %c |", 'A' + (j % 2)); // Use ASCII art to represent alive cells
            } else {
                printf("| %c |", 'A' + (j % 2)); // Use ASCII art to represent dead cells
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    cell_t* board = create_board(); // Create the game board

    for (int i = 0; i < 100; i++) { // Loop for 100 generations
        update_board(board); // Update the game board
        display_board(board); // Display the game board
    }

    return 0;
}