//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

typedef struct GameBoard {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;
    int moveCounter;
} GameBoard;

void initializeGameBoard(GameBoard *board) {
    board->currentPlayer = PLAYER_X;
    board->moveCounter = 0;

    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            board->board[r][c] = ' ';
        }
    }
}

void displayGameBoard(GameBoard *board) {
    for (int r = 0; r < BOARD_SIZE; r++) {
        for (int c = 0; c < BOARD_SIZE; c++) {
            printf("%c ", board->board[r][c]);
        }
        printf("\n");
    }
}

int validateMove(GameBoard *board, int row, int column) {
    if (board->board[row][column] != ' ') {
        return 0;
    }

    if (board->currentPlayer == PLAYER_X) {
        board->board[row][column] = PLAYER_X;
    } else if (board->currentPlayer == PLAYER_O) {
        board->board[row][column] = PLAYER_O;
    }

    board->moveCounter++;

    return 1;
}

int checkWin(GameBoard *board) {
    // Check rows
    for (int r = 0; r < BOARD_SIZE; r++) {
        if (board->board[r][0] == board->board[r][1] && board->board[r][0] == board->board[r][2] && board->board[r][0] != ' ') {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < BOARD_SIZE; c++) {
        if (board->board[0][c] == board->board[1][c] && board->board[0][c] == board->board[2][c] && board->board[0][c] != ' ') {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != ' ') {
        return 1;
    }

    // If all moves have been made and there is no winner, it's a draw
    return 2;
}

int main() {
    GameBoard board;
    initializeGameBoard(&board);

    displayGameBoard(&board);

    while (1) {
        int row, column;
        printf("Enter row: ");
        scanf("%d", &row);

        printf("Enter column: ");
        scanf("%d", &column);

        if (validateMove(&board, row, column) == 0) {
            printf("Invalid move.\n");
        } else if (checkWin(&board) == 1) {
            printf("Winner: %c!\n", board.currentPlayer);
            break;
        } else if (checkWin(&board) == 2) {
            printf("It's a draw!\n");
            break;
        }
    }

    displayGameBoard(&board);

    return 0;
}