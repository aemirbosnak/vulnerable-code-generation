//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Percolation {
    int **grid;
    int size;
} Percolation;

Percolation* initializePercolation(int size) {
    Percolation* p = (Percolation*)malloc(sizeof(Percolation));
    p->size = size;
    p->grid = (int**)malloc(size * size * sizeof(int));
    for (int i = 0; i < size * size; i++) {
        p->grid[i] = 0;
    }
    return p;
}

void simulatePercolation(Percolation* p) {
    int x, y;
    printf("Enter the coordinates of the drop (x, y): ");
    scanf("%d %d", &x, &y);

    if (x < 0 || x >= p->size || y < 0 || y >= p->size) {
        printf("Invalid coordinates.\n");
        return;
    }

    if (p->grid[y * p->size + x] == 1) {
        printf("The drop already exists.\n");
        return;
    }

    p->grid[y * p->size + x] = 1;

    // Check if the drop has reached the border
    if (p->grid[0][x] == 1 || p->grid[p->size - 1][x] == 1) {
        // The drop has reached the border, so it is pervaded
        printf("The drop has percolated!\n");
    } else {
        // The drop has not reached the border, so it continues to spread
        simulatePercolation(p);
    }
}

int main() {
    Percolation* p = initializePercolation(MAX_SIZE);
    simulatePercolation(p);

    return 0;
}