//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// This function generates a random number within the specified range
int randomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void drawBingoBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));

    int board[ROWS][COLS];

    // Populate the bingo board with random numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = randomNumber(1, 5);
        }
    }

    // Print the bingo board
    printf("Bingo Board:\n");
    drawBingoBoard(board);

    // Get the user's bingo numbers
    printf("Enter your bingo numbers (separated by commas): ");
    char numbers[100];
    fgets(numbers, sizeof(numbers), stdin);

    // Convert the input string to an array of integers
    char* tokens[100];
    char* token = strtok(numbers, ",");
    int* bingoNumbers = (int*)malloc(sizeof(int) * 100);
    int count = 0;
    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, ",");
    }
    bingoNumbers[count - 1] = 0;  // Always end with 0 to represent "bingo"

    // Check if the user has bingo
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == bingoNumbers[i * COLS + j]) {
                printf("%d ", bingoNumbers[i * COLS + j]);
                bingoNumbers[i * COLS + j] = 0;  // Mark the number as used
                if (bingoNumbers[i * COLS + j] == 0) {
                    printf("BINGO!\n");
                    break;
                }
            }
        }
    }

    free(bingoNumbers);

    return 0;
}