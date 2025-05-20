//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <omp.h>

#define N 10 // Size of grid

int find_root(int x, int *id) {
    while (x != id[x]) {
        id[x] = id[id[x]]; // Path compression
        x = id[x];
    }

    return x;
}

int unite(int x, int y, int *id) {
    int root_x = find_root(x, id);
    int root_y = find_root(y, id);

    if (root_x != root_y) {
        id[root_x] = root_y;
        return 1;
    }

    return 0;
}

bool percolates(int *id) {
    int top_root = find_root(0, id);
    int bottom_root = find_root(N*N+1, id);

    if (top_root == bottom_root) {
        return true;
    }

    return false;
}

int main() {
    srand(time(0));
    int *id = malloc(sizeof(int) * (N*N+2));

    // Initializing grid with no connection
    for (int i = 0; i < N*N+2; i++) {
        id[i] = i;
    }

    // Connecting top row to virtual top cell
    #pragma omp parallel for
    for (int i = 1; i <= N; i++) {
        unite(0, i, id);
    }

    // Connecting bottom row to virtual bottom cell
    #pragma omp parallel for
    for (int i = N*N-N+1; i <= N*N; i++) {
        unite(i, N*N+1, id);
    }

    // Running simulation
    int open_sites = 0;
    while (!percolates(id)) {
        int random_cell = rand() % (N*N) + 1;

        // Calculating row and column number of the random cell
        int row = (random_cell - 1) / N + 1;
        int col = (random_cell - 1) % N + 1;

        // Opening the site
        if (id[random_cell] != 0) {
            #pragma omp critical
            {
                id[random_cell] = 0;
                open_sites++;
            }
        }

        // Connecting to adjacent open sites
        if (row > 1 && id[random_cell-N] == 0) { // Connecting to top cell
            unite(random_cell, random_cell-N, id);
        }
        if (row < N && id[random_cell+N] == 0) { // Connecting to bottom cell
            unite(random_cell, random_cell+N, id);
        }
        if (col > 1 && id[random_cell-1] == 0) { // Connecting to left cell
            unite(random_cell, random_cell-1, id);
        }
        if (col < N && id[random_cell+1] == 0) { // Connecting to right cell
            unite(random_cell, random_cell+1, id);
        }
    }

    float p = (float) open_sites / (N*N);
    printf("Percolation threshold: %f\n", p);

    free(id);
    return 0;
}