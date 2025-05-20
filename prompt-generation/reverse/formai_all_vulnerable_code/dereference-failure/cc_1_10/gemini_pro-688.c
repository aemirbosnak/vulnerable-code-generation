//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of rows and columns
#define MAX_ROWS 10
#define MAX_COLS 10

// Define the character used to print the pattern
#define PATTERN_CHAR '*'

// Function to print the pattern
void print_pattern(int rows, int cols) {
    // Validate the input
    if (rows < 1 || rows > MAX_ROWS || cols < 1 || cols > MAX_COLS) {
        printf("Invalid input: rows and columns must be between 1 and %d\n", MAX_ROWS);
        return;
    }

    // Allocate memory for the pattern
    char **pattern = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        pattern[i] = (char *)malloc(cols * sizeof(char));
    }

    // Initialize the pattern with spaces
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pattern[i][j] = ' ';
        }
    }

    // Print the pattern
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Print the character at the current position
            printf("%c", pattern[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the pattern
    for (int i = 0; i < rows; i++) {
        free(pattern[i]);
    }
    free(pattern);
}

// Main function
int main() {
    // Get the number of rows and columns from the user
    int rows, cols;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Print the pattern
    print_pattern(rows, cols);

    return 0;
}