//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Adjust this to change the size of the grid
#define THRESHOLD 0.6 // Adjust this to change the percolation threshold

typedef struct {
    int row;
    int col;
} Site;

typedef struct {
    int size;
    int *id;
} Grid;

void init(Grid *g);
void print_grid(Grid *g);
int find(Grid *g, int p);
void unite(Grid *g, int p, int q);
void percolate(Grid *g);
int is_percolated(Grid *g);

int main() {
    srand(time(NULL)); // Seed the random number generator
    Grid *g = malloc(sizeof(Grid));
    g->size = SIZE*SIZE + 2; // Add two extra sites for virtual top and bottom nodes
    g->id = malloc(g->size * sizeof(int));
    init(g);
    print_grid(g);
    percolate(g);
    if (is_percolated(g)) {
        printf("The grid has percolated!\n");
    } else {
        printf("The grid has not percolated. :(\n");
    }
    free(g->id);
    free(g);
    return 0;
}

void init(Grid *g) {
    for (int i = 0; i < g->size; i++) {
        g->id[i] = -1; // Initialize all sites to be unconnected
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int site = i*SIZE + j + 1; // Map (i, j) to a unique site number
            if ((double) rand() / RAND_MAX < THRESHOLD) {
                g->id[site] = site; // Connect the site to itself with probability THRESHOLD
            }
        }
    }
    // Connect the virtual top and bottom nodes to all sites in the top and bottom rows respectively
    for (int j = 1; j <= SIZE; j++) {
        unite(g, 0, j);
        unite(g, g->size - 1, g->size - j - 1);
    }
}

void print_grid(Grid *g) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int site = i*SIZE + j + 1;
            if (g->id[site] == -1) {
                printf(". "); // Unconnected site
            } else {
                printf("o "); // Connected site
            }
        }
        printf("\n");
    }
}

int find(Grid *g, int p) {
    while (p != g->id[p]) {
        p = g->id[p];
    }
    return p;
}

void unite(Grid *g, int p, int q) {
    int pid = find(g, p);
    int qid = find(g, q);
    if (pid != qid) {
        g->id[pid] = qid;
    }
}

void percolate(Grid *g) {
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int site = (i - 1)*SIZE + j + 1;
            if (g->id[site] != -1) {
                if (i > 1 && g->id[site - SIZE] != -1) {
                    unite(g, site, site - SIZE); // Connect to the site above
                }
                if (i < SIZE && g->id[site + SIZE] != -1) {
                    unite(g, site, site + SIZE); // Connect to the site below
                }
                if (j > 0 && g->id[site - 1] != -1) {
                    unite(g, site, site - 1); // Connect to the site to the left
                }
                if (j < SIZE - 1 && g->id[site + 1] != -1) {
                    unite(g, site, site + 1); // Connect to the site to the right
                }
            }
        }
    }
}

int is_percolated(Grid *g) {
    return find(g, 0) == find(g, g->size - 1);
}