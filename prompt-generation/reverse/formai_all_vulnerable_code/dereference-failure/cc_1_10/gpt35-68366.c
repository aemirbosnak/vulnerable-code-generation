//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define size of grid and probability of each site being open
#define N 10
#define P 0.5

// define a struct for the percolation simulator
typedef struct {
    int parent; // parent site in the system of clusters
    int size; // size of the cluster
    int open; // whether the site is open or not (0 or 1)
} Site;

// define a struct for the system of clusters
typedef struct {
    Site **sites; // 2D array of sites
    int num_clusters; // number of clusters in the system
    int *cluster_sizes; // array of sizes of all clusters
} Cluster_System;

// function to create a new site
Site *new_site(int parent, int size, int open) {
    Site *s = malloc(sizeof(Site));
    s->parent = parent;
    s->size = size;
    s->open = open;
    return s;
}

// function to create a new cluster system
Cluster_System *new_cluster_system() {
    Cluster_System *c = malloc(sizeof(Cluster_System));
    c->sites = malloc(N * sizeof(Site *));
    c->cluster_sizes = malloc(N * sizeof(int));
    c->num_clusters = 0;
    int i, j;
    for (i = 0; i < N; i++) {
        c->sites[i] = malloc(N * sizeof(Site));
        for (j = 0; j < N; j++) {
            c->sites[i][j] = *new_site(-1, 0, 0);
        }
    }
    return c;
}

// function to find the root of a site's cluster
int find_root(Cluster_System *c, int row, int col) {
    while (c->sites[row][col].parent != -1) {
        int parent_row = c->sites[row][col].parent / N;
        int parent_col = c->sites[row][col].parent % N;
        row = parent_row;
        col = parent_col;
    }
    return row * N + col;
}

// function to merge two clusters
void merge_clusters(Cluster_System *c, int row1, int col1, int row2, int col2) {
    int root1 = find_root(c, row1, col1);
    int root2 = find_root(c, row2, col2);
    if (root1 != root2) {
        if (c->sites[root1 / N][root1 % N].size < c->sites[root2 / N][root2 % N].size) {
            c->sites[root1 / N][root1 % N].parent = root2;
            c->sites[root2 / N][root2 % N].size += c->sites[root1 / N][root1 % N].size;
        }
        else {
            c->sites[root2 / N][root2 % N].parent = root1;
            c->sites[root1 / N][root1 % N].size += c->sites[root2 / N][root2 % N].size;
        }
        c->num_clusters--;
    }
}

// function to open a site
void open_site(Cluster_System *c, int row, int col) {
    c->sites[row][col].open = 1;
    c->sites[row][col].size = 1;
    int i, j;
    int neighbors[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (i = 0; i < 4; i++) {
        int neighbor_row = row + neighbors[i][0];
        int neighbor_col = col + neighbors[i][1];
        if (neighbor_row >= 0 && neighbor_row < N && neighbor_col >= 0 && neighbor_col < N && c->sites[neighbor_row][neighbor_col].open) {
            merge_clusters(c, row, col, neighbor_row, neighbor_col);
        }
    }
}

// function to print the grid
void print_grid(Cluster_System *c) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (c->sites[i][j].open) {
                if (c->sites[i][j].parent == -1) {
                    printf("-");
                }
                else {
                    printf("%c", 'A' + c->sites[i][j].parent % 26);
                }
            }
            else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    // seed random number generator
    srand(time(NULL));

    // initialize percolation simulator
    Cluster_System *c = new_cluster_system();

    // open sites with probability P
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if ((double) rand() / (double) RAND_MAX < P) {
                open_site(c, i, j);
            }
        }
    }

    // print grid
    print_grid(c);

    return 0;
}