//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // size of the grid
#define PROBABILITY 0.5 // probability of a cell being open

// Structure to hold percolation grid info
typedef struct grid {
    int **data; // 2D array of integers
    int size; // size of the 2D array
} grid;

// Function to create a new grid
grid *newGrid(int size) {
    // Allocate memory for the grid struct
    grid *g = (grid *)malloc(sizeof(grid));

    // Allocate memory for the 2D array
    g->data = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        g->data[i] = (int *)malloc(size * sizeof(int));
    }

    // Set the size of the array
    g->size = size;

    // Initialize all cells to be closed
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            g->data[i][j] = 0;
        }
    }

    return g;
}

// Function to print the grid
void printGrid(grid *g) {
    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < g->size; j++) {
            printf("%d ", g->data[i][j]);
        }
        printf("\n");
    }
}

// Function to randomly generate a percolation grid based on input probability
void generateGrid(grid *g, double probability) {
    srand(time(NULL)); // Seed the random number generator

    // Loop through each cell in the grid
    for (int i = 0; i < g->size; i++) {
        for (int j = 0; j < g->size; j++) {
            double random = (double)rand() / (double)RAND_MAX; // Generate a random number between 0 and 1
            if (random < probability) { // If the random number is less than the input probability, open the cell
                g->data[i][j] = 1;
            }
            else { // Otherwise, keep the cell closed
                g->data[i][j] = 0;
            }
        }
    }
}

// Function to determine if a grid percolates
int percolates(grid *g) {
    // Initialize arrays to hold visited cells and cells connected to the top and bottom
    int *visited = (int *)malloc(g->size * sizeof(int));
    int *topConnected = (int *)malloc(g->size * sizeof(int));
    int *bottomConnected = (int *)malloc(g->size * sizeof(int));

    // Initialize all arrays to be empty
    for (int i = 0; i < g->size; i++) {
        visited[i] = 0;
        topConnected[i] = 0;
        bottomConnected[i] = 0;
    }

    // Check if each cell in the top row is connected to the top
    for (int i = 0; i < g->size; i++) {
        if (g->data[0][i] == 1) { // If the cell is open
            topConnected[i] = 1; // Mark it as connected to the top
            visited[i] = 1; // Mark it as visited
            if (i - 1 >= 0 && g->data[0][i - 1] == 1) { // Check the cell to the left
                topConnected[i - 1] = 1;
                visited[i - 1] = 1;
            }
            if (i + 1 < g->size && g->data[0][i + 1] == 1) { // Check the cell to the right
                topConnected[i + 1] = 1;
                visited[i + 1] = 1;
            }
        }
    }

    // Loop through all rows except the top row
    for (int i = 1; i < g->size; i++) {
        // Loop through each cell in the row
        for (int j = 0; j < g->size; j++) {
            if (g->data[i][j] == 1) { // If the cell is open
                if (topConnected[j] == 1) { // If it is connected to the top, mark it as such
                    topConnected[j] = 1;
                    visited[j] = 1;
                }
                if (j - 1 >= 0 && topConnected[j - 1] == 1) { // If the cell to the left is connected to the top, mark this cell as connected to the top
                    topConnected[j] = 1;
                    visited[j] = 1;
                }
                if (j + 1 < g->size && topConnected[j + 1] == 1) { // If the cell to the right is connected to the top, mark this cell as connected to the top
                    topConnected[j] = 1;
                    visited[j] = 1;
                }
                if (bottomConnected[j] == 1) { // If it is connected to the bottom, mark it as such
                    bottomConnected[j] = 1;
                    visited[j] = 1;
                }
                if (j - 1 >= 0 && bottomConnected[j - 1] == 1) { // If the cell to the left is connected to the bottom, mark this cell as connected to the bottom
                    bottomConnected[j] = 1;
                    visited[j] = 1;
                }
                if (j + 1 < g->size && bottomConnected[j + 1] == 1) { // If the cell to the right is connected to the bottom, mark this cell as connected to the bottom
                    bottomConnected[j] = 1;
                    visited[j] = 1;
                }
            }
        }
    }

    // Check if any cells are connected to both the top and bottom
    for (int i = 0; i < g->size; i++) {
        if (topConnected[i] == 1 && bottomConnected[i] == 1) { // If a cell is connected to both the top and bottom, the grid percolates
            return 1;
        }
        else { // Otherwise, continue to the next cell
            continue;
        }
    }

    // If no cells are connected to both the top and bottom, the grid does not percolate
    return 0;
}

// Main function
int main() {
    // Create a new percolation grid
    grid *g = newGrid(SIZE);

    // Generate a percolation grid with the given probability
    generateGrid(g, PROBABILITY);

    // Print the grid
    printf("Percolation Grid:\n");
    printGrid(g);

    // Determine if the grid percolates
    if (percolates(g) == 1) {
        printf("The grid percolates!\n");
    }
    else {
        printf("The grid does not percolate.\n");
    }

    return 0;
}