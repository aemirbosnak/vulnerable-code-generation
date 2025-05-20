//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 20
#define SITE(i, j) (i) * N + (j)

bool *grid;
bool *visited;

int find_root(int p, int *parents) {
    while (p != parents[p]) {
        parents[p] = parents[parents[p]];
        p = parents[p];
    }
    return p;
}

void union_sites(int p, int q, int *parents, int *sizes) {
    int root_p = find_root(p, parents);
    int root_q = find_root(q, parents);
    if (root_p == root_q) {
        return;
    }
    if (sizes[root_p] < sizes[root_q]) {
        parents[root_p] = root_q;
        sizes[root_q] += sizes[root_p];
    } else {
        parents[root_q] = root_p;
        sizes[root_p] += sizes[root_q];
    }
}

bool is_percolated(int *parents, int *sizes) {
    int top = N * N;
    int root_top = find_root(top, parents);
    for (int j = 0; j < N; j++) {
        int root_j = find_root(j, parents);
        if (sizes[root_j] != 0 && root_j == root_top) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(NULL));
    int num_sites = N * N + 1;
    int *parents = malloc(num_sites * sizeof(int));
    int *sizes = calloc(num_sites, sizeof(int));
    size_t grid_size = num_sites * sizeof(bool);
    grid = malloc(grid_size);
    visited = calloc(num_sites, sizeof(bool));
    for (int i = 0; i < num_sites; i++) {
        parents[i] = i;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[SITE(i, j)] = false;
        }
    }
    int p;
    while (!is_percolated(parents, sizes)) {
        p = rand() % num_sites;
        if (p == N * N) {
            continue;
        }
        int i = p / N;
        int j = p % N;
        grid[SITE(i, j)] = true;
        visited[SITE(i, j)] = true;
        if (i > 0 && visited[SITE(i - 1, j)]) {
            union_sites(SITE(i, j), SITE(i - 1, j), parents, sizes);
        }
        if (i < N - 1 && visited[SITE(i + 1, j)]) {
            union_sites(SITE(i, j), SITE(i + 1, j), parents, sizes);
        }
        if (j > 0 && visited[SITE(i, j - 1)]) {
            union_sites(SITE(i, j), SITE(i, j - 1), parents, sizes);
        }
        if (j < N - 1 && visited[SITE(i, j + 1)]) {
            union_sites(SITE(i, j), SITE(i, j + 1), parents, sizes);
        }
    }
    printf("Percolation threshold: %f\n", (float) p / (N * N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[SITE(i, j)]) {
                printf("O ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
    free(parents);
    free(sizes);
    free(grid);
    free(visited);
    return 0;
}