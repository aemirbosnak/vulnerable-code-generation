//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WINDOW_WIDTH 80
#define WINDOW_HEIGHT 25

// Structure to represent a game board square
typedef struct {
    char symbol;    // Symbol on the square ('.' or 'X')
    int row;       // Row number of the square
    int col;      // Column number of the square
} square_t;

// Function to print the game board
void print_board(square_t *board, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c%d%c", board[i * cols + j].symbol, board[i * cols + j].row + 1, board[i * cols + j].col + 1);
        }
        printf("\n");
    }
}

// Function to get a random square on the game board
square_t *get_random_square(square_t *board, int rows, int cols) {
    int i, j;
    int row = rand() % rows;
    int col = rand() % cols;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (board[i * cols + j].symbol == '.') {
                return &board[i * cols + j];
            }
        }
    }
    return NULL;
}

// Function to make a move on the game board
void make_move(square_t *board, int rows, int cols, char symbol) {
    square_t *square = get_random_square(board, rows, cols);
    if (square != NULL) {
        square->symbol = symbol;
        print_board(board, rows, cols);
    }
}

// Game loop
int main() {
    int rows = WINDOW_HEIGHT;
    int cols = WINDOW_WIDTH;
    square_t *board = calloc(rows * cols, sizeof(square_t));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i * cols + j].symbol = '.';
        }
    }

    char symbol;
    while (1) {
        print_board(board, rows, cols);
        printf("Enter a symbol (X or .): ");
        scanf(" %c", &symbol);

        make_move(board, rows, cols, symbol);

        if (symbol == 'X') {
            printf("You won! Congratulations!\n");
            break;
        }

        if (symbol == '.') {
            printf("You lost. Better luck next time!\n");
            break;
        }
    }

    free(board);
    return 0;
}