//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EMPTY 0
#define BLOCKED 1
#define OPEN 2

typedef struct {
    int **grid;
    int size;
} Percolation;

Percolation* create_percolation(int size) {
    Percolation *p = (Percolation *)malloc(sizeof(Percolation));
    p->size = size;
    p->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        p->grid[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = EMPTY; // Initialize as empty
        }
    }
    return p;
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
            if (p->grid[i][j] == EMPTY) printf(".");
            else if (p->grid[i][j] == BLOCKED) printf("#");
            else printf("O");
        }
        printf("\n");
    }
}

void random_fill(Percolation *p, double density) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if ((double)rand() / RAND_MAX < density) {
                p->grid[i][j] = BLOCKED;
            } else {
                p->grid[i][j] = EMPTY;
            }
        }
    }
}

int is_open(Percolation *p, int row, int col) {
    return (row >= 0 && row < p->size && col >= 0 && col < p->size && p->grid[row][col] == EMPTY);
}

int percolates(Percolation *p) {
    int *visited = (int *)calloc(p->size * p->size, sizeof(int));
    int stack[p->size * p->size][2]; // Stack for DFS
    int top = -1;

    // Push all open sites in the first row onto the stack
    for (int j = 0; j < p->size; j++) {
        if (p->grid[0][j] == EMPTY) {
            stack[++top][0] = 0;
            stack[top][1] = j;
            visited[j] = 1;
        }
    }

    // Perform DFS
    while (top != -1) {
        int row = stack[top][0];
        int col = stack[top][1];
        top--;

        if (row == p->size - 1) {
            free(visited);
            return 1; // Found a path to the last row
        }

        // Check all 4 directions
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int d = 0; d < 4; d++) {
            int new_row = row + directions[d][0];
            int new_col = col + directions[d][1];
            int idx = new_row * p->size + new_col;

            if (is_open(p, new_row, new_col) && visited[idx] == 0) {
                stack[++top][0] = new_row;
                stack[top][1] = new_col;
                visited[idx] = 1;
            }
        }
    }
    
    free(visited);
    return 0; // No path found
}

int main() {
    srand(time(NULL));
    int size;
    double density;
    
    printf("Enter grid size (e.g., 10): ");
    scanf("%d", &size);

    printf("Enter fill density (between 0 and 1): ");
    scanf("%lf", &density);

    Percolation *p = create_percolation(size);
    
    random_fill(p, density);
    
    printf("Initial grid:\n");
    print_grid(p);
    
    if (percolates(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free_percolation(p);
    return 0;
}