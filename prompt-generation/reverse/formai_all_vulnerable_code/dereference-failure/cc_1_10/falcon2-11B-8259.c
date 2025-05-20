//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int value;
} Cell;

typedef struct {
    int width;
    int height;
    Cell** cells;
} Grid;

Grid* createGrid(int width, int height) {
    Grid* grid = (Grid*)malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->cells = (Cell**)malloc(width * sizeof(Cell*));
    for (int i = 0; i < width; i++) {
        grid->cells[i] = (Cell*)malloc(height * sizeof(Cell));
        for (int j = 0; j < height; j++) {
            grid->cells[i][j].x = i;
            grid->cells[i][j].y = j;
            grid->cells[i][j].value = 0;
        }
    }
    return grid;
}

void setCellValue(Grid* grid, int x, int y, int value) {
    grid->cells[x][y].value = value;
}

void printGrid(Grid* grid) {
    for (int i = 0; i < grid->width; i++) {
        for (int j = 0; j < grid->height; j++) {
            printf("%d ", grid->cells[i][j].value);
        }
        printf("\n");
    }
}

int percolate(Grid* grid, int x, int y) {
    int neighbors = 0;
    if (x > 0 && y > 0 && grid->cells[x - 1][y - 1].value == 1) {
        neighbors++;
    }
    if (x > 0 && grid->cells[x - 1][y].value == 1) {
        neighbors++;
    }
    if (x > 0 && y < grid->height - 1 && grid->cells[x - 1][y + 1].value == 1) {
        neighbors++;
    }
    if (y > 0 && grid->cells[x][y - 1].value == 1) {
        neighbors++;
    }
    if (y < grid->height - 1 && grid->cells[x][y + 1].value == 1) {
        neighbors++;
    }
    if (x < grid->width - 1 && y > 0 && grid->cells[x + 1][y - 1].value == 1) {
        neighbors++;
    }
    if (x < grid->width - 1 && grid->cells[x + 1][y].value == 1) {
        neighbors++;
    }
    if (x < grid->width - 1 && y < grid->height - 1 && grid->cells[x + 1][y + 1].value == 1) {
        neighbors++;
    }
    if (neighbors == 4) {
        return 1;
    } else {
        return 0;
    }
}

void simulatePercolation(Grid* grid) {
    int width = grid->width;
    int height = grid->height;
    int cells = width * height;
    int randomIndex = rand() % cells;
    int x = randomIndex / height;
    int y = randomIndex % height;
    setCellValue(grid, x, y, 1);
    int currentCount = 1;
    int nextCount = 0;
    int iterations = 0;
    while (nextCount!= currentCount) {
        currentCount = nextCount;
        nextCount = 0;
        for (int i = 0; i < cells; i++) {
            x = i / height;
            y = i % height;
            if (percolate(grid, x, y) == 1) {
                nextCount++;
            }
        }
        iterations++;
    }
    printf("Iterations: %d\n", iterations);
}

int main() {
    int width = 10;
    int height = 10;
    Grid* grid = createGrid(width, height);
    simulatePercolation(grid);
    printGrid(grid);
    free(grid->cells);
    free(grid);
    return 0;
}