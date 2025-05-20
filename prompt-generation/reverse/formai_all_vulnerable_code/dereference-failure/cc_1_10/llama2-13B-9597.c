//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent the game board
typedef struct {
    int rows;
    int cols;
    int **board;
} game_board_t;

// Function to create a new game board
game_board_t *new_game_board(int rows, int cols) {
    game_board_t *board = (game_board_t *) malloc(sizeof(game_board_t));
    board->rows = rows;
    board->cols = cols;
    board->board = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        board->board[i] = (int *) malloc(cols * sizeof(int));
    }
    return board;
}

// Function to print the game board
void print_board(game_board_t *board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }
}

// Function to apply the game of life rules
void apply_rules(game_board_t *board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->cols; j++) {
            // Check if the cell is alive
            if (board->board[i][j] == 1) {
                // If alive, apply the rules
                if (is_alive_neighbor(board, i, j) > 1) {
                    board->board[i][j] = 1; // If there are 2 or 3 alive neighbors, keep the cell alive
                } else if (is_alive_neighbor(board, i, j) == 2) {
                    board->board[i][j] = 0; // If there is only one alive neighbor, die
                }
            }
        }
    }
}

// Function to check if a cell has alive neighbors
int is_alive_neighbor(game_board_t *board, int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (board->board[row + i][col + j] == 1) {
                count++;
            }
        }
    }
    return count;
}

// Function to run the game of life
void run_game(game_board_t *board) {
    for (int i = 0; i < 100; i++) {
        apply_rules(board);
        print_board(board);
    }
}

int main() {
    game_board_t *board = new_game_board(10, 10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board->board[i][j] = rand() % 2;
        }
    }
    run_game(board);
    return 0;
}