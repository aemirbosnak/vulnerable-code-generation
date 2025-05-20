//Falcon2-11B DATASET v1.0 Category: Pong Game with AI Opponent ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int score1 = 0, score2 = 0;
    int x1 = 50, x2 = 50;
    int y1 = 50, y2 = 50;
    int dx = 10, dy = 10;
    int x1_change, x2_change;

    // Initialize ball
    int ball_x = (rand() % (x2 - x1)) + x1;
    int ball_y = (rand() % (y2 - y1)) + y1;

    // Game loop
    while (1) {
        // Move ball
        ball_x += dx;
        ball_y += dy;

        // Move paddles
        if (ball_y > y1) {
            y1 += dy;
        }
        if (ball_y < y2) {
            y2 -= dy;
        }
        if (ball_x > x1) {
            x1 += dx;
        }
        if (ball_x < x2) {
            x2 -= dx;
        }

        // Check collision
        if (ball_x > x2 || ball_x < x1) {
            dx = -dx;
        }
        if (ball_y > y2 || ball_y < y1) {
            dy = -dy;
        }

        // Update scores
        if (ball_x > x2 && ball_y > y2) {
            score2++;
        } else if (ball_x < x1 && ball_y > y1) {
            score1++;
        }

        // AI opponent
        if (score1 == 10) {
            x1_change = 0;
        } else if (score2 == 10) {
            x2_change = 0;
        } else if (ball_x > x1 && ball_x < x2) {
            if (abs(ball_y - y1) > abs(ball_y - y2)) {
                x1_change = 1;
            } else {
                x2_change = 1;
            }
        } else {
            x1_change = 0;
            x2_change = 0;
        }

        // Move paddles based on AI opponent
        x1 += x1_change;
        x2 += x2_change;

        // Print scores
        printf("Score: %d - %d\n", score1, score2);

        // Draw paddles and ball
        printf("X1: %d Y1: %d\n", x1, y1);
        printf("X2: %d Y2: %d\n", x2, y2);
        printf("Ball: X: %d Y: %d\n", ball_x, ball_y);
    }

    return 0;
}