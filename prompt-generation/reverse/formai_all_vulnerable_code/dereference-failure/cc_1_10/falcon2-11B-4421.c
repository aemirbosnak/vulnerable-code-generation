//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Function to generate a maze
void generateMaze(int row, int col, int maze[row][col]) {
    // Check if row is less than col
    if (row < col) {
        printf("Error: Number of columns cannot be greater than number of rows.\n");
        return;
    }

    // Check if row is equal to 1
    if (row == 1) {
        maze[row][col] = 1;
        return;
    }

    // Recursively generate maze for row-1 and col-1
    generateMaze(row-1, col-1, maze);

    // Set value of maze[row][col] to 1
    maze[row][col] = 1;
}

int main() {
    int row, col;

    // Prompt user to enter number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("Enter the number of columns: ");
    scanf("%d", &col);

    // Generate maze
    int maze[row][col];
    generateMaze(row, col, maze);

    // Print maze
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (maze[i][j] == 1) {
                printf(" *");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }

    return 0;
}