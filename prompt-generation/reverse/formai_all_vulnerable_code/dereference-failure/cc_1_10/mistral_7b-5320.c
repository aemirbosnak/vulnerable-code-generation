//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10
#define SITES 100

typedef struct {
    int x, y;
} Point;

bool **grid;
Point openSites[SITES];

void print_grid() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

bool site_is_open(int x, int y) {
    return grid[x][y] == 0;
}

bool is_valid_site(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

int num_neighbors(int x, int y) {
    int num = 0;
    if (site_is_open(x - 1, y)) num++;
    if (site_is_open(x + 1, y)) num++;
    if (site_is_open(x, y - 1)) num++;
    if (site_is_open(x, y + 1)) num++;
    if (site_is_open(x - 1, y - 1)) num++;
    if (site_is_open(x - 1, y + 1)) num++;
    if (site_is_open(x + 1, y - 1)) num++;
    if (site_is_open(x + 1, y + 1)) num++;
    return num;
}

void pick_site() {
    int i;
    Point site;
    int min_dist = SIZE * SIZE;

    for (i = 0; i < SITES; i++) {
        site = openSites[i];
        if (num_neighbors(site.x, site.y) < min_dist) {
            min_dist = num_neighbors(site.x, site.y);
            grid[site.x][site.y] = 1;
        }
    }
}

void fill_open_sites() {
    int i, j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            openSites[i * SIZE + j] = (Point) {i, j};
        }
    }
}

int main() {
    int i;

    srand(time(NULL));
    grid = malloc(SIZE * sizeof(bool *));

    for (i = 0; i < SIZE; i++) {
        grid[i] = calloc(SIZE, sizeof(bool));
    }

    fill_open_sites();

    for (i = 0; i < 1000; i++) {
        pick_site();
        print_grid();
        printf("\n");
    }

    free(grid);
    return 0;
}