//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int row;
    int col;
    int state;
} site;

void initialize_sites(site *sites, int nx, int ny) {
    int i, j;
    for (i = 0; i < nx; i++) {
        for (j = 0; j < ny; j++) {
            sites[i * ny + j].state = 0;
        }
    }
}

void print_sites(site *sites, int nx, int ny) {
    int i, j;
    for (i = 0; i < nx; i++) {
        for (j = 0; j < ny; j++) {
            printf("%d ", sites[i * ny + j].state);
        }
        printf("\n");
    }
}

int main() {
    int nx = 20, ny = 20;
    site *sites = (site *)malloc(nx * ny * sizeof(site));
    int i, j;
    initialize_sites(sites, nx, ny);
    printf("Initial state:\n");
    print_sites(sites, nx, ny);

    // Simulate percolation
    srand(time(NULL));
    int p = 0.2;
    int k = 0;
    while (k < 100) {
        int row, col, state;
        do {
            row = rand() % nx;
            col = rand() % ny;
            state = rand() % 2;
        } while (sites[row * ny + col].state!= 0);
        sites[row * ny + col].state = state;
        k++;
        if (state == 1) {
            printf("Percolation at (%d, %d)\n", row, col);
        }
        printf("State after %d iterations:\n", k);
        print_sites(sites, nx, ny);
    }

    free(sites);
    return 0;
}