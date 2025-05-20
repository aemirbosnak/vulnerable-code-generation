//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH  10
#define HEIGHT 10

typedef struct {
    int x, y;
} Point;

typedef bool **Grid;

void init_grid(Grid grid) {
    int i;

    for (i = 0; i < HEIGHT; i++)
        grid[i] = calloc(WIDTH, sizeof(bool));
}

bool is_valid(int x, int y, Grid grid) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT
        && grid[y][x] == false;
}

void drop_water(Point source, Grid grid) {
    int dx[4] = {1, 1, 1, 0};
    int dy[4] = {1, 0, -1, -1};
    int i;

    grid[source.y][source.x] = true;

    for (i = 0; i < 4; i++) {
        Point next = {source.x + dx[i], source.y + dy[i]};
        if (is_valid(next.x, next.y, grid)) {
            grid[next.y][next.x] = true;
            drop_water(next, grid);
        }
    }
}

void print_grid(Grid grid) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++)
            printf(grid[i][j] ? "#" : ".");
        printf("\n");
    }
}

bool percolates(Grid grid) {
    bool top = false;
    bool bottom = false;

    for (int i = 0; i < WIDTH; i++) {
        top |= grid[0][i];
        bottom |= grid[HEIGHT - 1][i];
    }

    return top && bottom;
}

int main(void) {
    Grid grid;
    int x, y;
    Point source;

    srand(time(NULL));

    init_grid(grid);

    do {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
    } while (grid[y][x]);

    source.x = x;
    source.y = y;

    printf("Initial state:\n");
    print_grid(grid);

    drop_water(source, grid);

    printf("Final state (%d, %d) dropped:\n", source.x, source.y);
    print_grid(grid);

    printf("Does the grid percolate? %s\n", percolates(grid) ? "Yes" : "No");

    for (int i = 0; i < HEIGHT; i++)
        free(grid[i]);
    free(grid);

    return EXIT_SUCCESS;
}