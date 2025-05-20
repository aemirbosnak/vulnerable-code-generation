//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define OPEN 1
#define BLOCKED 0

typedef struct {
    int size;
    int** grid;
    int* root;
} Percolation;

Percolation* createPercolation(int size);
void freePercolation(Percolation* perc);
void openSite(Percolation* perc, int row, int col);
bool isOpen(Percolation* perc, int row, int col);
bool percolates(Percolation* perc);
void printGrid(Percolation* perc);
int findRoot(Percolation* perc, int idx);
void unionSets(Percolation* perc, int p, int q);
void initialize(Percolation* perc);

int main() {
    srand(time(NULL));
    
    int gridSize;
    printf("Welcome to the Percolation Simulator! 🎉\n");
    printf("Enter the size of the grid (NxN): ");
    scanf("%d", &gridSize);
    printf("\nLet the simulation begin!\n");

    Percolation* perc = createPercolation(gridSize);
    initialize(perc);

    while (true) {
        printGrid(perc);
        int row, col;
        printf("Choose a site to open (row col): ");
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= gridSize || col < 0 || col >= gridSize) {
            printf("Out of bounds! Try again.\n");
            continue;
        }

        openSite(perc, row, col);
        if (percolates(perc)) {
            printf("Yay! The system percolates! 🌊\n");
            break;
        } else {
            printf("The system does not percolate yet. Keep trying!\n");
        }
    }

    freePercolation(perc);
    return 0;
}

Percolation* createPercolation(int size) {
    Percolation* perc = (Percolation*)malloc(sizeof(Percolation));
    perc->size = size;
    perc->grid = (int**)malloc(size * sizeof(int*));
    perc->root = (int*)malloc(size * size * sizeof(int));

    for (int i = 0; i < size; i++) {
        perc->grid[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            perc->grid[i][j] = BLOCKED; // Start with all sites blocked
        }
    }

    return perc;
}

void freePercolation(Percolation* perc) {
    for (int i = 0; i < perc->size; i++) {
        free(perc->grid[i]);
    }
    free(perc->grid);
    free(perc->root);
    free(perc);
}

void openSite(Percolation* perc, int row, int col) {
    if (!isOpen(perc, row, col)) {
        perc->grid[row][col] = OPEN;
        printf("Opening site (%d, %d)! 🌟\n", row, col);
    }
}

bool isOpen(Percolation* perc, int row, int col) {
    return perc->grid[row][col] == OPEN;
}

int findRoot(Percolation* perc, int idx) {
    while (idx != perc->root[idx]) {
        idx = perc->root[idx];
    }
    return idx;
}

void unionSets(Percolation* perc, int p, int q) {
    int rootP = findRoot(perc, p);
    int rootQ = findRoot(perc, q);
    if (rootP != rootQ) {
        perc->root[rootP] = rootQ; // Connect the roots
    }
}

void initialize(Percolation* perc) {
    int n = perc->size;
    for (int i = 0; i < n * n; i++) {
        perc->root[i] = i; // Each site is its own root initially
    }

    // Connect top row sites (for percolation)
    for (int j = 0; j < n; j++) {
        if (isOpen(perc, 0, j)) {
            unionSets(perc, j, -1); // Connect to virtual top site
        }
    }
}

bool percolates(Percolation* perc) {
    // Check if the bottom row is connected to the top
    int n = perc->size;
    for (int j = 0; j < n; j++) {
        if (findRoot(perc, j) == findRoot(perc, -1)) {
            return true;
        }
    }
    return false;
}

void printGrid(Percolation* perc) {
    printf("Current Grid State:\n");
    for (int i = 0; i < perc->size; i++) {
        for (int j = 0; j < perc->size; j++) {
            if (isOpen(perc, i, j))
                printf(" O "); // Open
            else
                printf(" X "); // Blocked
        }
        printf("\n");
    }
    printf("\n");
}