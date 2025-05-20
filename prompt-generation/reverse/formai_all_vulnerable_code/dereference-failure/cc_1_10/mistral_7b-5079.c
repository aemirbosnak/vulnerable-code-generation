//MISTRAL-7B DATASET v1.0 Category: Bingo Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_BOARD_SIZE 5
#define BINGO_CALLS_COUNT 25

typedef struct {
    int numbers[BINGO_BOARD_SIZE][BINGO_BOARD_SIZE];
    int markers[BINGO_BOARD_SIZE][BINGO_BOARD_SIZE];
} BingoBoard;

void initializeBoard(BingoBoard *board) {
    for (int i = 0; i < BINGO_BOARD_SIZE; ++i) {
        for (int j = 0; j < BINGO_BOARD_SIZE; ++j) {
            board->numbers[i][j] = i * BINGO_BOARD_SIZE + j + 1;
            board->markers[i][j] = 0;
        }
    }
}

void printBoard(const BingoBoard *board) {
    for (int i = 0; i < BINGO_BOARD_SIZE; ++i) {
        for (int j = 0; j < BINGO_BOARD_SIZE; ++j) {
            printf("%3d ", board->numbers[i][j]);
            if (board->markers[i][j])
                printf("X");
            else
                printf("-");
        }
        printf("\n");
    }
}

void callBall(BingoBoard *board) {
    srand(time(NULL));
    int ball = rand() % (BINGO_BOARD_SIZE * BINGO_BOARD_SIZE) + 1;
    int row = ball / BINGO_BOARD_SIZE;
    int col = ball % BINGO_BOARD_SIZE;

    if (board->markers[row][col]) {
        callBall(board);
        return;
    }

    board->markers[row][col] = 1;
}

int checkBingo(const BingoBoard *board) {
    for (int i = 0; i < BINGO_BOARD_SIZE; ++i) {
        if (board->markers[i][0] && board->markers[i][1] && board->markers[i][2] && board->markers[i][3] && board->markers[i][4])
            return 1;

        if (board->markers[0][i] && board->markers[1][i] && board->markers[2][i] && board->markers[3][i] && board->markers[4][i])
            return 1;
    }

    for (int i = 0; i < BINGO_BOARD_SIZE; ++i) {
        if (board->markers[i][i])
            return 1;
    }

    for (int i = 0; i < BINGO_BOARD_SIZE; ++i) {
        if (board->markers[4 - i][i])
            return 1;
    }

    return 0;
}

int main() {
    BingoBoard board;
    initializeBoard(&board);

    printf("Initial board:\n");
    printBoard(&board);

    printf("\nCalling balls...\n");
    for (int i = 0; i < BINGO_CALLS_COUNT; ++i)
        callBall(&board);

    if (checkBingo(&board)) {
        printf("\nBINGO! Congratulations!\n");
        printBoard(&board);
    } else {
        printf("\nNo BINGO yet.\n");
    }

    return 0;
}