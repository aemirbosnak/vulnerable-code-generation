//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// Struct for keeping track of open and closed sites
typedef struct site {
    int isOpen;
    int id;
    int hasTopNeighbor;
    int hasBottomNeighbor;
    int hasLeftNeighbor;
    int hasRightNeighbor;
} site;

// Function prototypes
int getIndex(int row, int col);
int getRow(int i);
int getCol(int i);
int getNeighborIndex(site *sites, int i, int j);
site *createSites();
void printSites(site *sites);
void open(site *sites, int i, int j);
int isOpen(site *sites, int i, int j);
int isFull(site *sites, int i, int j);
int percolates(site *sites);

int main()
{
    site *sites = createSites();
    srand(time(NULL)); // Initializing random number generator
    
    int i = 0;
    int j = 0;
    while (!percolates(sites)) {
        i = rand() % SIZE;
        j = rand() % SIZE;
        open(sites, i, j);
    }
    printf("The system percolates!\n");
    printSites(sites);
    free(sites);
    return 0;
}

// Get the 1D array index of a site at (row, col)
int getIndex(int row, int col)
{
    return row * SIZE + col;
}

// Get the row of a site with index i
int getRow(int i)
{
    return i / SIZE;
}

// Get the column of a site with index i
int getCol(int i)
{
    return i % SIZE;
}

// Get the 1D array index of the neighbor of site i in direction j
int getNeighborIndex(site *sites, int i, int j)
{
    int row = getRow(i);
    int col = getCol(i);
    switch (j) {
        case 0: // Top
            if (row == 0) { // If already in top row, return -1
                return -1;
            } else {
                return getIndex(row - 1, col);
            }
            break;
            
        case 1: // Bottom
            if (row == SIZE - 1) { // If already in bottom row, return -1
                return -1;
            } else {
                return getIndex(row + 1, col);
            }
            break;
            
        case 2: // Left
            if (col == 0) { // If already in leftmost column, return -1
                return -1;
            } else {
                return getIndex(row, col - 1);
            }
            break;

        case 3: // Right
            if (col == SIZE - 1) { // If already in rightmost column, return -1
                return -1;
            } else {
                return getIndex(row, col + 1);
            }
            break;
    }
    return -1;
}

// Creates and initializes array of sites
site *createSites()
{
    site *sites = (site *)malloc(SIZE * SIZE * sizeof(site));
    for (int i = 0; i < SIZE * SIZE; i++) {
        sites[i].isOpen = 0;
        sites[i].id = i;
        sites[i].hasTopNeighbor = (i / SIZE == 0) ? 1 : 0; // If site is in top row, it has a top virtual site
        sites[i].hasBottomNeighbor = (i / SIZE == SIZE - 1) ? 1 : 0; // If site is in bottom row, it has a bottom virtual site
        sites[i].hasLeftNeighbor = (i % SIZE == 0) ? 1 : 0; // If site is in leftmost column, it has a left virtual site
        sites[i].hasRightNeighbor = (i % SIZE == SIZE - 1) ? 1 : 0; // If site is in rightmost column, it has a right virtual site
    }
    return sites;
}

// Prints out the current state of the system
void printSites(site *sites)
{
    printf("System:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", (sites[getIndex(i, j)].isOpen) ? ' ' : 'X');
        }
        printf("\n");
    }
}

// Opens the site at (i, j)
void open(site *sites, int i, int j)
{
    int index = getIndex(i, j);
    sites[index].isOpen = 1;
    for (int k = 0; k < 4; k++) {
        int neighborIndex = getNeighborIndex(sites, index, k);
        if (neighborIndex != -1 && sites[neighborIndex].isOpen) { // If neighbor exists and is open
            // Check if site and neighbor are in same component
            if (sites[index].id != sites[neighborIndex].id) {
                // Merge components and mark site and neighbor as having virtual site neighbors if needed
                int oldNeighborId = sites[neighborIndex].id;
                for (int l = 0; l < SIZE * SIZE; l++) {
                    if (sites[l].id == oldNeighborId) {
                        sites[l].id = sites[index].id;
                        sites[l].hasTopNeighbor = sites[l].hasTopNeighbor || sites[index].hasTopNeighbor;
                        sites[l].hasBottomNeighbor = sites[l].hasBottomNeighbor || sites[index].hasBottomNeighbor;
                        sites[l].hasLeftNeighbor = sites[l].hasLeftNeighbor || sites[index].hasLeftNeighbor;
                        sites[l].hasRightNeighbor = sites[l].hasRightNeighbor || sites[index].hasRightNeighbor;
                    }
                }
            }
        }
    }
}

// Returns 1 if site at (i, j) is open, 0 otherwise
int isOpen(site *sites, int i, int j)
{
    return sites[getIndex(i, j)].isOpen;
}

// Returns 1 if site at (i, j) is full (connected to top row), 0 otherwise
int isFull(site *sites, int i, int j)
{
    int index = getIndex(i, j);
    return sites[index].isOpen && sites[index].hasTopNeighbor;
}

// Returns 1 if the system percolates (i.e., there is a path from any site in the top row to any site in the bottom row), 0 otherwise
int percolates(site *sites)
{
    for (int i = 0; i < SIZE; i++) {
        if (sites[i].isOpen) {
            for (int j = 0; j < SIZE; j++) {
                if (sites[(SIZE * SIZE) - SIZE + i].isOpen) { // If site in bottom row is open
                    if (sites[i].id == sites[(SIZE * SIZE) - SIZE + i].id) { // If top site and bottom site are in same component, the system percolates
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}