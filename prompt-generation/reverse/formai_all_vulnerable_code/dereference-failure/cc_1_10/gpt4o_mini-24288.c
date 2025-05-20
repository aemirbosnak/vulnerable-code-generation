//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int size;
    int **grid;
} Percolation;

Percolation* createPercolation(int size) {
    Percolation* perc = (Percolation*)malloc(sizeof(Percolation));
    perc->size = size;
    perc->grid = (int**)malloc(size * sizeof(int*));
    
    for(int i = 0; i < size; i++) {
        perc->grid[i] = (int*)malloc(size * sizeof(int));
        for(int j = 0; j < size; j++) {
            perc->grid[i][j] = BLOCKED;
        }
    }
    return perc;
}

void freePercolation(Percolation *perc) {
    for(int i = 0; i < perc->size; i++) {
        free(perc->grid[i]);
    }
    free(perc->grid);
    free(perc);
}

void openSite(Percolation *perc, int row, int col) {
    if(row >= 0 && row < perc->size && col >= 0 && col < perc->size) {
        perc->grid[row][col] = OPEN;
    }
}

bool isOpen(Percolation *perc, int row, int col) {
    return (row >= 0 && row < perc->size && col >= 0 && col < perc->size) ? (perc->grid[row][col] == OPEN) : false;
}

bool isFull(Percolation *perc, int row, int col) {
    return isOpen(perc, row, col) && (row == 0 || isFull(perc, row - 1, col));
}

bool percolates(Percolation *perc) {
    for(int col = 0; col < perc->size; col++) {
        if(isFull(perc, perc->size - 1, col)) {
            return true;
        }
    }
    return false;
}

void printGrid(Percolation *perc) {
    for(int i = 0; i < perc->size; i++) {
        for(int j = 0; j < perc->size; j++) {
            printf("%s ", perc->grid[i][j] == OPEN ? "O" : "X");
        }
        printf("\n");
    }
}

void simulatePercolation(int size, float probability) {
    srand(time(NULL));
    Percolation *perc = createPercolation(size);
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if(((float) rand() / RAND_MAX) < probability) {
                openSite(perc, i, j);
            }
        }
    }

    printf("Percolation grid (O = Open, X = Blocked):\n");
    printGrid(perc);
    
    if (percolates(perc)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freePercolation(perc);
}

int main() {
    int gridSize;
    float openProbability;

    printf("Enter the size of the grid (e.g. 10): ");
    scanf("%d", &gridSize);
    printf("Enter the probability of a site being open (0.0 to 1.0): ");
    scanf("%f", &openProbability);

    if(gridSize <= 0 || openProbability < 0.0 || openProbability > 1.0) {
        printf("Invalid input. Please enter a valid grid size and probability.\n");
        return EXIT_FAILURE;
    }

    simulatePercolation(gridSize, openProbability);
    return EXIT_SUCCESS;
}