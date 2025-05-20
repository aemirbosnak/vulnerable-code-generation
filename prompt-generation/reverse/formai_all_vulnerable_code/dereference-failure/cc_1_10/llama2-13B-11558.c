//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a cell in the grid
typedef struct {
    int x; // Position of the cell in the grid
    int y;
    int state; // 0 for dead, 1 for alive
} Cell;

// Function to create a 2D grid of cells
void createGrid(int size) {
    int i, j;
    Cell **grid = calloc(size, sizeof(Cell *));

    for (i = 0; i < size; i++) {
        grid[i] = calloc(size, sizeof(Cell));

        for (j = 0; j < size; j++) {
            grid[i][j].x = i * size / 10;
            grid[i][j].y = j * size / 10;
            grid[i][j].state = rand() % 2; // Initialize cells with a 50% chance of being alive
        }
    }
}

// Function to draw the grid
void drawGrid(Cell **grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (grid[i][j].state) {
                printf("|  %d |", i * size / 10 + j * size / 10);
            } else {
                printf("| %d |", i * size / 10 + j * size / 10);
            }
        }
        printf("\n");
    }
}

// Function to simulate the game of life
void simulate(Cell **grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            // Check the eight neighbors of the cell
            int aliveNeighbors = 0;
            if (grid[i][j].state && grid[i][j - 1].state) aliveNeighbors++; // Up
            if (grid[i][j].state && grid[i][j + 1].state) aliveNeighbors++; // Down
            if (grid[i][j].state && grid[i - 1][j].state) aliveNeighbors++; // Left
            if (grid[i][j].state && grid[i + 1][j].state) aliveNeighbors++; // Right
            if (aliveNeighbors == 2 || aliveNeighbors == 3) {
                grid[i][j].state = 1 - grid[i][j].state; // If the cell is alive and has 2 or 3 alive neighbors, keep it alive
            } else if (aliveNeighbors == 0 || aliveNeighbors == 4) {
                grid[i][j].state = 0; // If the cell is dead and has no alive neighbors, make it alive
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    int size = 10; // Size of the grid
    Cell **grid = calloc(size, sizeof(Cell *));
    createGrid(size);
    drawGrid(grid, size);

    for (int i = 0; i < 100; i++) {
        simulate(grid, size);
        drawGrid(grid, size);
        printf("Generation %d\n", i + 1);
    }

    return 0;
}