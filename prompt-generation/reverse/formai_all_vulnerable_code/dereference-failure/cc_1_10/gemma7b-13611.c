//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 10
#define BOARD_SIZE 5

typedef struct Ball {
    int number;
    struct Ball* next;
} Ball;

typedef struct Board {
    Ball** balls;
    int currentBallIndex;
    int winner;
} Board;

void initializeBoard(Board* board) {
    board->balls = (Ball**)malloc(BOARD_SIZE * sizeof(Ball*));
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->balls[i] = NULL;
    }
    board->currentBallIndex = 0;
    board->winner = 0;
}

void addBallToBoard(Board* board) {
    Ball* newBall = (Ball*)malloc(sizeof(Ball));
    newBall->number = rand() % MAX_BALLS + 1;
    newBall->next = NULL;

    if (board->balls[board->currentBallIndex] != NULL) {
        board->balls[board->currentBallIndex]->next = newBall;
    } else {
        board->balls[board->currentBallIndex] = newBall;
    }

    board->currentBallIndex++;
}

int checkWin(Board* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board->balls[i] == NULL) {
            continue;
        }
        int winningNumbers[5] = { board->balls[i]->number, board->balls[i]->number, board->balls[i]->number, board->balls[i]->number, board->balls[i]->number };
        int win = 1;
        for (int j = 0; j < 5; j++) {
            if (board->balls[i]->number != winningNumbers[j]) {
                win = 0;
            }
        }
        if (win) {
            board->winner = 1;
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));

    Board* board = (Board*)malloc(sizeof(Board));
    initializeBoard(board);

    for (int i = 0; i < MAX_BALLS; i++) {
        addBallToBoard(board);
    }

    while (!checkWin(board)) {
        addBallToBoard(board);
    }

    if (board->winner) {
        printf("Congratulations! You won!\n");
    } else {
        printf("Sorry, no winner.\n");
    }

    free(board);
    return 0;
}