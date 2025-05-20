//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ON 1
#define OFF 0

typedef struct {
    int *grid;
    int size;
} Percolation;

Percolation* createPercolation(int size);
void freePercolation(Percolation* perc);
void openSite(Percolation* perc, int row, int col);
int isOpen(Percolation* perc, int row, int col);
void printGrid(Percolation* perc);
int percolates(Percolation* perc);
void fill(Percolation* perc, int row, int col);
int isValid(int size, int row, int col);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <grid size> <probability>\n", argv[0]);
        return 1;
    }

    int gridSize = atoi(argv[1]);
    float probability = atof(argv[2]);
    if (gridSize <= 0 || probability < 0 || probability > 1) {
        printf("Invalid arguments. Grid size must be positive and probability must be between 0 and 1.\n");
        return 1;
    }

    srand(time(NULL));
    Percolation* perc = createPercolation(gridSize);

    // Open random sites based on the given probability
    for (int row = 0; row < gridSize; row++) {
        for (int col = 0; col < gridSize; col++) {
            if ((float)rand() / RAND_MAX < probability) {
                openSite(perc, row, col);
            }
        }
    }

    printf("Percolation Grid:\n");
    printGrid(perc);
    if (percolates(perc)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freePercolation(perc);
    return 0;
}

Percolation* createPercolation(int size) {
    Percolation* perc = (Percolation*)malloc(sizeof(Percolation));
    perc->size = size;
    perc->grid = (int*)calloc(size * size, sizeof(int));
    return perc;
}

void freePercolation(Percolation* perc) {
    free(perc->grid);
    free(perc);
}

void openSite(Percolation* perc, int row, int col) {
    if (isValid(perc->size, row, col)) {
        perc->grid[row * perc->size + col] = ON;
    }
}

int isOpen(Percolation* perc, int row, int col) {
    return isValid(perc->size, row, col) && perc->grid[row * perc->size + col] == ON;
}

void printGrid(Percolation* perc) {
    for (int row = 0; row < perc->size; row++) {
        for (int col = 0; col < perc->size; col++) {
            printf("%d ", perc->grid[row * perc->size + col]);
        }
        printf("\n");
    }
}

int percolates(Percolation* perc) {
    for (int col = 0; col < perc->size; col++) {
        if (isOpen(perc, 0, col)) {
            fill(perc, 0, col);
        }
    }
    
    // Check bottom row for open sites
    for (int col = 0; col < perc->size; col++) {
        if (isOpen(perc, perc->size - 1, col)) {
            return 1; // Percolates
        }
    }
    return 0; // Does not percolate
}

void fill(Percolation* perc, int row, int col) {
    if (!isOpen(perc, row, col)) return;
  
    // Mark the site as filled
    perc->grid[row * perc->size + col] = OFF;

    // Recursively fill adjacent sites
    fill(perc, row + 1, col); // Down
    fill(perc, row - 1, col); // Up
    fill(perc, row, col + 1); // Right
    fill(perc, row, col - 1); // Left
}

int isValid(int size, int row, int col) {
    return row >= 0 && row < size && col >= 0 && col < size;
}