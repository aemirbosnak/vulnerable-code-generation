//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>

// Structure to represent the game board
typedef struct {
    int rows;
    int cols;
    int** board;
} game_board;

// Function to initialize the game board
void init_board(game_board* board, int rows, int cols) {
    board->rows = rows;
    board->cols = cols;
    board->board = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        board->board[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            board->board[i][j] = rand() % 2;
        }
    }
}

// Function to update the game board
void update_board(game_board* board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            // Calculate the number of alive neighbors
            int alive_neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (k == 0 && l == 0) continue;
                    if (board->board[i + k][j + l] != 0) {
                        alive_neighbors++;
                    }
                }
            }

            // Apply the rules
            if (board->board[i][j] == 1 && alive_neighbors < 2) {
                board->board[i][j] = 0; // die of loneliness
            } else if (board->board[i][j] == 0 && alive_neighbors >= 3) {
                board->board[i][j] = 1; // reproduce
            } else if (board->board[i][j] == 1 && alive_neighbors == 2) {
                board->board[i][j] = 1; // survive
            }
        }
    }
}

// Function to print the game board
void print_board(game_board* board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    game_board* board = malloc(sizeof(game_board));
    init_board(board, 20, 20);

    for (int i = 0; i < 100; i++) {
        update_board(board);
        print_board(board);
    }

    free(board->board);
    free(board);
    return 0;
}