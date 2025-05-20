//Falcon2-11B DATASET v1.0 Category: Matrix operations ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Function to initialize a matrix with zeros
void initialize_matrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
}

// Function to print a matrix
void print_matrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate the sum of all elements in a matrix
int calculate_sum(int** matrix, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    int size = 3;
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
    }

    initialize_matrix(matrix, size);

    // Print the initialized matrix
    print_matrix(matrix, size);

    // Calculate the sum of all elements in the matrix
    int sum = calculate_sum(matrix, size);

    // Print the sum
    printf("Sum: %d\n", sum);

    // Free the memory
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}