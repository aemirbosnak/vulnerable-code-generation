//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_DROPS 100000

typedef struct {
    int x, y;
} Point;

typedef struct {
    int size;
    Point *points;
} Grid;

void init_grid(Grid *grid, int size) {
    grid->size = size;
    grid->points = malloc(size * sizeof(Point));
}

void free_grid(Grid *grid) {
    free(grid->points);
}

void connect(Grid *grid, int x, int y, int dx, int dy) {
    if (dx == 0 && dy == 0)
        return;

    int nx = x + dx, ny = y + dy;

    if (nx >= 0 && nx < grid->size && ny >= 0 && ny < grid->size) {
        Point p = {nx, ny};
        grid->points[ny * grid->size + nx] = p;
    }
}

int count_neighbors(Grid *grid, int x, int y) {
    int count = 0;

    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (i!= 0 || j!= 0)
                count += grid->points[y * grid->size + x + i * grid->size + j].x;

    return count;
}

void percolate(Grid *grid, int x, int y) {
    grid->points[y * grid->size + x].x = 1;

    for (int i = -1; i <= 1; i++)
        for (int j = -1; j <= 1; j++)
            if (i!= 0 || j!= 0) {
                int nx = x + i, ny = y + j;

                if (nx >= 0 && nx < grid->size && ny >= 0 && ny < grid->size &&
                    grid->points[ny * grid->size + nx].x == 0) {
                    Point p = {nx, ny};
                    connect(grid, x, y, i, j);
                    percolate(grid, nx, ny);
                }
            }
}

void simulate(Grid *grid, int num_drops) {
    srand(time(NULL));

    for (int i = 0; i < num_drops; i++) {
        int x = rand() % grid->size, y = rand() % grid->size;

        if (grid->points[y * grid->size + x].x == 0) {
            grid->points[y * grid->size + x].x = 1;
            percolate(grid, x, y);
        }
    }
}

void print_grid(Grid *grid) {
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            if (grid->points[j * grid->size + i].x == 1)
                printf("#");
            else
                printf(".");
        }
        printf("\n");
    }
}

int main() {
    Grid grid;
    init_grid(&grid, MAX_SIZE);

    int num_drops = MAX_DROPS;

    simulate(&grid, num_drops);

    print_grid(&grid);

    free_grid(&grid);

    return 0;
}