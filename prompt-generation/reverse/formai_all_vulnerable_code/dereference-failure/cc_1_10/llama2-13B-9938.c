//LLAMA2-13B DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the dimensions of the grid
const int GRID_SIZE = 10;
const int GRID_WIDTH = GRID_SIZE * 2;
const int GRID_HEIGHT = GRID_SIZE * 2;

// Define the color palette
#define COLOR_COUNT 5
#define COLOR_BLACK 0
#define COLOR_WHITE 1
#define COLOR_RED 2
#define COLOR_GREEN 3
#define COLOR_BLUE 4

// Define the grid data structure
typedef struct {
    int x, y;
    int color;
} grid_t;

// Define the grid drawing function
void draw_grid(grid_t *grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid_t *cell = &grid[i * size + j];
            if (cell->color == COLOR_BLACK) {
                printf(" ");
            } else {
                printf("%d", cell->color);
            }
        }
        printf("\n");
    }
}

// Define the grid drawing function with a border
void draw_grid_bordered(grid_t *grid, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid_t *cell = &grid[i * size + j];
            if (cell->color == COLOR_BLACK) {
                printf("X");
            } else {
                printf("%d", cell->color);
            }
        }
        printf("\n");
    }
}

// Define the grid filling function
void fill_grid(grid_t *grid, int size, int color) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            grid_t *cell = &grid[i * size + j];
            cell->color = color;
        }
    }
}

int main() {
    // Create a grid with 10x10 cells
    grid_t *grid = malloc(GRID_SIZE * GRID_SIZE * sizeof(grid_t));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i * GRID_SIZE + j].x = i * 2;
            grid[i * GRID_SIZE + j].y = j * 2;
            grid[i * GRID_SIZE + j].color = COLOR_BLACK;
        }
    }

    // Draw the grid
    draw_grid(grid, GRID_SIZE);

    // Fill the grid with a random color
    int color = rand() % COLOR_COUNT;
    fill_grid(grid, GRID_SIZE, color);

    // Draw the grid again
    draw_grid(grid, GRID_SIZE);

    // Draw the grid with a border
    draw_grid_bordered(grid, GRID_SIZE);

    free(grid);
    return 0;
}