//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 0   // Represents an empty site
#define F 1   // Represents a filled site

typedef struct {
    int size;
    int** grid;
} Percolation;

Percolation* create_percolation(int size) {
    Percolation* perc = (Percolation*)malloc(sizeof(Percolation));
    perc->size = size;
    perc->grid = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        perc->grid[i] = (int*)calloc(size, sizeof(int));
    }
    return perc;
}

void free_percolation(Percolation* perc) {
    for (int i = 0; i < perc->size; i++) {
        free(perc->grid[i]);
    }
    free(perc->grid);
    free(perc);
}

void print_grid(Percolation* perc) {
    for (int i = 0; i < perc->size; i++) {
        for (int j = 0; j < perc->size; j++) {
            printf("%d ", perc->grid[i][j]);
        }
        printf("\n");
    }
}

void fill_site(Percolation* perc, int x, int y) {
    if (x < 0 || x >= perc->size || y < 0 || y >= perc->size) {
        return;  // Out of bounds
    }
    if (perc->grid[x][y] == F) {
        return;  // Already filled
    }
    perc->grid[x][y] = F;  // Fill the site
}

void random_fill(Percolation* perc, float probability) {
    for (int i = 0; i < perc->size; i++) {
        for (int j = 0; j < perc->size; j++) {
            if ((float)rand() / RAND_MAX < probability) {
                fill_site(perc, i, j);
            }
        }
    }
}

int is_connected(int** parent, int i, int j) {
    // Union-Find checking mechanism here
    while (parent[i][j] != -1) {
        j = parent[i][j];
    }
    return j;
}

int percolates(Percolation* perc) {
    int size = perc->size;
    
    // Create Union-Find structure
    int** parent = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        parent[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            parent[i][j] = -1;
        }
    }

    // Connect filled sites
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (perc->grid[i][j] == F) {
                // Check if it connects to top row
                if (i == 0) {
                    parent[i][j] = -1;  // Connected to the top
                }
                // Connect to left
                if (j > 0 && perc->grid[i][j - 1] == F) {
                    parent[i][j] = j - 1;
                }
                // Connect to above
                if (i > 0 && perc->grid[i - 1][j] == F) {
                    parent[i][j] = is_connected(parent, i - 1, j);
                }
            }
        }
    }

    // Check for connection to the bottom row
    for (int j = 0; j < size; j++) {
        if (perc->grid[size - 1][j] == F) {
            if (is_connected(parent, size - 1, j) == -1) {
                for (int i = 0; i < size; i++) {
                    free(parent[i]);
                }
                free(parent);
                return 1;  // Percolates
            }
        }
    }

    for (int i = 0; i < size; i++) {
        free(parent[i]);
    }
    free(parent);
    return 0;  // Does not percolate
}

int main() {
    srand(time(NULL));
    
    int grid_size;
    float fill_probability;
    
    printf("Enter grid size: ");
    scanf("%d", &grid_size);
    printf("Enter probability of filling sites (0.0 to 1.0): ");
    scanf("%f", &fill_probability);
    
    Percolation* perc = create_percolation(grid_size);
    
    random_fill(perc, fill_probability);
    
    printf("Generated grid:\n");
    print_grid(perc);
    
    if (percolates(perc)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    
    free_percolation(perc);
    return 0;
}