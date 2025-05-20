//Falcon2-11B DATASET v1.0 Category: Percolation Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct {
    int x;
    int y;
} Coord;

typedef struct {
    int is_water;
    int is_wet;
} Cell;

typedef struct {
    int x;
    int y;
    Cell* cells;
} Grid;

Grid create_grid() {
    Grid grid;
    grid.x = WIDTH;
    grid.y = HEIGHT;
    grid.cells = (Cell*)malloc(grid.x * grid.y * sizeof(Cell));
    return grid;
}

void fill_grid(Grid* grid) {
    for (int i = 0; i < grid->x; i++) {
        for (int j = 0; j < grid->y; j++) {
            grid->cells[i * grid->y + j].is_water = 0;
            grid->cells[i * grid->y + j].is_wet = 0;
        }
    }
}

void print_grid(Grid grid) {
    for (int i = 0; i < grid.x; i++) {
        for (int j = 0; j < grid.y; j++) {
            if (grid.cells[i * grid.y + j].is_water)
                printf("W\t");
            else
                printf(".\t");
        }
        printf("\n");
    }
}

void simulate_percolation(Grid* grid) {
    srand(time(NULL));

    for (int i = 0; i < 1000; i++) {
        int x = rand() % grid->x;
        int y = rand() % grid->y;

        if (grid->cells[x * grid->y + y].is_wet == 0) {
            grid->cells[x * grid->y + y].is_water = 1;
            grid->cells[x * grid->y + y].is_wet = 1;

            for (int d = -1; d <= 1; d++) {
                if (x + d >= 0 && x + d < grid->x && y + d >= 0 && y + d < grid->y) {
                    int dx = x + d;
                    int dy = y + d;

                    if (grid->cells[dx * grid->y + dy].is_wet == 0) {
                        grid->cells[dx * grid->y + dy].is_wet = 1;
                    }
                }
            }
        }
    }
}

int main() {
    Grid grid = create_grid();
    fill_grid(&grid);
    simulate_percolation(&grid);
    print_grid(grid);
    return 0;
}