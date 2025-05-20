//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10 // Grid size
#define OPEN 1
#define BLOCKED 0
#define EMPTY -1

typedef struct {
    int **grid;
    int size;
} Percolation;

void printGrid(Percolation *p) {
    printf("Grid state:\n");
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            switch (p->grid[i][j]) {
                case OPEN: 
                    printf(". ");
                    break;
                case BLOCKED: 
                    printf("X ");
                    break;
                default: 
                    printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

Percolation *createGrid(int size) {
    Percolation *p = (Percolation *)malloc(sizeof(Percolation));
    p->size = size;
    p->grid = (int **)malloc(size * sizeof(int *));
    
    for (int i = 0; i < size; i++) {
        p->grid[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = (rand() % 2) ? BLOCKED : OPEN; // Randomly set cells to OPEN or BLOCKED
        }
    }
    
    return p;
}

void freeGrid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

bool isOpen(Percolation *p, int row, int col) {
    return (row >= 0 && row < p->size && col >= 0 && col < p->size && p->grid[row][col] == OPEN);
}

bool percolates(Percolation *p) {
    bool *visited = (bool *)calloc(p->size * p->size, sizeof(bool));
    int *stack = (int *)malloc(p->size * p->size * 2 * sizeof(int)); // For DFS
    int top = -1;
    
    // Push all open sites in the first row onto the stack
    for (int j = 0; j < p->size; j++) {
        if (p->grid[0][j] == OPEN) {
            stack[++top] = 0;
            stack[++top] = j;
            visited[0 * p->size + j] = true;
        }
    }

    while (top >= 0) {
        int row = stack[top--]; 
        int col = stack[top--]; 

        if (row == p->size - 1) {
            free(stack);
            free(visited);
            return true;
        }

        // Explore neighboring cells
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int d = 0; d < 4; d++) {
            int newRow = row + directions[d][0];
            int newCol = col + directions[d][1];
            if (isOpen(p, newRow, newCol) && !visited[newRow * p->size + newCol]) {
                visited[newRow * p->size + newCol] = true;
                stack[++top] = newRow;
                stack[++top] = newCol;
            }
        }
    }

    free(stack);
    free(visited);
    return false;
}

int main() {
    srand(time(0)); // Seed for random number generator
    Percolation *p = createGrid(N);
    printGrid(p);

    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freeGrid(p);
    return 0;
}