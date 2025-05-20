//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Function to generate a random number between min and max
int roll_dice(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to check if a given number is prime
bool is_prime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int divisor = 2; divisor * divisor <= number; divisor++) {
        if (number % divisor == 0) {
            return false;
        }
    }

    return true;
}

// Function to print a given 2D array in a more enthusiastic way
void print_magic_square(int **square) {
    printf("\n\n***** WELCOME TO THE MAGIC SQUARE *****\n\n");
    printf("***************************************\n");
    for (int row = 0; row < 3; row++) {
        printf("\nRow %d: ", row + 1);
        for (int col = 0; col < 3; col++) {
            int number = square[row][col];
            printf(" %3d", number);
            if (is_prime(number)) {
                printf(" (PRIME!)");
            }
        }
        printf("\n");
    }
    printf("***************************************\n");
}

int main() {
    srand(time(NULL));

    // Initialize the magic square with zeros
    int **magic_square = malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++) {
        magic_square[i] = calloc(3, sizeof(int));
    }

    // Calculate the position of each number using arithmetic operations
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int position = (i + j) % 3;
            magic_square[i][j] = roll_dice(1, 10) + (position * 10);
        }
    }

    // Print the magic square in an enthusiastic way
    print_magic_square(magic_square);

    // Free allocated memory
    for (int i = 0; i < 3; i++) {
        free(magic_square[i]);
    }
    free(magic_square);

    return 0;
}