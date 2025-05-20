//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCKED 0
#define OPEN 1

typedef struct {
    int **grid;
    int size;
} PercolationSystem;

PercolationSystem* create_system(int size);
void free_system(PercolationSystem* system);
void initialize_system(PercolationSystem* system);
int is_open(PercolationSystem* system, int row, int col);
void open_site(PercolationSystem* system, int row, int col);
int percolates(PercolationSystem* system);
void print_system(PercolationSystem* system);
void simulate_percolation(PercolationSystem* system, float probability);

int main() {
    srand(time(NULL));
    int size = 10;  // Size of the grid
    float probability = 0.5;  // Probability of opening a site

    PercolationSystem* system = create_system(size);
    initialize_system(system);
    simulate_percolation(system, probability);

    if (percolates(system)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    print_system(system);
    free_system(system);
    return 0;
}

PercolationSystem* create_system(int size) {
    PercolationSystem* system = (PercolationSystem*)malloc(sizeof(PercolationSystem));
    system->size = size;
    system->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        system->grid[i] = (int*)malloc(size * sizeof(int));
    }
    return system;
}

void free_system(PercolationSystem* system) {
    for (int i = 0; i < system->size; i++) {
        free(system->grid[i]);
    }
    free(system->grid);
    free(system);
}

void initialize_system(PercolationSystem* system) {
    for (int i = 0; i < system->size; i++) {
        for (int j = 0; j < system->size; j++) {
            system->grid[i][j] = BLOCKED;
        }
    }
}

int is_open(PercolationSystem* system, int row, int col) {
    if (row >= 0 && row < system->size && col >= 0 && col < system->size) {
        return system->grid[row][col] == OPEN;
    }
    return 0;  // out of bounds
}

void open_site(PercolationSystem* system, int row, int col) {
    if (row >= 0 && row < system->size && col >= 0 && col < system->size) {
        system->grid[row][col] = OPEN;
    }
}

void simulate_percolation(PercolationSystem* system, float probability) {
    for (int i = 0; i < system->size; i++) {
        for (int j = 0; j < system->size; j++) {
            if ((float)rand() / RAND_MAX < probability) {
                open_site(system, i, j);
            }
        }
    }
}

int percolates(PercolationSystem* system) {
    for (int col = 0; col < system->size; col++) {
        if (is_open(system, 0, col)) {
            for (int row = 0; row < system->size; row++) {
                if (is_open(system, row, col)) {
                    for (int dcol = -1; dcol <= 1; dcol++) {
                        if (is_open(system, row + 1, col + dcol)) {
                            if (row == system->size - 1) {
                                return 1;  // Percolates if we reach the bottom row
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;  // Does not percolate
}

void print_system(PercolationSystem* system) {
    for (int i = 0; i < system->size; i++) {
        for (int j = 0; j < system->size; j++) {
            printf(system->grid[i][j] == OPEN ? "O " : ". ");
        }
        printf("\n");
    }
}