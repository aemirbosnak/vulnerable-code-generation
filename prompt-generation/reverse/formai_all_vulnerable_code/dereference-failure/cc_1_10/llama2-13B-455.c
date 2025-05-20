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
game_board *new_board(int rows, int cols) {
    game_board *board = (game_board *)malloc(sizeof(game_board));
    board->rows = rows;
    board->cols = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board->cells[i][j] = 0; // Initialize all cells to 0
        }
    }
    return board;
}

// Function to update the game board
void update_board(game_board *board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            // If the cell is alive and has two or three alive neighbors, leave it alive
            if (board->cells[i][j] == 1 && check_neighbors(board, i, j) >= 2) {
                board->cells[i][j] = 1;
            }
            // If the cell is dead and has exactly three alive neighbors, bring it to life
            else if (board->cells[i][j] == 0 && check_neighbors(board, i, j) == 3) {
                board->cells[i][j] = 1;
            }
            // Otherwise, leave the cell dead
        }
    }
}

// Function to check the number of alive neighbors of a cell
int check_neighbors(game_board *board, int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (board->cells[row + i][col + j] == 1) {
                count++;
            }
        }
    }
    return count;
}

// Main function
int main() {
    // Create a new game board
    game_board *board = new_board(10, 10);

    // Initialize the cells with random values
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board->cells[i][j] = (rand() % 2) ? 1 : 0;
        }
    }

    // Update the board for 100 generations
    for (int i = 0; i < 100; i++) {
        update_board(board);
    }

    // Print the final board
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            printf("%d ", board->cells[i][j]);
        }
        printf("\n");
    }

    return 0;
}