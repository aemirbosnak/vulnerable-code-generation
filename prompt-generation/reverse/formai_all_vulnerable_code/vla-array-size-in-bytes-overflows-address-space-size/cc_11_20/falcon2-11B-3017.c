//Falcon2-11B DATASET v1.0 Category: Breakout Game Clone ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int width, height;
    printf("Enter the width of the game window: ");
    scanf("%d", &width);
    printf("Enter the height of the game window: ");
    scanf("%d", &height);

    // Create a 2D array to represent the game board
    int gameBoard[height][width];

    // Fill the game board with bricks
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            gameBoard[i][j] = 1;
        }
    }

    // Initialize the ball's position and velocity
    int ballX = width / 2;
    int ballY = height / 2;
    int ballXVel = 2;
    int ballYVel = -1;

    // Initialize the paddle's position
    int paddleX = width - 10;
    int paddleY = height / 2;

    // Game loop
    while (true) {
        // Update the ball's position
        ballX += ballXVel;
        ballY += ballYVel;

        // Check for collision with the top or bottom walls
        if (ballY < 0 || ballY >= height) {
            ballYVel = -ballYVel;
        }

        // Check for collision with the left or right walls
        if (ballX < 0 || ballX >= width) {
            ballXVel = -ballXVel;
        }

        // Check for collision with the paddle
        if (ballY <= paddleY && abs(ballX - paddleX) <= 5) {
            ballYVel = -ballYVel;
        }

        // Check for collision with the bricks
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (gameBoard[i][j] == 1) {
                    if (ballX == j && ballY == i) {
                        gameBoard[i][j] = 0;
                        ballXVel = -ballXVel;
                        ballYVel = -ballYVel;
                    }
                }
            }
        }

        // Draw the game board
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (gameBoard[i][j] == 1) {
                    printf("1 ");
                } else {
                    printf("0 ");
                }
            }
            printf("\n");
        }

        // Draw the ball and paddle
        printf("Ball: (%d, %d)\n", ballX, ballY);
        printf("Paddle: (%d, %d)\n", paddleX, paddleY);

        // Update the display
        fflush(stdout);

        // Check for keyboard input
        char key;
        scanf(" %c", &key);
        if (key == 'q') {
            break;
        }
    }

    return 0;
}