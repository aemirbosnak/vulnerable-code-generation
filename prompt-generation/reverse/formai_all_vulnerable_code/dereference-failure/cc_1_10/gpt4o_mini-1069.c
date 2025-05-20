//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

// Function prototypes
void initialize_grid(int **grid, int size);
void open_site(int **grid, int size, int row, int col);
int percolates(int **grid, int size);
int is_open(int **grid, int size, int row, int col);
void print_grid(int **grid, int size);
int dfs(int **grid, int size, int row, int col, int *visited);

int main() {
    int size;
    printf("Enter the grid size (e.g., 10): ");
    scanf("%d", &size);

    int **grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid[i] = (int *)malloc(size * sizeof(int));
    }

    initialize_grid(grid, size);

    // Randomly open sites in the grid
    srand(time(NULL));
    for (int i = 0; i < size * size / 2; i++) {
        int row = rand() % size;
        int col = rand() % size;
        open_site(grid, size, row, col);
    }

    // Print the grid
    printf("Grid after opening sites:\n");
    print_grid(grid, size);

    // Check for percolation
    if (percolates(grid, size)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    // Free allocated memory
    for (int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

void initialize_grid(int **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid[i][j] = BLOCKED; // Start with all sites blocked
        }
    }
}

void open_site(int **grid, int size, int row, int col) {
    // Check if the coordinates are within bounds and if the site is blocked
    if (row >= 0 && row < size && col >= 0 && col < size) {
        grid[row][col] = OPEN;
    }
}

int is_open(int **grid, int size, int row, int col) {
    return (row >= 0 && row < size && col >= 0 && col < size && grid[row][col] == OPEN);
}

int dfs(int **grid, int size, int row, int col, int *visited) {
    // Base case: if we reach the bottom row
    if (row == size - 1) {
        return 1;
    }

    // Mark current cell as visited
    visited[row * size + col] = 1;

    // Define possible moves: down, left, right, up
    int moves[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    
    for (int i = 0; i < 4; i++) {
        int new_row = row + moves[i][0];
        int new_col = col + moves[i][1];

        // If the new position is open and not visited, continue DFS
        if (is_open(grid, size, new_row, new_col) && !visited[new_row * size + new_col]) {
            if (dfs(grid, size, new_row, new_col, visited)) {
                return 1; // Found a path to the bottom
            }
        }
    }

    return 0; // No path found
}

int percolates(int **grid, int size) {
    int *visited = (int *)calloc(size * size, sizeof(int));
    int result = 0;

    // Start the search from the top row
    for (int col = 0; col < size; col++) {
        if (is_open(grid, size, 0, col) && !visited[col]) {
            result |= dfs(grid, size, 0, col, visited);
        }
    }

    free(visited);
    return result;
}

void print_grid(int **grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}