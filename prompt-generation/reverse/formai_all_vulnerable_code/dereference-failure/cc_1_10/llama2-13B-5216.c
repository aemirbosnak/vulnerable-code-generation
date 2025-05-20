//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>

// Structure to represent a game board
typedef struct {
    int rows;
    int cols;
    int **grid;
} game_board;

// Function to initialize the game board
void init_board(game_board *board, int rows, int cols) {
    board->rows = rows;
    board->cols = cols;
    board->grid = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        board->grid[i] = calloc(cols, sizeof(int));
    }
}

// Function to print the game board
void print_board(game_board *board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            printf("%d", board->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to apply the game of life rules
void apply_rules(game_board *board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            // Check if the cell is alive
            if (board->grid[i][j] == 1) {
                // If the cell is alive and has two or three alive neighbors, leave it alive
                if (check_neighbors(board, i, j, 2) || check_neighbors(board, i, j, 3)) {
                    board->grid[i][j] = 1;
                } else {
                    // If the cell is alive and has less than two alive neighbors, die
                    board->grid[i][j] = 0;
                }
            } else {
                // If the cell is dead and has three alive neighbors, come to life
                if (check_neighbors(board, i, j, 3)) {
                    board->grid[i][j] = 1;
                }
            }
        }
    }
}

// Function to check the number of alive neighbors of a cell
int check_neighbors(game_board *board, int row, int col, int threshold) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (board->grid[row + i][col + j] == 1) {
                count++;
            }
        }
    }
    return count >= threshold;
}

// Main function
int main() {
    game_board board;
    init_board(&board, 20, 20);
    for (int i = 0; i < 100; i++) {
        apply_rules(&board);
        print_board(&board);
    }
    return 0;
}