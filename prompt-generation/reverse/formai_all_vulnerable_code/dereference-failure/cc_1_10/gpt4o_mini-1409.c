//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10  // Size of the grid

typedef struct {
    int** grid;
    int*** uf; // Union-Find data structure
    int openSites;
} Percolation;

void initGrid(Percolation* p) {
    p->grid = malloc(SIZE * sizeof(int*));
    for(int i = 0; i < SIZE; i++) {
        p->grid[i] = malloc(SIZE * sizeof(int));
        for(int j = 0; j < SIZE; j++) {
            p->grid[i][j] = 0; // Initialize all sites as blocked
        }
    }
    p->openSites = 0;
    
    // Initialize union-find structure
    p->uf = malloc(SIZE * SIZE * sizeof(int*));
    for (int i = 0; i < SIZE * SIZE; i++) {
        p->uf[i] = malloc(2 * sizeof(int));
        p->uf[i][0] = i;  // Parent
        p->uf[i][1] = 1;  // Rank
    }
}

void freeGrid(Percolation* p) {
    for (int i = 0; i < SIZE; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    
    for (int i = 0; i < SIZE * SIZE; i++) {
        free(p->uf[i]);
    }
    free(p->uf);
}

int find(Percolation* p, int x) {
    if (p->uf[x][0] != x) {
        p->uf[x][0] = find(p, p->uf[x][0]); // Path compression
    }
    return p->uf[x][0];
}

void unionSet(Percolation* p, int x, int y) {
    int rootX = find(p, x);
    int rootY = find(p, y);

    if (rootX != rootY) {
        // Union by rank
        if (p->uf[rootX][1] > p->uf[rootY][1]) {
            p->uf[rootY][0] = rootX;
        } else if (p->uf[rootX][1] < p->uf[rootY][1]) {
            p->uf[rootX][0] = rootY;
        } else {
            p->uf[rootY][0] = rootX;
            p->uf[rootX][1]++;
        }
    }
}

void openSite(Percolation* p, int row, int col) {
    if (p->grid[row][col] == 0) { // If site is blocked
        p->grid[row][col] = 1; // Open the site
        p->openSites++;
        
        int index = row * SIZE + col;
        
        // Connect to neighboring sites
        if (row > 0 && p->grid[row - 1][col] == 1) { // Up
            unionSet(p, index, (row - 1) * SIZE + col);
        }
        if (row < SIZE - 1 && p->grid[row + 1][col] == 1) { // Down
            unionSet(p, index, (row + 1) * SIZE + col);
        }
        if (col > 0 && p->grid[row][col - 1] == 1) { // Left
            unionSet(p, index, row * SIZE + (col - 1));
        }
        if (col < SIZE - 1 && p->grid[row][col + 1] == 1) { // Right
            unionSet(p, index, row * SIZE + (col + 1));
        }
    }
}

int percolates(Percolation* p) {
    int firstRowParent = find(p, 0);
    
    for (int col = 0; col < SIZE; col++) {
        if (p->grid[SIZE - 1][col] == 1) {
            int lastRowIndex = (SIZE - 1) * SIZE + col;
            if (find(p, firstRowParent) == find(p, lastRowIndex)) {
                return 1; // The system percolates
            }
        }
    }
    return 0; // The system does not percolate
}

void printGrid(Percolation* p) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    
    Percolation p;
    initGrid(&p);
    
    printf("Initial grid:\n");
    printGrid(&p);
    
    // Randomly open sites
    while (p.openSites < SIZE * SIZE) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        openSite(&p, row, col);
        
        printf("Opened site (%d, %d):\n", row, col);
        printGrid(&p);

        if (percolates(&p)) {
            printf("The system percolates!\n");
            break;
        }
    }
    
    freeGrid(&p);
    return 0;
}