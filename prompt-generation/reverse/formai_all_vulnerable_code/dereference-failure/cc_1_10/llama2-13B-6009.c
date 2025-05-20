//LLAMA2-13B DATASET v1.0 Category: Checkers Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_ROWS 8
#define BOARD_COLS 8
#define PIECE_SIZE 3

// Structure to represent a checker board
typedef struct {
    char board[BOARD_ROWS][BOARD_COLS];
    int turn;
} board_t;

// Function to print the board
void print_board(board_t *board) {
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            printf("%c", board->board[i][j] == 'X' ? 'X' : 'O');
        }
        printf("\n");
    }
}

// Function to make a move
void make_move(board_t *board, int row, int col) {
    if (board->board[row][col] == ' ') {
        board->board[row][col] = board->turn == 'X' ? 'O' : 'X';
        board->turn = board->turn == 'X' ? 'O' : 'X';
    }
}

// Function to check if the game is over
int is_game_over(board_t *board) {
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            if (board->board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to get a random move
int get_random_move(board_t *board) {
    int row = rand() % BOARD_ROWS;
    int col = rand() % BOARD_COLS;
    while (board->board[row][col] != ' ') {
        row = rand() % BOARD_ROWS;
        col = rand() % BOARD_COLS;
    }
    return row * BOARD_COLS + col;
}

int main() {
    srand(time(NULL));

    // Initialize the board
    board_t *board = malloc(sizeof(board_t));
    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLS; j++) {
            board->board[i][j] = ' ';
        }
    }
    board->turn = 'X';

    // Play the game
    while (!is_game_over(board)) {
        int move = get_random_move(board);
        make_move(board, move / BOARD_COLS, move % BOARD_COLS);
        print_board(board);
    }

    // Print the final board
    print_board(board);

    return 0;
}