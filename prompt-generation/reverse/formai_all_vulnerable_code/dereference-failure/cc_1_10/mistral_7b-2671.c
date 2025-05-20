//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define SITES_COUNT (WIDTH * HEIGHT)

typedef struct {
    int x, y;
} point_t;

typedef struct {
    int sites_count;
    bool **grid;
} percolation_t;

void print_grid(percolation_t *percolation) {
    int i;
    for (i = 0; i < HEIGHT; i++) {
        int j;
        for (j = 0; j < WIDTH; j++) {
            printf(percolation->grid[i][j] ? "#" : ".");
        }
        printf("\n");
    }
}

void fill_randomly(percolation_t *percolation) {
    int filled_sites = 0;
    while (filled_sites < SITES_COUNT / 2) {
        point_t p;
        p.x = rand() % WIDTH;
        p.y = rand() % HEIGHT;
        if (!percolation->grid[p.y][p.x]) {
            percolation->grid[p.y][p.x] = true;
            filled_sites++;
        }
    }
}

bool is_valid_neighbor(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}

bool percolate(percolation_t *percolation, point_t p) {
    if (!percolation->grid[p.y][p.x]) {
        return false;
    }

    percolation->grid[p.y][p.x] = false;

    int dx[4] = {1, 1, -1, -1};
    int dy[4] = {1, -1, 1, -1};

    int i;
    for (i = 0; i < 4; i++) {
        int nx = p.x + dx[i];
        int ny = p.y + dy[i];
        if (is_valid_neighbor(nx, ny) && percolation->grid[ny][nx]) {
            percolate(percolation, (point_t) {nx, ny});
        }
    }

    return true;
}

bool simulate(percolation_t *percolation) {
    point_t p;

    while (true) {
        fill_randomly(percolation);

        if (percolate(percolation, (point_t) {0, 0})) {
            print_grid(percolation);
            printf("Percolation occurred!\n");
            return true;
        }
    }

    return false;
}

int main() {
    srand(time(NULL));

    percolation_t percolation = {SITES_COUNT, calloc(HEIGHT, sizeof(bool *))};
    for (int i = 0; i < HEIGHT; i++) {
        percolation.grid[i] = calloc(WIDTH, sizeof(bool));
    }

    simulate(&percolation);

    for (int i = 0; i < HEIGHT; i++) {
        free(percolation.grid[i]);
    }
    free(percolation.grid);

    return 0;
}