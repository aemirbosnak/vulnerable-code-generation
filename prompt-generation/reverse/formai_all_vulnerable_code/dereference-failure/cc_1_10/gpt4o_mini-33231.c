//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCKED 0
#define OPEN 1

typedef struct {
    int width;
    int height;
    int **grid;
} Percolation;

Percolation* createPercolation(int width, int height) {
    Percolation* perc = malloc(sizeof(Percolation));
    perc->width = width;
    perc->height = height;
    perc->grid = malloc(height * sizeof(int*));
    
    for (int i = 0; i < height; i++) {
        perc->grid[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            perc->grid[i][j] = BLOCKED; // Initialize all blocks as blocked
        }
    }

    return perc;
}

void freePercolation(Percolation* perc) {
    for (int i = 0; i < perc->height; i++) {
        free(perc->grid[i]);
    }
    free(perc->grid);
    free(perc);
}

void openSite(Percolation* perc, int x, int y) {
    if (x < 0 || x >= perc->height || y < 0 || y >= perc->width) {
        printf("Invalid coordinates to open site.\n");
        return;
    }
    perc->grid[x][y] = OPEN;
}

void printGrid(Percolation* perc) {
    for (int i = 0; i < perc->height; i++) {
        for (int j = 0; j < perc->width; j++) {
            printf("%d ", perc->grid[i][j]);
        }
        printf("\n");
    }
}

int isFull(Percolation* perc, int x, int y) {
    // Check if the site is full (open and connected to the top row)
    return (x == 0 && perc->grid[x][y] == OPEN) || 
           (x > 0 && (perc->grid[x-1][y] == OPEN || 
                       (y > 0 && perc->grid[x-1][y-1] == OPEN) || 
                       (y < perc->width - 1 && perc->grid[x-1][y + 1] == OPEN)));
}

int percolates(Percolation* perc) {
    for (int j = 0; j < perc->width; j++) {
        if (isFull(perc, perc->height - 1, j)) {
            return 1;
        }
    }
    return 0;
}

void randomOpenSites(Percolation* perc, int num) {
    srand(time(NULL));
    for (int n = 0; n < num; n++) {
        int x = rand() % perc->height;
        int y = rand() % perc->width;
        openSite(perc, x, y);
    }
}

int main() {
    int width = 10;
    int height = 10;
    Percolation* perc = createPercolation(width, height);

    printf("Initial grid (all blocked):\n");
    printGrid(perc);

    int numToOpen = 30; // Open 30 random sites
    randomOpenSites(perc, numToOpen);

    printf("\nGrid after opening %d random sites:\n", numToOpen);
    printGrid(perc);
    
    if (percolates(perc)) {
        printf("\nThe system percolates!\n");
    } else {
        printf("\nThe system does not percolate.\n");
    }
    
    freePercolation(perc);
    return 0;
}