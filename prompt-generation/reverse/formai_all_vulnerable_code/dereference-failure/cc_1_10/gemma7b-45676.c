//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BALLS 100
#define BOARD_SIZE 5

typedef struct Ball {
    int number;
    struct Ball* next;
} Ball;

typedef struct Board {
    Ball** squares;
    int size;
} Board;

void initializeBoard(Board* board) {
    board->squares = malloc(board->size * sizeof(Ball**));
    for (int i = 0; i < board->size; i++) {
        board->squares[i] = NULL;
    }
}

void addBall(Ball* ball, Board* board) {
    Ball* lastBall = board->squares[ball->number - 1];
    if (lastBall) {
        lastBall->next = ball;
    } else {
        initializeBoard(board);
        board->squares[ball->number - 1] = ball;
    }
}

int main() {
    srand(time(NULL));
    Board* board = malloc(sizeof(Board));
    board->size = BOARD_SIZE;
    initializeBoard(board);

    // Generate balls
    Ball* head = NULL;
    for (int i = 0; i < MAX_BALLS; i++) {
        Ball* ball = malloc(sizeof(Ball));
        ball->number = rand() % MAX_BALLS + 1;
        addBall(ball, board);
        head = ball;
    }

    // Play the game
    printf("Bingo! Please match the following numbers:");
    for (int i = 0; i < MAX_BALLS; i++) {
        Ball* ball = head;
        while (ball) {
            if (ball->number == i + 1) {
                printf("%d ", ball->number);
                free(ball);
                break;
            }
            ball = ball->next;
        }
    }
    printf("\n");

    free(board);
    free(head);
    return 0;
}