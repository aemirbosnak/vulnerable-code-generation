//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a game board
typedef struct {
    int rows;
    int cols;
    int cells[100][100];
} game_board;

// Function to create a new game board
game_board* new_board(int rows, int cols) {
    game_board* board = malloc(sizeof(game_board));
    board->rows = rows;
    board->cols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board->cells[i][j] = 0; // Initialize all cells as dead
        }
    }
    return board;
}

// Function to print the game board
void print_board(game_board* board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            if (board->cells[i][j] == 1) {
                printf("X");
            } else {
                printf("O");
            }
        }
        printf("\n");
    }
}

// Function to update the game board based on the current state
void update_board(game_board* board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board->cells[i][j] == 0) { // If the cell is dead...
                if (neighbors >= 2 && neighbors <= 3) { // ...and has 2-3 alive neighbors...
                    board->cells[i][j] = 1; // ...then it becomes alive.
                }
            } else if (board->cells[i][j] == 1) { // If the cell is alive...
                if (neighbors < 2 && neighbors > 3) { // ...and has fewer than 2 alive neighbors...
                    board->cells[i][j] = 0; // ...then it dies.
                }
            }
        }
    }
}

// Function to count the number of alive neighbors of a cell
int count_neighbors(game_board* board, int row, int col) {
    int neighbors = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) { // Don't count the cell itself
                continue;
            }
            if (board->cells[row + i][col + j] == 1) {
                neighbors++;
            }
        }
    }
    return neighbors;
}

// Function to play a game of life
void play_game(game_board* board) {
    srand(time(NULL)); // Initialize the random number generator
    for (int i = 0; i < 100; i++) {
        update_board(board); // Update the game board
        print_board(board); // Print the game board
        printf("Generation %d\n", i); // Print the generation number
        sleep(1); // Pause for 1 second before updating again
    }
}

int main() {
    game_board* board = new_board(10, 10); // Create a 10x10 game board
    play_game(board); // Play a game of life on the board
    return 0;
}