//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // Size of the grid
#define OPEN 1 // Represent an open site
#define BLOCKED 0 // Represent a blocked site

typedef struct {
    int grid[SIZE][SIZE];
    int visited[SIZE][SIZE];
    int size;
} Percolation;

// Function prototypes
Percolation* create_percolation(int size);
void initialize_grid(Percolation* perc);
void display_grid(Percolation* perc);
void open_site(Percolation* perc, int x, int y);
int is_open(Percolation* perc, int x, int y);
int percolates(Percolation* perc);
void perform_dfs(Percolation* perc, int x, int y);

int main() {
    srand(time(0));
    Percolation* perc = create_percolation(SIZE);

    int num_open_sites = (SIZE * SIZE) / 2; // Open half of the sites randomly
    for (int i = 0; i < num_open_sites; i++) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        open_site(perc, x, y);
    }

    printf("Percolation grid:\n");
    display_grid(perc);

    if (percolates(perc)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    free(perc);
    return 0;
}

Percolation* create_percolation(int size) {
    Percolation* perc = (Percolation*)malloc(sizeof(Percolation));
    perc->size = size;
    initialize_grid(perc);
    return perc;
}

void initialize_grid(Percolation* perc) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            perc->grid[i][j] = BLOCKED; // Start with all blocked
            perc->visited[i][j] = 0; // Start with all unvisited
        }
    }
}

void display_grid(Percolation* perc) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (perc->grid[i][j] == OPEN)
                printf(" O ");
            else
                printf(" X ");
        }
        printf("\n");
    }
}

void open_site(Percolation* perc, int x, int y) {
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
        perc->grid[x][y] = OPEN; // Open the site
    }
}

int is_open(Percolation* perc, int x, int y) {
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && perc->grid[x][y] == OPEN);
}

void perform_dfs(Percolation* perc, int x, int y) {
    // Mark the site as visited
    perc->visited[x][y] = 1;

    // Explore neighbors (up, down, left, right)
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        int new_x = x + direction[i][0];
        int new_y = y + direction[i][1];
        if (is_open(perc, new_x, new_y) && !perc->visited[new_x][new_y]) {
            perform_dfs(perc, new_x, new_y);
        }
    }
}

int percolates(Percolation* perc) {
    // Check if there's a path from the top row to the bottom row
    for (int j = 0; j < SIZE; j++) {
        if (is_open(perc, 0, j) && !perc->visited[0][j]) {
            perform_dfs(perc, 0, j);
        }
    }

    // Check if we visited any site in the bottom row
    for (int j = 0; j < SIZE; j++) {
        if (perc->visited[SIZE - 1][j]) {
            return 1; // Percolates
        }
    }
    return 0; // Does not percolate
}