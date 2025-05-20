//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int z;
} Point3D;

typedef struct {
    Point3D* points;
    int n;
    int m;
    int p;
    int iterations;
} Grid;

void generateGrid(Grid* grid, int n, int m, int p, int iterations) {
    srand(time(0));
    grid->n = n;
    grid->m = m;
    grid->p = p;
    grid->iterations = iterations;

    grid->points = (Point3D*)malloc(n * m * sizeof(Point3D));
    for (int i = 0; i < n * m; i++) {
        Point3D* p = &(grid->points[i]);
        p->x = rand() % (grid->m - 1) + 1;
        p->y = rand() % (grid->n - 1) + 1;
        p->z = 0;
    }
}

void printGrid(Grid grid) {
    for (int i = 0; i < grid.n; i++) {
        for (int j = 0; j < grid.m; j++) {
            printf("%d ", grid.points[i * grid.m + j].z);
        }
        printf("\n");
    }
}

void percolate(Grid grid) {
    for (int i = 0; i < grid.iterations; i++) {
        int n_percolating = 0;
        for (int j = 0; j < grid.n; j++) {
            for (int k = 0; k < grid.m; k++) {
                int neighbors = 0;
                for (int l = 0; l < grid.p; l++) {
                    Point3D* neighbor = &(grid.points[j * grid.m + k]);
                    neighbor->z = grid.points[j * grid.m + k].z + 1;
                    if (neighbor->z > grid.n * grid.m * grid.p) {
                        neighbor->z = 0;
                    } else if (neighbor->z > grid.points[j * grid.m + k].z) {
                        neighbors++;
                    } else {
                        neighbor->z = 0;
                    }
                }
                if (neighbors >= 3) {
                    n_percolating++;
                }
            }
        }
        printf("Iteration %d: %d percolating\n", i + 1, n_percolating);
    }
}

int main() {
    srand(time(0));
    int n = 50;
    int m = 50;
    int p = 4;
    int iterations = 100;

    Grid grid = {
       .n = n,
       .m = m,
       .p = p,
       .iterations = iterations
    };

    generateGrid(&grid, n, m, p, iterations);

    printGrid(grid);

    percolate(grid);

    return 0;
}