//Gemma-7B DATASET v1.0 Category: Breakout Game Clone ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 5
#define BALL_SIZE 2

typedef struct Ball {
    int x, y;
    int dx, dy;
} Ball;

void initialize_board(int **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void draw_board(int **board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void move_ball(Ball *ball) {
    ball->x += ball->dx;
    ball->y += ball->dy;

    if (ball->x >= BOARD_SIZE - BALL_SIZE || ball->x <= 0) {
        ball->dx *= -1;
    }

    if (ball->y >= BOARD_SIZE - BALL_SIZE || ball->y <= 0) {
        ball->dy *= -1;
    }
}

int main() {
    int **board = NULL;
    Ball ball;

    initialize_board(&board);

    ball.x = BOARD_SIZE / 2;
    ball.y = BOARD_SIZE / 2;
    ball.dx = 1;
    ball.dy = 1;

    draw_board(board);

    while (1) {
        move_ball(&ball);
        draw_board(board);

        if (ball.x == 0 && ball.y == 0) {
            printf("You win!");
            break;
        }
    }

    return 0;
}