//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a game board
typedef struct {
    int rows;
    int cols;
    int** cells;
} game_board;

// Function to create a new game board
game_board* new_game_board(int rows, int cols) {
    game_board* board = (game_board*) malloc(sizeof(game_board));
    board->rows = rows;
    board->cols = cols;
    board->cells = (int**) malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        board->cells[i] = (int*) malloc(sizeof(int) * cols);
        for (int j = 0; j < cols; j++) {
            board->cells[i][j] = 0; // Initialize all cells to 0
        }
    }
    return board;
}

// Function to print the game board
void print_board(game_board* board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            printf("%d", board->cells[i][j]);
        }
        printf("\n");
    }
}

// Function to apply the game of life rules
void apply_rules(game_board* board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            // Check if the cell is alive
            if (board->cells[i][j] == 1) {
                // If the cell is alive and has two or three alive neighbors, leave it alive
                if (count_alive_neighbors(board, i, j) >= 2 && count_alive_neighbors(board, i, j) <= 3) {
                    board->cells[i][j] = 1;
                } else {
                    // If the cell is alive and has less than two alive neighbors, die
                    if (count_alive_neighbors(board, i, j) < 2) {
                        board->cells[i][j] = 0;
                    }
                }
            }
        }
    }
}

// Function to count the number of alive neighbors of a cell
int count_alive_neighbors(game_board* board, int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 || j == 0) {
                continue;
            }
            if (board->cells[row + i][col + j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    game_board* board = new_game_board(10, 10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board->cells[i][j] = (i % 2 == 0) ? 1 : 0;
        }
    }
    print_board(board);
    apply_rules(board);
    print_board(board);
    return 0;
}