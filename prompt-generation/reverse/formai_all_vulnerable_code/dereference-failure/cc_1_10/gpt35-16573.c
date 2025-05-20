//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find(int *parent, int i) {
    while (i != parent[i]) {
        i = parent[i];
    }
    return i;
}

void set_union(int *parent, int *size, int i, int j) {
    int root_i = find(parent, i);
    int root_j = find(parent, j);
    if (root_i == root_j) {
        return;
    }
    if (size[root_i] < size[root_j]) {
        parent[root_i] = parent[root_j];
        size[root_j] += size[root_i];
    } else {
        parent[root_j] = parent[root_i];
        size[root_i] += size[root_j];
    }
}

int main() {
    srand(time(NULL));
    int n = 10; // size of grid
    int num_sites = n * n;
    int num_open = 0;
    int *open = calloc(num_sites, sizeof(int));
    int *parent = calloc(num_sites, sizeof(int));
    int *size = calloc(num_sites, sizeof(int));
    for (int i = 0; i < num_sites; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    while (find(parent, 0) != find(parent, num_sites - 1)) {
        int site = rand() % num_sites;
        if (!open[site]) {
            open[site] = 1;
            num_open++;
            int row = site / n;
            int col = site % n;
            if (row > 0 && open[site - n]) {
                set_union(parent, size, site, site - n);
            }
            if (row < n - 1 && open[site + n]) {
                set_union(parent, size, site, site + n);
            }
            if (col > 0 && open[site - 1]) {
                set_union(parent, size, site, site - 1);
            }
            if (col < n - 1 && open[site + 1]) {
                set_union(parent, size, site, site + 1);
            }
        }
    }
    if (num_sites > 300) {
        printf("Grid too large to print\n");
    } else {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                int site = row * n + col;
                if (open[site]) {
                    printf(" ");
                } else {
                    printf("#");
                }
            }
            printf("\n");
        }
    }
    printf("%d sites were opened\n", num_open);
    free(open);
    free(parent);
    free(size);
    return 0;
}