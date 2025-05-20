//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define SQUARE_SIZE 50

// Structure to represent a table game board
typedef struct {
    char **board;
    int rows;
    int cols;
} table_game_board;

// Function to initialize the board with random values
void init_board(table_game_board *board) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        board->board[i] = malloc(COLS * sizeof(char));
        for (j = 0; j < COLS; j++) {
            board->board[i][j] = 'X' + (rand() % 2);
        }
    }
}

// Function to print the board
void print_board(table_game_board *board) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
}

// Function to make a move
void make_move(table_game_board *board, int row, int col) {
    char old_value = board->board[row][col];
    board->board[row][col] = old_value == 'X' ? 'O' : 'X';
}

// Function to check for a win
int check_win(table_game_board *board) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board->board[i][j] == 'X' && board->board[i][j + 1] == 'X' && board->board[i][j + 2] == 'X') {
                return 1;
            }
            if (board->board[i][j] == 'O' && board->board[i][j + 1] == 'O' && board->board[i][j + 2] == 'O') {
                return 2;
            }
        }
    }
    return 0;
}

// Main game loop
int main() {
    table_game_board board;
    init_board(&board);

    while (1) {
        print_board(&board);
        int row, col;
        scanf("%d%d", &row, &col);
        make_move(&board, row, col);
        if (check_win(&board)) {
            break;
        }
    }
    return 0;
}