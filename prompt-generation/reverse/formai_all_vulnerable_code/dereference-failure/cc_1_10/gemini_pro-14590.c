//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Initialize the matrix to simulate the grid with water
void init_grid(uint8_t *grid, uint32_t *counts, uint32_t size) {
    for(uint32_t row = 0; row < size; ++row) {
        for(uint32_t col = 0; col < size; ++col) {
            grid[row * size + col] = 0;
        }
    }
    memset(counts, 0, size * sizeof(uint32_t));
}

// Open sites by randomly picking coordinates
void open_sites(uint8_t *grid, uint32_t *counts, uint32_t perc, uint32_t size) {
    uint32_t row, col;
    for(uint32_t i = 0; i < (perc * size * size) / 100; ++i) {
        do {
            row = rand() % size;
            col = rand() % size;
        } while(grid[row * size + col] != 0);
        grid[row * size + col] = 1;
        counts[row]++;
    }
}

// Check if the site is open
bool is_open(uint8_t *grid, uint32_t row, uint32_t col, uint32_t size) {
    return grid[row * size + col] == 1;
}

// Check if the site is part of the cluster
bool is_in_cluster(uint8_t *grid, uint32_t *cluster, uint32_t row, uint32_t col, uint32_t size) {
    return cluster[row * size + col] != 0;
}

// Find the maximum cluster size
uint32_t find_max_cluster(uint8_t *grid, uint32_t *cluster, uint32_t size) {
    uint32_t max_cluster = 0;
    for(uint32_t row = 0; row < size; ++row) {
        for(uint32_t col = 0; col < size; ++col) {
            if(is_in_cluster(grid, cluster, row, col, size)) {
                max_cluster = fmax(max_cluster, cluster[row * size + col]);
            }
        }
    }
    return max_cluster;
}

// Percolate the grid and mark the clusters
void percolate(uint8_t *grid, uint32_t *cluster, uint32_t size) {
    uint32_t cluster_id = 1;
    for(uint32_t row = 0; row < size; ++row) {
        for(uint32_t col = 0; col < size; ++col) {
            if(!is_open(grid, row, col, size) || is_in_cluster(grid, cluster, row, col, size)) {
                continue;
            }
            cluster[row * size + col] = cluster_id;
            uint8_t stack[size * size];
            uint8_t top = 0;
            stack[top++] = row * size + col;
            while(top > 0) {
                uint32_t index = stack[--top];
                uint32_t r = index / size;
                uint32_t c = index % size;
                if(r > 0 && !is_in_cluster(grid, cluster, r - 1, c, size) && is_open(grid, r - 1, c, size)) {
                    stack[top++] = (r - 1) * size + c;
                    cluster[(r - 1) * size + c] = cluster_id;
                }
                if(r < size - 1 && !is_in_cluster(grid, cluster, r + 1, c, size) && is_open(grid, r + 1, c, size)) {
                    stack[top++] = (r + 1) * size + c;
                    cluster[(r + 1) * size + c] = cluster_id;
                }
                if(c > 0 && !is_in_cluster(grid, cluster, r, c - 1, size) && is_open(grid, r, c - 1, size)) {
                    stack[top++] = r * size + c - 1;
                    cluster[r * size + c - 1] = cluster_id;
                }
                if(c < size - 1 && !is_in_cluster(grid, cluster, r, c + 1, size) && is_open(grid, r, c + 1, size)) {
                    stack[top++] = r * size + c + 1;
                    cluster[r * size + c + 1] = cluster_id;
                }
            }
            cluster_id++;
        }
    }
}

// Print the grid
void print_grid(uint8_t *grid, uint32_t size) {
    for(uint32_t row = 0; row < size; ++row) {
        for(uint32_t col = 0; col < size; ++col) {
            printf("%d ", grid[row * size + col]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    uint32_t size = 10;
    uint32_t perc = 50;
    uint8_t *grid = malloc(size * size * sizeof(uint8_t));
    uint32_t *counts = malloc(size * sizeof(uint32_t));
    uint32_t *cluster = malloc(size * size * sizeof(uint32_t));
    init_grid(grid, counts, size);
    open_sites(grid, counts, perc, size);
    percolate(grid, cluster, size);
    uint32_t max_cluster = find_max_cluster(grid, cluster, size);
    printf("Grid:\n");
    print_grid(grid, size);
    printf("\nCounts:\n");
    for(uint32_t row = 0; row < size; ++row) {
        printf("%d ", counts[row]);
    }
    printf("\n");
    printf("Max cluster: %d\n", max_cluster);
    free(grid);
    free(counts);
    free(cluster);
    return 0;
}