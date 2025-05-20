//GPT-4o-mini DATASET v1.0 Category: Percolation Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEFAULT_SIZE 10
#define DEFAULT_PROBABILITY 50

typedef struct {
    int size;
    float probability;
    int **grid;
    int **visited;
} Percolation;

void initializePercolation(Percolation *perc, int size, float probability) {
    perc->size = size;
    perc->probability = probability;
    perc->grid = (int **)malloc(size * sizeof(int *));
    perc->visited = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        perc->grid[i] = (int *)malloc(size * sizeof(int));
        perc->visited[i] = (int *)calloc(size, sizeof(int));
    }
}

void freePercolation(Percolation *perc) {
    for (int i = 0; i < perc->size; i++) {
        free(perc->grid[i]);
        free(perc->visited[i]);
    }
    free(perc->grid);
    free(perc->visited);
}

void generateGrid(Percolation *perc) {
    srand(time(0));
    for (int i = 0; i < perc->size; i++) {
        for (int j = 0; j < perc->size; j++) {
            int randomValue = rand() % 100;
            perc->grid[i][j] = (randomValue < perc->probability) ? 1 : 0;
        }
    }
}

void printGrid(Percolation *perc) {
    printf("Percolation Grid (%d x %d) with probability %.2f:\n", perc->size, perc->size, perc->probability);
    for (int i = 0; i < perc->size; i++) {
        for (int j = 0; j < perc->size; j++) {
            printf("%d ", perc->grid[i][j]);
        }
        printf("\n");
    }
}

int isValid(int x, int y, Percolation *perc) {
    return (x >= 0 && x < perc->size && y >= 0 && y < perc->size);
}

int dfs(int x, int y, Percolation *perc) {
    if (x == perc->size - 1) { // Reached the bottom row
        return 1;
    }
    perc->visited[x][y] = 1; // Mark as visited

    int directions[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (isValid(newX, newY, perc) && perc->grid[newX][newY] == 1 && !perc->visited[newX][newY]) {
            if (dfs(newX, newY, perc)) {
                return 1; // Path found to bottom row
            }
        }
    }
    return 0; // No path to the bottom row
}

int doesPercolate(Percolation *perc) {
    for (int j = 0; j < perc->size; j++) {
        if (perc->grid[0][j] == 1 && !perc->visited[0][j]) {
            if (dfs(0, j, perc)) {
                return 1; // Percolates
            }
        }
    }
    return 0; // Does not percolate
}

int main(int argc, char *argv[]) {
    int size = (argc > 1) ? atoi(argv[1]) : DEFAULT_SIZE;
    float probability = (argc > 2) ? atof(argv[2]) : DEFAULT_PROBABILITY;

    Percolation perc;
    initializePercolation(&perc, size, probability);
    generateGrid(&perc);
    printGrid(&perc);

    if (doesPercolate(&perc)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    freePercolation(&perc);
    return 0;
}