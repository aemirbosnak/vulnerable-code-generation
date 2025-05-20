//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The game board is represented as a 2D array of booleans, where true
// indicates a living cell and false indicates a dead cell.
bool **board;

// The size of the game board.
int size;

// Initialize the game board with a random pattern of living and dead cells.
void init_board() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// Print the game board to the console.
void print_board() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c", board[i][j] ? 'X' : ' ');
        }
        printf("\n");
    }
}

// Count the number of living neighbors of a cell.
int count_neighbors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // Ignore the cell itself.
            if (i == 0 && j == 0) {
                continue;
            }
            // Wrap around the edges of the board.
            int nx = (x + i + size) % size;
            int ny = (y + j + size) % size;
            if (board[nx][ny]) {
                count++;
            }
        }
    }
    return count;
}

// Update the game board to the next generation.
void update_board() {
    // Create a temporary board to store the next generation.
    bool **next = malloc(sizeof(bool *) * size);
    for (int i = 0; i < size; i++) {
        next[i] = malloc(sizeof(bool) * size);
    }

    // Update each cell based on the number of living neighbors.
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int neighbors = count_neighbors(i, j);
            if (board[i][j]) {
                // A living cell with 2 or 3 neighbors survives.
                next[i][j] = neighbors == 2 || neighbors == 3;
            } else {
                // A dead cell with exactly 3 neighbors is born.
                next[i][j] = neighbors == 3;
            }
        }
    }

    // Copy the next generation to the game board.
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = next[i][j];
        }
        free(next[i]);
    }
    free(next);
}

// Play the game of life for a specified number of generations.
void play_game(int generations) {
    for (int i = 0; i < generations; i++) {
        printf("Generation %d\n", i + 1);
        print_board();
        update_board();
    }
}

// Free the memory allocated for the game board.
void free_board() {
    for (int i = 0; i < size; i++) {
        free(board[i]);
    }
    free(board);
}

// Main function.
int main() {
    // Set the size of the game board.
    size = 20;

    // Allocate memory for the game board.
    board = malloc(sizeof(bool *) * size);
    for (int i = 0; i < size; i++) {
        board[i] = malloc(sizeof(bool) * size);
    }

    // Initialize the game board with a random pattern.
    init_board();

    // Play the game of life for 100 generations.
    play_game(100);

    // Free the memory allocated for the game board.
    free_board();

    return 0;
}