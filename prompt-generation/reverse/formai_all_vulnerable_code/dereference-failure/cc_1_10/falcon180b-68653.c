//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100 // number of sites
#define M 1000 // number of Monte Carlo steps
#define P 0.5 // probability of site occupancy

int **create_lattice(int n) {
    int **lattice = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        lattice[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            lattice[i][j] = 0;
        }
    }
    return lattice;
}

void destroy_lattice(int **lattice, int n) {
    for (int i = 0; i < n; i++) {
        free(lattice[i]);
    }
    free(lattice);
}

void initialize_lattice(int **lattice, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rand() % 2 == 0) {
                lattice[i][j] = 1;
            }
        }
    }
}

int count_neighbors(int **lattice, int i, int j) {
    int count = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (k == 0 && l == 0)
                continue;
            count += lattice[i + k][j + l];
        }
    }
    return count;
}

void percolate(int **lattice, int n) {
    int **new_lattice = create_lattice(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int neighbors = count_neighbors(lattice, i, j);
            if (lattice[i][j] == 1 && neighbors < 2) {
                new_lattice[i][j] = 0;
            } else if (lattice[i][j] == 0 && neighbors >= 2) {
                new_lattice[i][j] = 1;
            } else {
                new_lattice[i][j] = lattice[i][j];
            }
        }
    }
    destroy_lattice(lattice, n);
    lattice = new_lattice;
}

void print_lattice(int **lattice, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (lattice[i][j] == 1) {
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int main() {
    int **lattice = create_lattice(N);
    initialize_lattice(lattice, N);
    for (int i = 0; i < M; i++) {
        percolate(lattice, N);
        print_lattice(lattice, N);
    }
    destroy_lattice(lattice, N);
    return 0;
}