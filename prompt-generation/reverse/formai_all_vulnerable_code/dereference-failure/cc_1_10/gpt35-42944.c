//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
  
// Define the size of the grid
#define SIZE 10

// Define the probability of a site being open
#define PROBABILITY 0.5

// Define the maximum number of iterations
#define MAX_ITERATIONS 10000

// Define a union-find structure
typedef struct union_find { 
    int *parent; 
    int *rank; 
} union_find; 

// Initialize the percolation grid
void initialize_grid(int grid[SIZE][SIZE], double probability) {
    for (int i = 0; i < SIZE; i++) { 
        for (int j = 0; j < SIZE; j++) { 
            double random_num = (double) rand() / (double) RAND_MAX;
            grid[i][j] = (random_num <= probability) ? 1 : 0;
        } 
    }
}

// Find the root of a node
int find(union_find *uf, int i) { 
    if (uf->parent[i] != i) 
        uf->parent[i] = find(uf, uf->parent[i]); 
    return uf->parent[i]; 
} 

// Merge two nodes together
void merge(union_find *uf, int x, int y) { 
    int root_x = find(uf, x); 
    int root_y = find(uf, y); 
  
    if (uf->rank[root_x] < uf->rank[root_y]) 
        uf->parent[root_x] = root_y; 
    else if (uf->rank[root_x] > uf->rank[root_y]) 
        uf->parent[root_y] = root_x;  
    else { 
        uf->parent[root_y] = root_x; 
        uf->rank[root_x]++; 
    } 
} 
  
// Check if the percolation has occurred
int percolation(union_find *uf, int grid[SIZE][SIZE]) { 
    for (int i = 0; i <= SIZE-1; i++) { 
        for (int j = 0; j <= SIZE-1; j++) { 
            if (grid[i][j] == 1) { 
                int node = i * SIZE + j;
                if (i == 0) 
                    merge(uf, node, SIZE*SIZE); 
                if (i == SIZE - 1) 
                    merge(uf, node, SIZE*SIZE+1); 
                if (i > 0 && grid[i-1][j] == 1) 
                    merge(uf, node, (i - 1) * SIZE + j); 
                if (i < SIZE - 1 && grid[i+1][j] == 1) 
                    merge(uf, node, (i + 1) * SIZE + j); 
                if (j > 0 && grid[i][j-1] == 1) 
                    merge(uf, node, i * SIZE + j - 1); 
                if (j < SIZE - 1 && grid[i][j+1] == 1) 
                    merge(uf, node, i * SIZE + j + 1); 
            } 
        } 
    } 
  
    return find(uf, SIZE*SIZE) == find(uf, SIZE*SIZE+1); 
} 
  
int main() { 
    // Define the percolation grid
    int grid[SIZE][SIZE];
  
    // Seed the random number generator
    srand(time(NULL)); 

    // Initialize the union-find data structure
    union_find *uf = (union_find*) malloc(sizeof(union_find)); 
    uf->parent = (int*) malloc(sizeof(int) * (SIZE*SIZE+2)); 
    uf->rank = (int*) malloc(sizeof(int) * (SIZE*SIZE+2)); 

    for (int i = 0; i <= SIZE*SIZE+1; i++) { 
        uf->parent[i] = i; 
        uf->rank[i] = 0; 
    } 

    // Initialize the percolation grid
    initialize_grid(grid, PROBABILITY);

    // Iterate until the grid percolates or we hit a maximum number of iterations
    int iterations = 0;
    while (!percolation(uf, grid) && iterations < MAX_ITERATIONS) {
        initialize_grid(grid, PROBABILITY);
        iterations++;
    }

    // Output the results
    if (percolation(uf, grid)) {
        printf("Percolation occurred after %d iterations\n", iterations);
    } else {
        printf("Percolation did not occur after %d iterations\n", iterations);
    }

    // Free the memory allocated for the union-find structure
    free(uf->parent); 
    free(uf->rank); 
    free(uf);

    return 0; 
}