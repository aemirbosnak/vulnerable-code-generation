//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Structure to represent the game board
typedef struct {
    int rows;
    int cols;
    int **board;
} game_board;

// Function to initialize the game board
void init_board(game_board *board, int rows, int cols) {
    board->rows = rows;
    board->cols = cols;
    board->board = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++) {
        board->board[i] = calloc(cols, sizeof(int));
        for (int j = 0; j < cols; j++) {
            board->board[i][j] = (rand() % 2) ? 1 : 0;
        }
    }
}

// Function to print the game board
void print_board(game_board *board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }
}

// Function to update the game board
void update_board(game_board *board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 || l == 0) {
                        continue;
                    }
                    if (board->board[i + k][j + l] == 1) {
                        alive_neighbors++;
                    }
                }
            }
            if (alive_neighbors < 2 && alive_neighbors > 0) {
                board->board[i][j] = 0;
            } else if (alive_neighbors >= 2) {
                board->board[i][j] = 1;
            } else {
                board->board[i][j] = 0;
            }
        }
    }
}

// Main function
int main() {
    game_board board;
    init_board(&board, 20, 20);
    print_board(&board);
    for (int i = 0; i < 100; i++) {
        update_board(&board);
        print_board(&board);
    }
    return 0;
}