//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Board {
    int **board;
    int turn;
    int winner;
} Board;

Board *initBoard() {
    Board *board = malloc(sizeof(Board));
    board->board = malloc(sizeof(int *) * BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->board[i] = malloc(sizeof(int) * BOARD_SIZE);
    }
    board->turn = 0;
    board->winner = -1;
    return board;
}

void placeMove(Board *board, int x, int y) {
    if (board->board[x][y] != 0) {
        return;
    }
    board->board[x][y] = board->turn;
}

int checkWin(Board *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[0][i] == board->board[2][i] && board->board[0][i] != 0) {
            return board->board[0][i];
        }
    }
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board->board[j][0] == board->board[j][1] && board->board[j][0] == board->board[j][2] && board->board[j][0] != 0) {
            return board->board[j][0];
        }
    }
    if (board->board[0][0] == board->board[1][1] && board->board[0][0] == board->board[2][2] && board->board[0][0] != 0) {
        return board->board[0][0];
    }
    return -1;
}

void playGame(Board *board) {
    int move = 0;
    while (!checkWin(board) && move < 9) {
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);
        placeMove(board, x, y);
        move++;
    }
    if (checkWin(board) != -1) {
        printf("Winner: Player %d\n", checkWin(board));
    } else {
        printf("It's a draw!\n");
    }
}

int main() {
    Board *board = initBoard();
    playGame(board);
    free(board);
    return 0;
}