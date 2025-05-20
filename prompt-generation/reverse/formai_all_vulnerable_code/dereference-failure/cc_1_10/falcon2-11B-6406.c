//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int *numbers = NULL;
int num_numbers = 0;
int max_num = 0;
int **bingo_numbers = NULL;
int num_bingo_numbers = 0;

void generate_numbers(int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < num_numbers; i++) {
        int num = rand() % (max - min + 1) + min;
        if (num > max_num) {
            max_num = num;
        }
        numbers[i] = num;
    }
}

void generate_bingo_numbers(int num_bingo_numbers, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < num_bingo_numbers; i++) {
        int num = rand() % (max - min + 1) + min;
        bingo_numbers[i][0] = num;
    }
}

int main() {
    // Set up global variables
    numbers = malloc(sizeof(int) * 25);
    if (numbers == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for numbers.\n");
        return 1;
    }
    num_numbers = 25;
    max_num = 0;

    bingo_numbers = malloc(sizeof(int*) * 5);
    if (bingo_numbers == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory for bingo numbers.\n");
        return 1;
    }
    num_bingo_numbers = 5;

    // Generate numbers
    generate_numbers(1, 75);

    // Generate bingo numbers
    generate_bingo_numbers(num_bingo_numbers, 1, 75);

    // Print the numbers
    printf("Numbers: ");
    for (int i = 0; i < num_numbers; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Print the bingo numbers
    printf("Bingo numbers: ");
    for (int i = 0; i < num_bingo_numbers; i++) {
        printf("(%d, ", bingo_numbers[i][0]);
        for (int j = 1; j < 5; j++) {
            printf("%d, ", bingo_numbers[i][j]);
        }
        printf(")\n");
    }

    // Free memory
    free(numbers);
    for (int i = 0; i < num_bingo_numbers; i++) {
        free(bingo_numbers[i]);
    }
    free(bingo_numbers);

    return 0;
}