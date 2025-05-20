//Falcon2-11B DATASET v1.0 Category: Breakout Game Clone ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <level>\n", argv[0]);
        return 1;
    }

    int level = atoi(argv[1]);

    srand(time(NULL));

    int screenWidth = 400;
    int screenHeight = 300;
    int ballRadius = 5;
    int paddleWidth = 10;
    int paddleHeight = 50;
    int ballX = screenWidth / 2 - ballRadius;
    int ballY = screenHeight / 2 - ballRadius;
    int paddleX = screenWidth / 2 - paddleWidth / 2;
    int paddleY = screenHeight - paddleHeight - 5;
    int ballSpeedX = 2;
    int ballSpeedY = 2;
    int levelSpeed = (level * 2) + 5;

    int score = 0;

    while (1) {
        int x1 = ballX;
        int y1 = ballY;

        int x2 = paddleX;
        int y2 = paddleY;

        int x3 = screenWidth - 1;
        int y3 = screenHeight - 1;

        int x4 = 0;
        int y4 = 0;

        printf("Score: %d\n", score);
        printf("Level: %d\n", level);

        for (int i = 0; i < screenHeight; i++) {
            for (int j = 0; j < screenWidth; j++) {
                if (i == ballY && j == ballX) {
                    printf("*");
                } else if (i == y2 && j == x2) {
                    printf("X");
                } else if (i == y3 && j == x3) {
                    printf("O");
                } else if (i == y4 && j == x4) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        if (ballY > screenHeight || ballX < 0 || ballX > screenWidth || ballY < 0) {
            printf("You Lose!\n");
            break;
        } else if (ballY < 0 || ballY > screenHeight) {
            ballSpeedY = -ballSpeedY;
        } else if (ballX < 0 || ballX > screenWidth) {
            ballSpeedX = -ballSpeedX;
        } else if (ballY == y2 && ballX == x2) {
            score++;
            ballSpeedX = -ballSpeedX;
        } else if (ballY == y3 && ballX == x3) {
            score--;
            ballSpeedX = -ballSpeedX;
        } else if (ballY == y4 && ballX == x4) {
            level++;
            levelSpeed += 2;
            srand(time(NULL));
            ballX = screenWidth / 2 - ballRadius;
            ballY = screenHeight / 2 - ballRadius;
            ballSpeedX = 2;
            ballSpeedY = 2;
            if (level == 9) {
                level = 0;
            }
            printf("Level: %d\n", level);
        }

        ballX += ballSpeedX;
        ballY += ballSpeedY;

        sleep(levelSpeed);
    }

    return 0;
}