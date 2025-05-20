//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20 // Size of the grid
#define OPEN 1
#define BLOCKED 0

typedef struct {
    int **grid;     // Grid representation
    int size;       // Size of the grid
    int num_open;   // Number of open sites
} Percolation;

Percolation* create_percolation(int size) {
    Percolation* p = (Percolation*)malloc(sizeof(Percolation));
    p->size = size;
    p->num_open = 0;

    // Allocate memory for the grid
    p->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        p->grid[i] = (int*)malloc(size * sizeof(int));
    }

    // Initialize the grid with blocked sites
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            p->grid[i][j] = BLOCKED;
        }
    }

    return p;
}

void free_percolation(Percolation* p) {
    for (int i = 0; i < p->size; i++) {
        free(p->grid[i]);
    }
    free(p->grid);
    free(p);
}

void open_site(Percolation* p, int x, int y) {
    if (x >= 0 && x < p->size && y >= 0 && y < p->size && p->grid[x][y] == BLOCKED) {
        p->grid[x][y] = OPEN;
        p->num_open++;
    }
}

int is_open(Percolation* p, int x, int y) {
    return (x >= 0 && x < p->size && y >= 0 && y < p->size) ? p->grid[x][y] : BLOCKED;
}

int check_percolation(Percolation* p) {
    // Simple BFS to check if percolation occurs
    int **visited = (int**)malloc(p->size * sizeof(int*));
    for (int i = 0; i < p->size; i++) {
        visited[i] = (int*)malloc(p->size * sizeof(int));
        for (int j = 0; j < p->size; j++) {
            visited[i][j] = 0;
        }
    }
    
    // Queue for BFS
    int queue[GRID_SIZE * GRID_SIZE][2];
    int front = 0, rear = 0;

    // Initialize queue with open sites in the first row
    for (int j = 0; j < p->size; j++) {
        if (is_open(p, 0, j)) {
            queue[rear][0] = 0;
            queue[rear++][1] = j;
            visited[0][j] = 1;
        }
    }

    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front++][1];

        // Check if we reached the last row
        if (x == p->size - 1) {
            for (int i = 0; i < p->size; i++) {
                free(visited[i]);
            }
            free(visited);
            return 1;
        }

        // Explore neighbors
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            
            if (is_open(p, nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                queue[rear][0] = nx;
                queue[rear++][1] = ny;
            }
        }
    }

    for (int i = 0; i < p->size; i++) {
        free(visited[i]);
    }
    free(visited);
    return 0;
}

void display_grid(Percolation* p) {
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            printf("%c ", p->grid[i][j] == OPEN ? '.' : '#');
        }
        printf("\n");
    }
}

void random_open_sites(Percolation* p, float probability) {
    srand(time(NULL));
    for (int i = 0; i < p->size; i++) {
        for (int j = 0; j < p->size; j++) {
            if ((float)rand() / RAND_MAX < probability) {
                open_site(p, i, j);
            }
        }
    }
}

int main() {
    Percolation* p = create_percolation(GRID_SIZE);
    random_open_sites(p, 0.5); // Open sites with 50% probability
    printf("Grid:\n");
    display_grid(p);

    if (check_percolation(p)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free_percolation(p);
    return 0;
}