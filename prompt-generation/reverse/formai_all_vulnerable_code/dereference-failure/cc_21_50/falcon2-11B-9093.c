//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int n = 1000; // number of nodes in the grid
    int p = 0.1; // probability of a node being open
    int m = 100; // number of Monte Carlo steps

    int **grid; // 2D array representing the grid
    int *open_nodes; // array of indices of open nodes

    srand(time(NULL)); // seed the random number generator

    grid = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        grid[i] = (int *)malloc(n * sizeof(int));
    }
    open_nodes = (int *)malloc(n * sizeof(int));

    // Initialize the grid with random open and closed nodes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int r = rand() % 2; // 0 = closed, 1 = open
            grid[i][j] = r;
            if (r == 1) {
                open_nodes[i]++;
            }
        }
    }

    // Perform Monte Carlo steps
    for (int i = 0; i < m; i++) {
        int u, v;

        // Pick a random open node
        int r = rand() % n;
        while (open_nodes[r] == 0) {
            r = rand() % n;
        }
        u = r;

        // Check neighbors of u
        for (int j = -1; j < 2; j++) {
            for (int k = -1; k < 2; k++) {
                int x = u + j * n + k;
                if (x >= 0 && x < n * n && grid[x][u] == 1) {
                    v = x;
                    break;
                }
            }
            if (v!= -1) {
                break;
            }
        }

        // Check if v is connected to u
        int open_neighbors = 0;
        for (int j = -1; j < 2; j++) {
            for (int k = -1; k < 2; k++) {
                int x = v + j * n + k;
                if (x >= 0 && x < n * n && grid[x][v] == 1 && grid[x][u] == 1) {
                    open_neighbors++;
                }
            }
        }

        // If v is connected to u, set u to open
        if (open_neighbors > 1 && open_neighbors <= n * p) {
            grid[u][u] = 1;
            open_nodes[u]++;
        }
    }

    // Count the number of open clusters
    int num_clusters = 0;
    for (int i = 0; i < n; i++) {
        if (open_nodes[i] > 1) {
            num_clusters++;
        }
    }

    // Print the number of open clusters
    printf("Number of open clusters: %d\n", num_clusters);

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(grid[i]);
    }
    free(grid);
    free(open_nodes);

    return 0;
}