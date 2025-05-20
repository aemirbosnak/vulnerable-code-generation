//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point **grid;
    int width;
    int height;
} Grid;

Grid *create_grid(int width, int height) {
    Grid *grid = malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->grid = malloc(sizeof(Point *) * height);
    for (int i = 0; i < height; i++) {
        grid->grid[i] = malloc(sizeof(Point) * width);
    }
    return grid;
}

void destroy_grid(Grid *grid) {
    for (int i = 0; i < grid->height; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    free(grid);
}

void print_grid(Grid *grid) {
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            printf("%c", grid->grid[i][j].x == -1 ? '#' : '.');
        }
        printf("\n");
    }
}

int main() {
    // Create a grid
    Grid *grid = create_grid(10, 10);

    // Set some obstacles
    grid->grid[0][0].x = -1;
    grid->grid[0][1].x = -1;
    grid->grid[0][2].x = -1;
    grid->grid[1][0].x = -1;
    grid->grid[1][1].x = -1;
    grid->grid[1][2].x = -1;

    // Print the grid
    print_grid(grid);

    // Destroy the grid
    destroy_grid(grid);

    return 0;
}