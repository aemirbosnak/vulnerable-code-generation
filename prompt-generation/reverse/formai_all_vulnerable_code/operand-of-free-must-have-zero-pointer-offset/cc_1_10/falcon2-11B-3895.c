//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int randomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    int board[5][5] = {0};
    int row = 0;
    int col = 0;
    char *randomBoard[5][5] = {NULL};
    int gameOver = 0;

    // Initialize the board
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            board[row][col] = randomNumber(1, 15);
        }
    }

    // Print the initial board
    printf("\n\n\n");
    for (row = 0; row < 5; row++) {
        printf("  ");
        for (col = 0; col < 5; col++) {
            printf("%3d ", board[row][col]);
        }
        printf("\n");
    }

    // Generate random numbers for each column
    for (col = 0; col < 5; col++) {
        for (row = 0; row < 5; row++) {
            randomBoard[row][col] = " ";
        }
    }

    // Check for bingo
    while (gameOver == 0) {
        // Print the current board
        printf("\n\n\n");
        for (row = 0; row < 5; row++) {
            printf("  ");
            for (col = 0; col < 5; col++) {
                printf("%3d ", randomBoard[row][col]);
            }
            printf("\n");
        }

        // Check each column for a bingo
        for (col = 0; col < 5; col++) {
            if (randomBoard[0][col] == randomBoard[1][col] &&
                randomBoard[1][col] == randomBoard[2][col] &&
                randomBoard[2][col] == randomBoard[3][col] &&
                randomBoard[3][col] == randomBoard[4][col]) {
                printf("Bingo!\n");
                gameOver = 1;
                break;
            }
        }

        // Generate a random number for the current column
        for (row = 0; row < 5; row++) {
            int num = randomNumber(1, 15);
            while (randomBoard[row][col]!= " ") {
                num = randomNumber(1, 15);
            }
            randomBoard[row][col] = num;
        }
    }

    // Free the memory
    for (row = 0; row < 5; row++) {
        free(randomBoard[row]);
    }

    return 0;
}