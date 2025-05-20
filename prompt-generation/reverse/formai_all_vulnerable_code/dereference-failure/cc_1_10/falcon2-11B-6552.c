//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// Function to generate a random bingo number
int generateRandomBingoNumber() {
    return rand() % 75 + 1;
}

// Function to check if a bingo number is in the current set of called numbers
bool isBingoNumber(int number, int* calledNumbers, int numCalledNumbers) {
    for (int i = 0; i < numCalledNumbers; i++) {
        if (calledNumbers[i] == number) {
            return true;
        }
    }
    return false;
}

// Function to check if the current set of called numbers forms a bingo
bool isBingo(int* calledNumbers, int numCalledNumbers) {
    for (int i = 1; i < 24; i++) {
        if (!isBingoNumber(i, calledNumbers, numCalledNumbers)) {
            return false;
        }
    }
    for (int i = 25; i < 50; i++) {
        if (!isBingoNumber(i, calledNumbers, numCalledNumbers)) {
            return false;
        }
    }
    for (int i = 51; i < 75; i++) {
        if (!isBingoNumber(i, calledNumbers, numCalledNumbers)) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(NULL));

    // Create an array to store the called numbers
    int* calledNumbers = (int*)malloc(75 * sizeof(int));
    memset(calledNumbers, 0, 75 * sizeof(int));

    // Generate 25 random bingo numbers
    for (int i = 0; i < 25; i++) {
        calledNumbers[i] = generateRandomBingoNumber();
    }

    // Print the called numbers
    printf("Called numbers: ");
    for (int i = 0; i < 25; i++) {
        printf("%d ", calledNumbers[i]);
    }
    printf("\n");

    // Simulate the next 24 calls
    for (int i = 0; i < 24; i++) {
        // Generate a random bingo number
        int randomNumber = generateRandomBingoNumber();

        // Check if the random number is in the current set of called numbers
        bool isBingo = isBingoNumber(randomNumber, calledNumbers, 25);

        // If it is in the set, print the number
        if (isBingo) {
            printf("%d ", randomNumber);
            calledNumbers[25 + i] = randomNumber;
        }
    }

    // Check if a bingo was formed
    if (isBingo(calledNumbers, 25)) {
        printf("Bingo!\n");
    } else {
        printf("No bingo.\n");
    }

    // Free the memory allocated for the called numbers
    free(calledNumbers);

    return 0;
}