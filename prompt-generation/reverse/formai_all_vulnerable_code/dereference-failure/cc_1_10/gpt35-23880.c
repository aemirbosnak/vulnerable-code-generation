//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Defines the size of the grid. 

int uf_find(int p, int *uf) {  // uf_find function to find if two sites are connected
    while (p != uf[p]) {
        uf[p] = uf[uf[p]];
        p = uf[p];
    }
    return p;
}

void uf_union(int p, int q, int *uf, int *sz) { // uf_union function to unite the two sites
    int rootP = uf_find(p, uf);
    int rootQ = uf_find(q, uf);

    if (rootP == rootQ) {
        return;
    }

    if (sz[rootP] < sz[rootQ]) {
        uf[rootP] = rootQ;
        sz[rootQ] += sz[rootP];
    } else {
        uf[rootQ] = rootP;
        sz[rootP] += sz[rootQ];
    }
}

int percolates(int *grid) { // percolates function to check if the system percolates
    int i, j;
    int *uf = malloc(N*N*sizeof(int));
    int *sz = malloc(N*N*sizeof(int));
    for (i = 0; i < N*N; i++) {
        uf[i] = i;
        sz[i] = 1;
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (*(grid + i*N + j) == 1) {
                if (i > 0) {
                    if (*(grid + (i-1)*N + j) == 1) {
                        uf_union(i*N + j, (i-1)*N + j, uf, sz);
                    }
                }
                if (i < N-1) {
                    if (*(grid + (i+1)*N + j) == 1) {
                        uf_union(i*N + j, (i+1)*N + j, uf, sz);
                    }
                }
                if (j > 0) {
                    if (*(grid + i*N + j-1) == 1) {
                        uf_union(i*N + j, i*N + j-1, uf, sz);
                    }
                }
                if (j < N-1) {
                    if (*(grid + i*N + j+1) == 1) {
                        uf_union(i*N + j, i*N + j+1, uf, sz);
                    }
                }
            }
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (*(grid + i*N + j) == 1) {
                if (uf_find(i*N + j, uf) < N) {
                    free(uf);
                    free(sz);
                    return 1;
                }
            }
        }
    }

    free(uf);
    free(sz);
    return 0;
}

int main() {
    int i, j, p;
    int *grid = malloc(N*N*sizeof(int));
    srand(time(NULL));
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            p = rand() % 100;
            if (p < 60) {
                *(grid + i*N + j) = 0;
            } else {
                *(grid + i*N + j) = 1;
            }
        }
    }

    printf("Initial Grid:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", *(grid + i*N + j));
        }
        printf("\n");
    }

    if (percolates(grid)) {
        printf("The system percolates\n");
    } else {
        printf("The system does not percolate\n");
    }

    free(grid);
    return 0;
}