//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10

// A structure for a single cell in the grid
typedef struct {
    int x, y;       // position of the cell
    int f, g, h;    // A* algorithm values
    struct Cell* parent;    // parent cell
} Cell;

// A structure for the grid
typedef struct {
    int width, height;
    Cell* cells;
} Grid;

// Function to calculate Manhattan distance between two cells
int manhattan(Cell* a, Cell* b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

// Function to find the cell with the lowest f value
Cell* lowest_f(Grid* grid) {
    int i, min_f = 99999;
    Cell* result = NULL;
    for (i = 0; i < grid->width * grid->height; i++) {
        int f = grid->cells[i].f;
        if (f < min_f) {
            min_f = f;
            result = &grid->cells[i];
        }
    }
    return result;
}

// Function to get a cell from x and y coordinates
Cell* get_cell(Grid* grid, int x, int y) {
    if (x < 0 || x >= grid->width || y < 0 || y >= grid->height) {
        return NULL;
    }
    return &grid->cells[y * grid->width + x];
}

// Function to get the neighbors of a cell
Cell** get_neighbors(Grid* grid, Cell* cell) {
    Cell** neighbors = malloc(sizeof(Cell*) * 8);
    int count = 0, i, j;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            Cell* neighbor = get_cell(grid, cell->x + i, cell->y + j);
            if (neighbor != NULL) {
                neighbors[count] = neighbor;
                count++;
            }
        }
    }
    return neighbors;
}

// A* algorithm implementation
void a_star(Grid* grid, Cell* start, Cell* end) {
    int i, j;
    for (i = 0; i < grid->width * grid->height; i++) {
        grid->cells[i].f = 99999;
        grid->cells[i].g = 99999;
        grid->cells[i].h = 99999;
        grid->cells[i].parent = NULL;
    }
    start->g = 0;
    start->h = manhattan(start, end);
    start->f = start->g + start->h;
    Cell* current = start;
    while (current != end) {
        Cell** neighbors = get_neighbors(grid, current);
        for (i = 0; i < 8; i++) {
            Cell* neighbor = neighbors[i];
            if (neighbor == NULL) {
                continue;
            }
            int new_g = current->g + manhattan(current, neighbor);
            if (new_g < neighbor->g) {
                neighbor->parent = current;
                neighbor->g = new_g;
                neighbor->h = manhattan(neighbor, end);
                neighbor->f = neighbor->g + neighbor->h;
            }
        }
        current = lowest_f(grid);
        if (current == NULL) {
            break;
        }
    }
}

// Function to print the path from start to end
void print_path(Grid* grid, Cell* start, Cell* end) {
    Cell* current = end;
    while (current != start) {
        printf("(%d,%d) -> ", current->x, current->y);
        current = current->parent;
    }
    printf("(%d,%d)\n", start->x, start->y);
}

// Main function to test the A* algorithm
int main() {
    Grid grid = {WIDTH, HEIGHT, malloc(sizeof(Cell) * WIDTH * HEIGHT)};
    int i, j;
    for (i = 0; i < grid.width; i++) {
        for (j = 0; j < grid.height; j++) {
            grid.cells[j * grid.width + i].x = i;
            grid.cells[j * grid.width + i].y = j;
        }
    }
    Cell* start = get_cell(&grid, 0, 0);
    Cell* end = get_cell(&grid, 9, 9);
    a_star(&grid, start, end);
    print_path(&grid, start, end);
    return 0;
}