//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void print_matrix(char **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char input_string[MAX_LINE_LENGTH];
    char **matrix = NULL;
    int rows = 0;
    int cols = 0;

    printf("Enter a string: ");
    fgets(input_string, MAX_LINE_LENGTH, stdin);

    // Count the number of rows and columns in the input string
    for (int i = 0; i < strlen(input_string); i++) {
        if (input_string[i] == '\n') {
            rows++;
        }
        if (i == 0 || input_string[i - 1] == '\n') {
            cols = i + 1;
        }
    }

    // Allocate memory for the matrix
    matrix = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (char *)malloc(cols * sizeof(char));
    }

    // Fill the matrix with the input string
    int current_row = 0;
    int current_col = 0;
    for (int i = 0; i < strlen(input_string); i++) {
        if (input_string[i] == '\n') {
            current_row++;
            current_col = 0;
        } else {
            matrix[current_row][current_col] = input_string[i];
            current_col++;
        }
    }

    // Print the matrix
    print_matrix(matrix, rows, cols);

    // Free the memory allocated for the matrix
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}