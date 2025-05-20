//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define OPEN 1
#define CLOSED 0

typedef struct {
    int row;
    int col;
} Cell;

typedef struct {
    int size;
    int **grid;
} Percolation;

Percolation* create_percolation(int size) {
    Percolation *p = (Percolation *)malloc(sizeof(Percolation));
    p->size = size;
    p->grid = (int **)malloc(size * sizeof(int *));
    
    for (int i = 0; i < size; i++) {
        p->grid[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = CLOSED; // Initialize all cells as closed
        }
    }
    
    return p;
}

void open_cell(Percolation *p, int row, int col) {
    if (row >= 0 && row < p->size && col >= 0 && col < p->size) {
        p->grid[row][col] = OPEN;
    }
}

bool is_valid(int row, int col, int size) {
    return (row >= 0 && row < size && col >= 0 && col < size);
}

bool dfs(Percolation *p, int row, int col, bool **visited) {
    if (row == p->size - 1) {
        return true; // Reached the bottom row
    }
    
    visited[row][col] = true;
    
    // Directions arrays for moving in 4 possible directions
    int dRow[] = {1, -1, 0, 0};
    int dCol[] = {0, 0, 1, -1};
    
    for (int i = 0; i < 4; i++) {
        int newRow = row + dRow[i];
        int newCol = col + dCol[i];
        
        if (is_valid(newRow, newCol, p->size) && 
            p->grid[newRow][newCol] == OPEN && 
            !visited[newRow][newCol]) {
            if (dfs(p, newRow, newCol, visited)) {
                return true;
            }
        }
    }
    
    return false;
}

bool percolates(Percolation *p) {
    bool **visited = (bool **)malloc(p->size * sizeof(bool *));
    for (int i = 0; i < p->size; i++) {
        visited[i] = (bool *)malloc(p->size * sizeof(bool));
        for (int j = 0; j < p->size; j++) {
            visited[i][j] = false;
        }
    }
    
    for (int col = 0; col < p->size; col++) {
        if (p->grid[0][col] == OPEN && !visited[0][col]) {
            if (dfs(p, 0, col, visited)) {
                for (int i = 0; i < p->size; i++) {
                    free(visited[i]);
                }
                free(visited);
                return true;
            }
        }
    }
    
    for (int i = 0; i < p->size; i++) {
        free(visited[i]);
    }
    free(visited);
    return false;
}

void free_percolation(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

void print_grid(Percolation *p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%d ", p->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int size = 10;
    Percolation *p = create_percolation(size);
    
    // Randomly open cells
    for (int i = 0; i < size * size / 2; i++) {
        int row = rand() % size;
        int col = rand() % size;
        open_cell(p, row, col);
    }
    
    printf("Percolation grid:\n");
    print_grid(p);
    
    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free_percolation(p);
    return 0;
}