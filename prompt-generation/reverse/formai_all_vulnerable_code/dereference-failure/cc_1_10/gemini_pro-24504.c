//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 90
int randomNumber() {
    return (rand() % 90) + 1;
}

// Function to check if a number is in an array
int checkNumber(int number, int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            return 1;
        }
    }
    return 0;
}

// Function to generate a unique array of 90 numbers
int* generateUniqueArray() {
    int* array = malloc(sizeof(int) * 90);
    for (int i = 0; i < 90; i++) {
        int number = randomNumber();
        while (checkNumber(number, array, i)) {
            number = randomNumber();
        }
        array[i] = number;
    }
    return array;
}

// Function to print an array of 90 numbers
void printArray(int array[]) {
    for (int i = 0; i < 90; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to simulate a bingo game
void bingoGame(int array[], int size) {
    if (size == 0) {
        printf("All numbers have been called.\n");
        return;
    }

    int number = randomNumber();
    while (checkNumber(number, array, size)) {
        number = randomNumber();
    }

    printf("The number called is: %d\n", number);

    // Remove the number from the array
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            array[i] = array[size - 1];
            size--;
            break;
        }
    }

    // Check if the game is over
    if (size == 0) {
        printf("Game over!\n");
    } else {
        bingoGame(array, size);
    }
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a unique array of 90 numbers
    int* array = generateUniqueArray();

    // Print the array
    printf("The numbers in the bingo game are:\n");
    printArray(array);

    // Simulate the bingo game
    bingoGame(array, 90);

    return 0;
}