//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PERCOLATION_SIZE 256

typedef struct percolator_t {
    int **grid;
    int size;
    int current_water_level;
    int max_water_level;
    int num_generations;
} percolator_t;

percolator_t* percolator_init(int size, int max_water_level, int num_generations) {
    percolator_t* p = malloc(sizeof(percolator_t));
    p->size = size;
    p->max_water_level = max_water_level;
    p->current_water_level = max_water_level;
    p->num_generations = num_generations;

    p->grid = malloc(p->size * sizeof(int*));
    for (int i = 0; i < p->size; i++) {
        p->grid[i] = malloc(p->size * sizeof(int));
    }

    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            p->grid[i][j] = 0;
        }
    }

    return p;
}

void percolator_generate_water(percolator_t* p) {
    int x, y;
    srand(time(NULL));

    for (int i = 0; i < p->num_generations; i++) {
        for (int attempts = 0; attempts < MAX_PERCOLATION_SIZE; attempts++) {
            x = rand() % p->size;
            y = rand() % p->size;

            if (p->grid[x][y] == 0 && p->current_water_level > 0) {
                p->grid[x][y] = 1;
                p->current_water_level--;
                break;
            }
        }
    }
}

void percolator_display(percolator_t* p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    percolator_t* p = percolator_init(5, 5, 10);
    percolator_generate_water(p);
    percolator_display(p);

    return 0;
}