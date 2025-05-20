//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A struct to represent a site in the Percolation system
typedef struct Site{
    int row;
    int col;
    int isOpen;
    int isFull;
} Site;

void printGrid(int n, Site **grid) {
    // Print out the grid to the console with '#' representing an open site 
    // and ' ' representing a blocked site
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("%d | ", i+1);
        for(int j = 0; j < n; j++) {
            if(grid[i][j].isOpen) {
                printf("# ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("   ");
    for(int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int isOpen(int i, int j, int n, Site **grid) {
    // Check if a site at row i and col j is open 
    if(i < 0 || i > n-1 || j < 0 || j > n-1) {
        return 0;
    }
    return grid[i][j].isOpen;
}

int isFull(int i, int j, int n, Site **grid) {
    // Check if a site at row i and col j is full
    if(i < 0 || i > n-1 || j < 0 || j > n-1) {
        return 0;
    }
    return grid[i][j].isFull;
}

void setOpen(int i, int j, Site **grid) {
    // Open a site at row i and col j
    grid[i][j].isOpen = 1;
}

void setFull(int i, int j, Site **grid) {
    // Set a site at row i and col j as full
    grid[i][j].isFull = 1;
}

void unionSites(int i1, int j1, int i2, int j2, Site **grid) {
    // Union two sites together
    int p = i1 * (sizeof(Site *)/sizeof(Site)) + j1; // site 1 index 
    int q = i2 * (sizeof(Site *)/sizeof(Site)) + j2; // site 2 index
    grid[p/sizeof(Site)][p%sizeof(Site)].row = i1;
    grid[p/sizeof(Site)][p%sizeof(Site)].col = j1;
    grid[q/sizeof(Site)][q%sizeof(Site)].row = i2;
    grid[q/sizeof(Site)][q%sizeof(Site)].col = j2; 
}

int connected(int p, int q, Site **grid) {
    // Check if two sites are connected (have the same parent)
    int px = grid[p/sizeof(Site)][p%sizeof(Site)].row;
    int py = grid[p/sizeof(Site)][p%sizeof(Site)].col;
    int qx = grid[q/sizeof(Site)][q%sizeof(Site)].row;
    int qy = grid[q/sizeof(Site)][q%sizeof(Site)].col;
    if(px==qx && py==qy) {
        return 1;
    }
    else {
        return 0;
    }
}

int percolates(int n, Site **grid) {
    // Check if the system has percolated from the top to the bottom
    for(int i = 0; i < n; i++) {
        if(grid[0][i].isOpen) {
            for(int j = 0; j < n; j++) {
                if(grid[n-1][j].isOpen) {
                    if(connected(i, j, grid)) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void percolate(int n) {
    // Create a Percolation system and open sites until it percolates
    Site **grid = malloc(sizeof(Site*) * n);
    for(int i = 0; i < n; i++) {
        grid[i] = malloc(sizeof(Site) * n);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            grid[i][j].isOpen = 0;
            grid[i][j].isFull = 0;
        }
    }
    int i, j;
    while(!percolates(n, grid)) {
        i = rand() % n;
        j = rand() % n;
        if(!isOpen(i, j, n, grid)) {
            setOpen(i, j, grid);
            setFull(i, j, grid);
            if(isOpen(i-1, j, n, grid)) {
                unionSites(i, j, i-1, j, grid);
            }
            if(isOpen(i+1, j, n, grid)) {
                unionSites(i, j, i+1, j, grid);
            }
            if(isOpen(i, j-1, n, grid)) {
                unionSites(i, j, i, j-1, grid);
            }
            if(isOpen(i, j+1, n, grid)) {
                unionSites(i, j, i, j+1, grid);
            }
        }
    }
    printGrid(n, grid);
    printf("Percolates!\n");
}

int main() {
    srand(time(0));
    percolate(8); // change the input to change the size of the grid
    return 0;
}