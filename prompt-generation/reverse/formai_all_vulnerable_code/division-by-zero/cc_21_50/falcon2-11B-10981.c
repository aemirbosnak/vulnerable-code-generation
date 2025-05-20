//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int ball_x = 10;
    int ball_y = 10;
    int paddle_x = 50;
    int paddle_y = 10;
    int paddle_width = 5;
    int paddle_height = 100;
    int ball_speed = 5;
    int paddle_speed = 10;
    int score1 = 0;
    int score2 = 0;

    // Initialize ball
    srand(time(NULL));
    ball_x = rand() % (paddle_x - 10) + 10;
    ball_y = rand() % (paddle_y - 10) + 10;

    // Initialize paddle
    paddle_x = rand() % (paddle_width) + 1;
    paddle_y = rand() % (paddle_height) + 1;

    int direction = 1;

    while (1) {
        // Print score
        printf("Score: Player 1 - %d, Player 2 - %d\n", score1, score2);

        // Move ball
        if (ball_x <= 0) {
            ball_x = paddle_x + paddle_width;
            ball_y = paddle_y;
            direction *= -1;
        }
        else if (ball_x >= (paddle_x + paddle_width)) {
            ball_x = paddle_x - paddle_width;
            ball_y = paddle_y;
            direction *= -1;
        }
        else {
            ball_x += ball_speed * direction;
            ball_y += ball_speed;
        }

        // Move paddle
        if (paddle_x <= 0) {
            paddle_x = paddle_width;
        }
        else if (paddle_x >= (paddle_width + paddle_height)) {
            paddle_x = 0;
        }
        else {
            paddle_x += paddle_speed;
        }

        // Detect collision
        if (ball_x <= 0 && ball_y >= paddle_y && ball_y <= paddle_y + paddle_height) {
            ball_x = paddle_x + paddle_width;
            ball_y = paddle_y;
            direction *= -1;
            score2++;
        }
        else if (ball_x >= (paddle_x + paddle_width) && ball_y >= paddle_y && ball_y <= paddle_y + paddle_height) {
            ball_x = paddle_x - paddle_width;
            ball_y = paddle_y;
            direction *= -1;
            score1++;
        }
        else if (ball_x <= 0 && ball_y >= (paddle_y + paddle_height)) {
            ball_x = paddle_x + paddle_width;
            ball_y = paddle_y + paddle_height;
            direction *= -1;
        }
        else if (ball_x >= (paddle_x + paddle_width) && ball_y >= (paddle_y + paddle_height)) {
            ball_x = paddle_x - paddle_width;
            ball_y = paddle_y + paddle_height;
            direction *= -1;
        }

        // Move ball
        if (ball_x <= 0 && ball_y <= 0) {
            ball_x = paddle_x + paddle_width;
            ball_y = paddle_y;
            direction *= -1;
        }
        else if (ball_x >= (paddle_x + paddle_width) && ball_y <= 0) {
            ball_x = paddle_x - paddle_width;
            ball_y = paddle_y;
            direction *= -1;
        }
        else if (ball_x <= 0 && ball_y >= paddle_y + paddle_height) {
            ball_x = paddle_x + paddle_width;
            ball_y = paddle_y + paddle_height;
            direction *= -1;
        }
        else if (ball_x >= (paddle_x + paddle_width) && ball_y >= paddle_y + paddle_height) {
            ball_x = paddle_x - paddle_width;
            ball_y = paddle_y + paddle_height;
            direction *= -1;
        }

        // Move paddle
        if (paddle_x <= 0) {
            paddle_x = paddle_width;
        }
        else if (paddle_x >= (paddle_width + paddle_height)) {
            paddle_x = 0;
        }
        else {
            paddle_x += paddle_speed;
        }

        // Sleep
        usleep(10000);
    }

    return 0;
}