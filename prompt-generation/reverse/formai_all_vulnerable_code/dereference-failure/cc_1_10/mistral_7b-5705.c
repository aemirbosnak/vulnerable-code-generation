//MISTRAL-7B DATASET v1.0 Category: Game of Life ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#define WIDTH 40
#define HEIGHT 22

typedef struct Cell {
    int x, y;
    bool alive;
    struct Cell *next;
} Cell;

Cell *grid = NULL;
int neighbors_alive(int x, int y) {
    int count = 0;
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) continue;
            int idx = (i < 0 ? WIDTH + i : i) * HEIGHT + (j < 0 ? j + HEIGHT : j);
            if (grid[idx].alive) count++;
        }
    }
    return count;
}

void update_grid() {
    Cell *current = grid;
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int x = current->x;
        int y = current->y;
        int neighbors = neighbors_alive(x, y);
        if (current->alive && (neighbors < 2 || neighbors > 3)) current->alive = false;
        if (!current->alive && neighbors == 3) current->alive = true;
        current = current->next;
    }
}

void print_grid() {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        Cell *cell = &grid[i];
        printf(cell->alive ? "#" : ".");
        if (cell->x % WIDTH == WIDTH - 1) printf("\n");
    }
}

void set_cell(int x, int y) {
    int idx = x * HEIGHT + y;
    if (grid[idx].alive) {
        grid[idx].alive = false;
    } else {
        Cell *new_cell = malloc(sizeof(Cell));
        new_cell->x = x;
        new_cell->y = y;
        new_cell->alive = true;
        new_cell->next = grid[idx].next;
        grid[idx].next = new_cell;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <initial_state>\n", argv[0]);
        return 1;
    }

    int len = strlen(argv[1]);
    if (len > WIDTH * HEIGHT) {
        printf("Error: Input length is too long.\n");
        return 1;
    }

    grid = malloc(sizeof(Cell) * (WIDTH * HEIGHT));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        Cell *cell = &grid[i];
        cell->x = i % WIDTH;
        cell->y = i / WIDTH;
        cell->alive = argv[1][i] == '#';
        cell->next = NULL;
    }

    for (int step = 0; step < 5; step++) {
        update_grid();
        print_grid();
        usleep(100000);
        system("clear");
    }

    free(grid);
    return 0;
}