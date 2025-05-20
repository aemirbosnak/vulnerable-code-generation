//MISTRAL-7B DATASET v1.0 Category: Physics simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define BOX_WIDTH 50
#define BOX_HEIGHT 30
#define BALL_RADIUS 5
#define TIME_STEP 0.01

typedef struct {
    double x, y, vx, vy;
} Ball;

void update_ball(Ball *ball) {
    double dx, dy;

    dx = ball->vx * TIME_STEP;
    dy = ball->vy * TIME_STEP;

    ball->x += dx;
    ball->y += dy;

    // Check for wall collisions
    if (ball->x - BALL_RADIUS < 0) {
        ball->vx = -ball->vx;
        ball->x += 2 * BALL_RADIUS;
    }

    if (ball->x + BALL_RADIUS > BOX_WIDTH) {
        ball->vx = -ball->vx;
        ball->x -= 2 * BALL_RADIUS;
    }

    if (ball->y - BALL_RADIUS < 0) {
        ball->vy = -ball->vy;
        ball->y += 2 * BALL_RADIUS;
    }

    if (ball->y + BALL_RADIUS > BOX_HEIGHT) {
        ball->vy = -ball->vy;
        ball->y -= 2 * BALL_RADIUS;
    }

    // Update velocity based on acceleration due to gravity
    ball->vy += 0.1;
}

int main() {
    srand(time(NULL));
    Ball *ball;

    ball = (Ball *) malloc(sizeof(Ball));
    ball->x = BOX_WIDTH / 2;
    ball->y = BOX_HEIGHT / 2;
    ball->vx = rand() % 10 + 5;
    ball->vy = 0;

    for (int i = 0; i < 1000; i++) {
        update_ball(ball);
        printf("Ball position: (%lf, %lf)\n", ball->x, ball->y);
        fflush(stdout);
        usleep(1000 * TIME_STEP);
    }

    free(ball);
    return 0;
}