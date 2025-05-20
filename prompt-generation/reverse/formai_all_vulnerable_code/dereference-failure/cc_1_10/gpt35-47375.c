//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of the grid

// Define a structure for each site in the grid
typedef struct {
    int row;
    int col;
    int isOpen;
} Site;

// Define a structure for the percolation system
typedef struct {
    Site** grid;
    int openCount;
} Percolation;

// Function prototypes
Percolation* initializePercolationSystem();
Site** initializeGrid();
void openSite(Percolation* perc, int row, int col);
int isPercolated(Percolation* perc);

int main() {
    srand(time(NULL)); // Initialize random number generator
    Percolation* perc = initializePercolationSystem(); // Initialize percolation system
    int siteOpened = -1; // Initialize variable for tracking sites opened
    while(!isPercolated(perc)) { // Loop until percolation occurs
        printf("Total open sites: %d\n", perc->openCount); // Print number of open sites
        printf("Enter site to open (0 to quit): "); // Prompt user for site to open
        scanf("%d", &siteOpened); // Read user input
        if(siteOpened == 0) { // If user inputs 0, quit program
            printf("Goodbye!\n");
            return 0;
        }
        int row = rand() % N; // Randomly choose row and column
        int col = rand() % N;
        openSite(perc, row, col); // Open random site
    }
    printf("Percolation occurred after opening %d sites.\n", perc->openCount); // Print result
    return 0;
}

/* Function to initialize percolation system */
Percolation* initializePercolationSystem() {
    Percolation* perc = (Percolation*) malloc(sizeof(Percolation));
    perc->grid = initializeGrid();
    perc->openCount = 0;
    return perc;
}

/* Function to initialize grid */
Site** initializeGrid() {
    Site** grid = (Site**) malloc(N * sizeof(Site*));
    for(int i = 0; i < N; i++) {
        grid[i] = (Site*) malloc(N * sizeof(Site));
        for(int j = 0; j < N; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].isOpen = 0;
        }
    }
    return grid;
}

/* Function to open site */
void openSite(Percolation* perc, int row, int col) {
    if(row < 0 || row >= N || col < 0 || col >= N) { // Check if site is out of bounds
        return;
    }
    if(perc->grid[row][col].isOpen) { // Check if site is already open
        return;
    }
    perc->grid[row][col].isOpen = 1; // Open site
    perc->openCount++; // Increment open site count
    printf("Site (%d, %d) opened.\n", row, col); // Print message
}

/* Function to check if percolation occurs */
int isPercolated(Percolation* perc) {
    if(perc->openCount == N*N) { // If all sites are open, percolation occurs
        return 1;
    }
    for(int i = 0; i < N; i++) { // Check if top and bottom rows are connected
        if(perc->grid[0][i].isOpen && perc->grid[N-1][i].isOpen) {
            return 1;
        }
    }
    return 0;
}