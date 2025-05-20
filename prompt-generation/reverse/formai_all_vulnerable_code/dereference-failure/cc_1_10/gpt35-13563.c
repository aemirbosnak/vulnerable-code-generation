//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int row;
    int col;
} Square;

int parent(int i, int j, int n) {
    return i * n + j;
}

bool valid(int i, int j, int n) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

int *initialize(int n) {
    int *id = malloc(n * n * sizeof(int));
    for (int i = 0; i < n * n; i++) {
        id[i] = i;
    }
    return id;
}

void print_grid(Square g[ROWS][COLS], int id[ROWS][COLS], int n) {
    printf("    ");
    for (int i = 0; i < n; i++) {
        printf("%02d ", i);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%02d: ", i);
        for (int j = 0; j < n; j++) {
            printf("%02d ", id[g[i][j].row][g[i][j].col]);
        }
        printf("\n");
    }
}

void unionize(Square g[ROWS][COLS], int id[ROWS][COLS], int n, int i, int j) {
    if (valid(i-1, j, n) && id[g[i-1][j].row][g[i-1][j].col] != id[g[i][j].row][g[i][j].col]) {
        int old_pid = id[g[i-1][j].row][g[i-1][j].col];
        int new_pid = id[g[i][j].row][g[i][j].col];
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (id[x][y] == old_pid) {
                    id[x][y] = new_pid;
                }
            }
        }
    }
    if (valid(i, j-1, n) && id[g[i][j-1].row][g[i][j-1].col] != id[g[i][j].row][g[i][j].col]) {
        int old_pid = id[g[i][j-1].row][g[i][j-1].col];
        int new_pid = id[g[i][j].row][g[i][j].col];
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (id[x][y] == old_pid) {
                    id[x][y] = new_pid;
                }
            }
        }
    }
    if (valid(i+1, j, n) && id[g[i+1][j].row][g[i+1][j].col] != id[g[i][j].row][g[i][j].col]) {
        int old_pid = id[g[i+1][j].row][g[i+1][j].col];
        int new_pid = id[g[i][j].row][g[i][j].col];
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (id[x][y] == old_pid) {
                    id[x][y] = new_pid;
                }
            }
        }
    }
    if (valid(i, j+1, n) && id[g[i][j+1].row][g[i][j+1].col] != id[g[i][j].row][g[i][j].col]) {
        int old_pid = id[g[i][j+1].row][g[i][j+1].col];
        int new_pid = id[g[i][j].row][g[i][j].col];
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (id[x][y] == old_pid) {
                    id[x][y] = new_pid;
                }
            }
        }
    }
}

bool percolates(int id[ROWS][COLS], int n) {
    for (int j = 0; j < n; j++) {
        if (id[0][j] == id[n-1][j]) {
            return true;
        }
    }
    return false;
}

int main() {
    // initialize grid
    Square grid[ROWS][COLS];
    int k = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            k++;
        }
    }
    
    // initialize id array
    int *id = initialize(ROWS);
    
    // print initial grid
    print_grid(grid, id, ROWS);
    printf("\n");
    
    // unionize random squares
    srand(time(NULL));
    for (int i = 0; i < ROWS * COLS; i++) {
        int random_index = rand() % (ROWS * COLS - i) + i;
        int row1 = parent(grid[i/ROWS][i%COLS].row, grid[i/ROWS][i%COLS].col, ROWS);
        int row2 = parent(grid[random_index/ROWS][random_index%COLS].row, grid[random_index/ROWS][random_index%COLS].col, ROWS);
        int tmp = id[row1];
        id[row1] = id[row2];
        id[row2] = tmp;
    }
    
    // print final grid
    print_grid(grid, id, ROWS);
    printf("\nPercolates: %d\n", percolates(id, ROWS));
    
    // free memory
    free(id);
    
    return 0;
}