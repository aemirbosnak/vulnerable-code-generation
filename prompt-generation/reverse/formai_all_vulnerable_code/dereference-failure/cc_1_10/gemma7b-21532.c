//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PERCOLATION_SIZE 100

typedef struct percolator {
    int **grid;
    int size;
    int water_level;
} percolator;

percolator* percolator_init(int size) {
    percolator* p = malloc(sizeof(percolator));
    p->size = size;
    p->grid = malloc(size * size * sizeof(int));
    p->water_level = 0;

    return p;
}

void percolator_fill(percolator* p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            p->grid[i][j] = 1;
        }
    }
}

void percolator_flood(percolator* p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if (p->grid[i][j] == 1) {
                p->water_level++;
            }
        }
    }
}

void percolator_run(percolator* p) {
    percolator_flood(p);
    printf("Water level: %d\n", p->water_level);
}

int main() {
    percolator* p = percolator_init(MAX_PERCOLATION_SIZE);
    percolator_fill(p);
    percolator_run(p);

    return 0;
}