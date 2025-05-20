//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int turn;
    int winner;
} Board;

Board* createBoard() {
    Board* board = (Board*)malloc(sizeof(Board));
    board->board = (int**)malloc(BOARD_SIZE * sizeof(int*));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = (int*)malloc(BOARD_SIZE * sizeof(int));
    }
    board->turn = 0;
    board->winner = 0;
    return board;
}

void displayBoard(Board* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board->board[i][j]);
        }
        printf("\n");
    }
}

int isBoardFull(Board* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int checkWin(Board* board) {
    // Horizontal win
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return board->board[0][i];
        }
    }

    // Vertical win
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return board->board[j][0];
        }
    }

    // Diagonal win
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0];
    }

    // Draw
    if (isBoardFull(board) && board->winner == 0) {
        return -1;
    }

    return 0;
}

int main() {
    Board* board = createBoard();

    // Play the game
    for (int i = 0; i < 9; i++) {
        int move = rand() % 9;
        if (board->board[move / 3][move % 3] == 0) {
            board->board[move / 3][move % 3] = board->turn;
            board->turn++;
        }
    }

    // Check if there is a winner or draw
    int winner = checkWin(board);

    // Display the board
    displayBoard(board);

    // Print the winner or draw
    if (winner != 0) {
        printf("Winner: Player %d\n", winner);
    } else {
        printf("Draw\n");
    }

    return 0;
}