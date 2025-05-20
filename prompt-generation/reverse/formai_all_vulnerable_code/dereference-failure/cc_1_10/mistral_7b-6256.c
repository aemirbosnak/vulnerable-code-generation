//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int width, height;
    bool **grid;
} board;

void init_board(board *b, int w, int h) {
    b->width = w;
    b->height = h;
    b->grid = malloc(h * sizeof(bool *));

    for (int i = 0; i < h; ++i) {
        b->grid[i] = calloc(w, sizeof(bool));
    }
}

bool in_bounds(board b, int x, int y) {
    return x >= 0 && x < b.width && y >= 0 && y < b.height;
}

bool is_open(board b, int x, int y) {
    if (!in_bounds(b, x, y)) {
        return false;
    }

    return b.grid[y][x];
}

void flood_fill(board b, int x, int y) {
    if (!is_open(b, x, y)) {
        return;
    }

    b.grid[y][x] = false;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) {
                continue;
            }

            int nx = x + dx, ny = y + dy;

            if (in_bounds(b, nx, ny) && is_open(b, nx, ny)) {
                flood_fill(b, nx, ny);
            }
        }
    }
}

void print_board(board b) {
    for (int y = 0; y < b.height; ++y) {
        for (int x = 0; x < b.width; ++x) {
            printf("%s", is_open(b, x, y) ? " ○" : " ●");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int width = 13, height = 13;
    board b;
    init_board(&b, width, height);

    printf("Initial board:\n");
    print_board(b);

    int oxs = rand() % width, oys = rand() % height;
    flood_fill(b, oxs, oys);

    printf("\nBoard after flood fill from (%d, %d):\n", oxs, oys);
    print_board(b);

    free(b.grid);

    return 0;
}