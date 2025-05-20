//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Cell {
    int row;
    int col;
    char symbol;
} Cell;

void initializeBoard(Cell **board);
void placeSymbol(Cell **board, char symbol, int row, int col);
int isBoardFull(Cell **board);
int checkWin(Cell **board, char symbol);

int main() {
    srand(time(NULL));

    Cell **board = NULL;
    initializeBoard(&board);

    char currentSymbol = 'X';
    int gameWon = 0;

    // Play until someone wins or the board is full
    while (!gameWon && !isBoardFull(board)) {
        int row = rand() % BOARD_SIZE;
        int col = rand() % BOARD_SIZE;

        placeSymbol(board, currentSymbol, row, col);

        gameWon = checkWin(board, currentSymbol);

        currentSymbol = (currentSymbol == 'X') ? 'O' : 'X';
    }

    // Print the winner or draw
    if (gameWon) {
        printf("The winner is: %c\n", currentSymbol);
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}

void initializeBoard(Cell **board) {
    *board = (Cell *)malloc(sizeof(Cell) * BOARD_SIZE * BOARD_SIZE);

    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        (*board)[i].row = -1;
        (*board)[i].col = -1;
        (*board)[i].symbol = '\0';
    }
}

void placeSymbol(Cell **board, char symbol, int row, int col) {
    board[row][col].symbol = symbol;
    board[row][col].row = row;
    board[row][col].col = col;
}

int isBoardFull(Cell **board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            if (board[r][c].symbol == '\0') {
                return 0;
            }
        }
    }

    return 1;
}

int checkWin(Cell **board, char symbol) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board[r][0].symbol == symbol && board[r][1].symbol == symbol && board[r][2].symbol == symbol) {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board[0][c].symbol == symbol && board[1][c].symbol == symbol && board[2][c].symbol == symbol) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0].symbol == symbol && board[1][1].symbol == symbol && board[2][2].symbol == symbol) {
        return 1;
    }

    if (board[0][2].symbol == symbol && board[1][1].symbol == symbol && board[2][0].symbol == symbol) {
        return 1;
    }

    return 0;
}