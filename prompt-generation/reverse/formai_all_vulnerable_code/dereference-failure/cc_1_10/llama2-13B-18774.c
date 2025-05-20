//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print a single pattern
void print_pattern(char *pattern) {
    int i, j;
    for (i = 0; i < strlen(pattern); i++) {
        for (j = 0; j < strlen(pattern); j++) {
            if (i == j) {
                printf("%c", pattern[i]);
            } else {
                printf("_%c", pattern[i]);
            }
        }
        printf("\n");
    }
}

// Function to print a matrix of patterns
void print_matrix(char **matrix, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            print_pattern(matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char **matrix;
    int rows, cols;

    // Ask user for input
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &rows, &cols);

    // Allocate memory for the matrix
    matrix = (char **) malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char *) malloc(cols * sizeof(char));
    }

    // Ask user for patterns
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter pattern %d, %d: ", i + 1, j + 1);
            scanf("%s", matrix[i][j]);
        }
    }

    // Print the matrix of patterns
    print_matrix(matrix, rows, cols);

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}