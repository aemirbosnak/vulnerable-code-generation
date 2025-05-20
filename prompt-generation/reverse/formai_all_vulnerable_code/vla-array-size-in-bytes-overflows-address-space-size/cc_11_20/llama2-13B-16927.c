//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: standalone
#include <stdio.h>

#define SPACE 2
#define ASTERISK '#'

int main() {
    int i, j, k;
    int row, col;

    // Get the number of rows and columns from the user
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &row, &col);

    // Create a 2D array to store the pattern
    char pattern[row][col];

    // Initialize the pattern with spaces
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            pattern[i][j] = SPACE;
        }
    }

    // Start drawing the spiral pattern
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            // If the current position is the center, print an asterisk
            if (i == row / 2 && j == col / 2) {
                pattern[i][j] = ASTERISK;
            }

            // If the current position is not the center, print a space
            else {
                pattern[i][j] = SPACE;
            }

            // If the position is in the top-left quadrant, print an asterisk
            if (i == 0 && j == 0) {
                pattern[i][j] = ASTERISK;
            }

            // If the position is in the bottom-right quadrant, print an asterisk
            if (i == row - 1 && j == col - 1) {
                pattern[i][j] = ASTERISK;
            }
        }
    }

    // Print the pattern
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%c", pattern[i][j]);
        }
        printf("\n");
    }

    return 0;
}