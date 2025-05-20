//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize a 2D array
void init2DArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 0;
        }
    }
}

// Function to percolate a 2D array
void percolate(int** arr, int rows, int cols) {
    int visited[rows][cols];

    // Mark all cells as unvisited
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = 0;
        }
    }

    // Mark all visited cells
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 1) {
                visited[i][j] = 1;
            }
        }
    }

    // Check for percolation
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (visited[i][j] == 0) {
                return;
            }
        }
    }

    // Percolate
    int r, c;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (visited[i][j] == 0) {
                r = i;
                c = j;
                break;
            }
        }
    }

    if (r == -1 || c == -1) {
        printf("Percolation not found.\n");
    } else {
        printf("Percolation found at (%d, %d).\n", r, c);
    }
}

int main() {
    srand(time(NULL));
    int rows = 10;
    int cols = 10;
    int** arr = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rand() % 2;
        }
    }

    init2DArray(arr, rows, cols);

    percolate(arr, rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);

    return 0;
}