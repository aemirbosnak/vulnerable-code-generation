//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define SITE_OPEN 1
#define SITE_CLOSED 0

int grid[SIZE][SIZE];
int open[SIZE * SIZE];
int nOpen = 0;

int uf_find(int *sites, int i)
{
    while (sites[i] != i)
        i = sites[i];
    return i;
}

void uf_union(int *sites, int *sizes, int p, int q)
{
    int rootP = uf_find(sites, p);
    int rootQ = uf_find(sites, q);
    if (rootP == rootQ) return;

    if (sizes[rootP] < sizes[rootQ]) {
        sites[rootP] = rootQ;
        sizes[rootQ] += sizes[rootP];
    } else {
        sites[rootQ] = rootP;
        sizes[rootP] += sizes[rootQ];
    }
}

void init_grid(int grid[][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = SITE_CLOSED;
        }
    }
}

void print_grid(int grid[][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == SITE_CLOSED) {
                printf("%c  ", 178);
            } else {
                printf("%c  ", 176);
            }
        }
        printf("\n");
    }
}

void open_random_site()
{
    int i, j, n;
    do {
        i = rand() % SIZE;
        j = rand() % SIZE;
    } while (grid[i][j] != SITE_CLOSED);
    grid[i][j] = SITE_OPEN;
    n = i * SIZE + j;
    open[nOpen++] = n;
}

int percolates()
{
    int i, j;
    int *sites, *sizes;

    sites = (int *) malloc(SIZE * SIZE * sizeof(int));
    sizes = (int *) malloc(SIZE * SIZE * sizeof(int));

    for (i = 0; i < SIZE * SIZE; i++) {
        sites[i] = i;
        sizes[i] = 1;
    }

    for (i = 0; i < nOpen; i++) {
        int n = open[i];
        int row = n / SIZE;
        int col = n % SIZE;

        if (row == 0) {
            uf_union(sites, sizes, n, SIZE * SIZE);
        }

        if (row > 0 && grid[row-1][col] == SITE_OPEN) {
            uf_union(sites, sizes, n, n - SIZE);
        }

        if (row < SIZE - 1 && grid[row+1][col] == SITE_OPEN) {
            uf_union(sites, sizes, n, n + SIZE);
        }

        if (col > 0 && grid[row][col-1] == SITE_OPEN) {
            uf_union(sites, sizes, n, n - 1);
        }

        if (col < SIZE - 1 && grid[row][col+1] == SITE_OPEN) {
            uf_union(sites, sizes, n, n + 1);
        }

        if (uf_find(sites, n) == uf_find(sites, SIZE * SIZE)) {
            free(sites);
            free(sizes);
            return 1; // percolates
        }
    }

    free(sites);
    free(sizes);
    return 0; // does not percolate
}

int main()
{
    srand(time(0));

    init_grid(grid);

    while (!percolates()) {
        open_random_site();
    }

    print_grid(grid);

    return 0;
}