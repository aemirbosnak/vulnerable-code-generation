//GEMINI-pro DATASET v1.0 Category: Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define MAX_NUM  100

// Create a 2D array
int** create_2d_array(int rows, int cols) {
    int** array = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
    }
    return array;
}

// Free a 2D array
void free_2d_array(int** array, int rows) {
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);
}

// Print a 2D array
void print_2d_array(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

// Check if a number is in a 2D array
int is_in_2d_array(int** array, int rows, int cols, int num) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (array[i][j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array
    int** array = create_2d_array(MAX_SIZE, MAX_SIZE);

    // Fill the array with random numbers
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            array[i][j] = rand() % MAX_NUM;
        }
    }

    // Print the array
    print_2d_array(array, MAX_SIZE, MAX_SIZE);

    // Ask the user for a number to search for
    int num;
    printf("Enter a number to search for: ");
    scanf("%d", &num);

    // Check if the number is in the array
    if (is_in_2d_array(array, MAX_SIZE, MAX_SIZE, num)) {
        printf("The number is in the array\n");
    } else {
        printf("The number is not in the array\n");
    }

    // Free the array
    free_2d_array(array, MAX_SIZE);

    return 0;
}