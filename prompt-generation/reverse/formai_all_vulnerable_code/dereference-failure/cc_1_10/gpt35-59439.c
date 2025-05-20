//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// function to generate a random number between 0 and 1
double randProb() {
    return (double) rand() / (double) RAND_MAX;
}

// struct to represent a site
typedef struct {
    int row, col;
    bool isOpen;
} Site;

// struct to represent a percolation system
typedef struct {
    int size;           // size of the grid
    Site *sites;        // array to hold the sites
    int *parents;       // array to hold the parent sites (for union-find)
    int numOpenSites;   // number of open sites in the system
} Percolation;

// function to get the index of a site in the 1D array
int getIndex(Percolation *p, int row, int col) {
    // check that the row and col are within the bounds of the grid
    if (row < 1 || row > p->size || col < 1 || col > p->size) {
        return -1;  // return -1 to indicate an invalid index
    }
    return (row - 1) * p->size + (col - 1);
}

// function to initialize the percolation system
void init(Percolation *p, int size) {
    p->size = size;
    p->sites = (Site *) malloc(sizeof(Site) * size * size);
    p->parents = (int *) malloc(sizeof(int) * size * size);
    p->numOpenSites = 0;
    // initialize the sites and parent sites
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            int index = getIndex(p, i, j);
            p->sites[index].row = i;
            p->sites[index].col = j;
            p->sites[index].isOpen = false;
            p->parents[index] = index;
        }
    }
}

// function to free the memory used by the percolation system
void freePercolation(Percolation *p) {
    free(p->sites);
    free(p->parents);
}

// function to print the current state of the percolation system
void printGrid(Percolation *p) {
    printf("\n");
    printf("Percolation System:\n\n");
    for (int i = 1; i <= p->size; i++) {
        for (int j = 1; j <= p->size; j++) {
            int index = getIndex(p, i, j);
            if (p->sites[index].isOpen) {
                printf(" ");
            } else {
                printf("*");
            }
            printf(" ");
        }
        printf("\n");
    }
}

// function to connect two sites (for the union-find algorithm)
void connect(Percolation *p, int site1, int site2) {
    // find the parent sites of site1 and site2
    int parent1 = p->parents[site1];
    int parent2 = p->parents[site2];
    // if site1 and site2 are already connected, stop
    if (parent1 == parent2) {
        return;
    }
    // otherwise, set the parent of site1 to site2's parent and update the number of open sites
    p->parents[parent1] = parent2;
    p->numOpenSites++;
}

// function to open a site
void openSite(Percolation *p, int row, int col) {
    // get the index of the site
    int index = getIndex(p, row, col);
    // check if the site is already open
    if (p->sites[index].isOpen) {
        return;
    }
    // otherwise, open the site and connect it to any adjacent open sites
    p->sites[index].isOpen = true;
    // check the site above
    if (row > 1) {
        int aboveIndex = getIndex(p, row - 1, col);
        if (p->sites[aboveIndex].isOpen) {
            connect(p, index, aboveIndex);
        }
    }
    // check the site below
    if (row < p->size) {
        int belowIndex = getIndex(p, row + 1, col);
        if (p->sites[belowIndex].isOpen) {
            connect(p, index, belowIndex);
        }
    }
    // check the site to the left
    if (col > 1) {
        int leftIndex = getIndex(p, row, col - 1);
        if (p->sites[leftIndex].isOpen) {
            connect(p, index, leftIndex);
        }
    }
    // check the site to the right
    if (col < p->size) {
        int rightIndex = getIndex(p, row, col + 1);
        if (p->sites[rightIndex].isOpen) {
            connect(p, index, rightIndex);
        }
    }
}

// function to check if the percolation system percolates
bool percolates(Percolation *p) {
    // check if any site in the top row is connected to any site in the bottom row
    for (int i = 1; i <= p->size; i++) {
        int topIndex = getIndex(p, 1, i);
        int bottomIndex = getIndex(p, p->size, i);
        if (p->sites[topIndex].isOpen && p->sites[bottomIndex].isOpen && p->parents[topIndex] == p->parents[bottomIndex]) {
            return true;
        }
    }
    return false;
}

int main() {
    // set the seed for the random number generator
    srand(time(NULL));
    // initialize the percolation system
    Percolation p;
    init(&p, 10);
    // open random sites until the system percolates
    while (!percolates(&p)) {
        int row = (int) (randProb() * p.size) + 1;
        int col = (int) (randProb() * p.size) + 1;
        openSite(&p, row, col);
    }
    // print the final state of the system
    printGrid(&p);
    printf("\nPercolation Threshold: %f\n", (double) p.numOpenSites / (double) (p.size * p.size));
    // free the memory used by the percolation system
    freePercolation(&p);
    return 0;
}