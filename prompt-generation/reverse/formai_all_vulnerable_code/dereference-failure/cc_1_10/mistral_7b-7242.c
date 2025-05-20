//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SITE_COUNT 10
#define ROW_COUNT 10

bool **grid;
bool open[SITE_COUNT];
int open_count = 0;

void print_grid() {
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < SITE_COUNT; j++) {
            printf("%-5s", grid[i][j] ? "OPEN" : "BLOCKED");
        }
        printf("\n");
    }
}

void initialize_grid() {
    grid = calloc(ROW_COUNT, sizeof(bool *));

    for (int i = 0; i < ROW_COUNT; i++) {
        grid[i] = calloc(SITE_COUNT, sizeof(bool));

        for (int j = 0; j < SITE_COUNT; j++) {
            grid[i][j] = false;
        }
    }
}

bool is_valid_site(int row, int col) {
    return (row >= 0 && row < ROW_COUNT && col >= 0 && col < SITE_COUNT);
}

bool connect_to_top(int row, int col) {
    if (row == 0) {
        open[open_count++] = col;
        grid[row][col] = true;
        return true;
    }

    if (grid[row - 1][col]) {
        open[open_count++] = col;
        grid[row][col] = true;
        return true;
    }

    return false;
}

bool percolate() {
    for (int i = 0; i < SITE_COUNT; i++) {
        if (!grid[ROW_COUNT - 1][i]) {
            if (connect_to_top(ROW_COUNT - 1, i)) {
                return true;
            }
        }
    }

    return false;
}

void random_site() {
    int row = rand() % ROW_COUNT;
    int col = rand() % SITE_COUNT;

    if (is_valid_site(row, col)) {
        grid[row][col] = true;
        open[open_count++] = col;
    }
    else {
        random_site();
    }
}

void simulate(int num_sites) {
    initialize_grid();

    for (int i = 0; i < num_sites; i++) {
        random_site();
        if (percolate()) {
            break;
        }
    }

    print_grid();
}

int main() {
    srand(time(NULL));

    int num_sites = ROW_COUNT * SITE_COUNT / 2;

    simulate(num_sites);

    for (int i = 0; i < open_count; i++) {
        free(grid[i / SITE_COUNT]);
    }
    free(grid);

    return 0;
}