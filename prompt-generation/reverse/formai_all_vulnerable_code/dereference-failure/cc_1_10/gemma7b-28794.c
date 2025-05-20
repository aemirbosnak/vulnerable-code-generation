//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define PLAYER_X 'X'
#define PLAYER_O 'O'

typedef struct GameBoard {
    char board[BOARD_SIZE][BOARD_SIZE];
    char currentPlayer;
    int gameStatus;
} GameBoard;

GameBoard *initializeGameBoard() {
    GameBoard *board = malloc(sizeof(GameBoard));
    board->currentPlayer = PLAYER_X;
    board->gameStatus = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = ' ';
        }
    }

    return board;
}

void displayGameBoard(GameBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board->board[i][j]);
        }
        printf("\n");
    }
}

void makeMove(GameBoard *board, int row, int col) {
    if (board->board[row][col] != ' ') {
        return;
    }

    board->board[row][col] = board->currentPlayer;
}

int checkWin(GameBoard *board) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != ' ') {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != ' ') {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != ' ') {
        return 1;
    }

    // If all cells are filled and no winner, it's a draw
    if (board->gameStatus == 0 && board->board[0][0] == board->board[0][1] && board->board[0][0] == board->board[0][2]) {
        return 2;
    }

    return 0;
}

int main() {
    GameBoard *board = initializeGameBoard();

    // Play the game
    while (board->gameStatus == 0) {
        displayGameBoard(board);

        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);

        printf("Enter column: ");
        scanf("%d", &col);

        makeMove(board, row, col);

        if (checkWin(board) == 1) {
            displayGameBoard(board);
            printf("Winner: %c!", board->currentPlayer);
            break;
        } else if (checkWin(board) == 2) {
            displayGameBoard(board);
            printf("It's a draw!");
            break;
        }
    }

    return 0;
}