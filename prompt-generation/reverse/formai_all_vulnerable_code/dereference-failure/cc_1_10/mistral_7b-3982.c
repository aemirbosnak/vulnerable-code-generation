//MISTRAL-7B DATASET v1.0 Category: Game of Life ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 32
#define HEIGHT 32
#define MAX_CELL 1
#define MIN_CELL 0

typedef struct {
    int x, y;
} Point;

typedef struct {
    int width, height;
    int **cells;
} Universe;

Universe *create_universe() {
    Universe *universe = malloc(sizeof(Universe));

    universe->width = WIDTH;
    universe->height = HEIGHT;

    universe->cells = malloc(sizeof(int *) * universe->height);

    for (int i = 0; i < universe->height; i++) {
        universe->cells[i] = calloc(universe->width, sizeof(int));
    }

    return universe;
}

void print_universe(Universe *universe) {
    for (int y = 0; y < universe->height; y++) {
        for (int x = 0; x < universe->width; x++) {
            printf("%d", universe->cells[y][x]);
        }
        printf("\n");
    }
}

void randomize_universe(Universe *universe) {
    srand(time(NULL));

    for (int y = 0; y < universe->height; y++) {
        for (int x = 0; x < universe->width; x++) {
            universe->cells[y][x] = (rand() % 2) * 2 - 1;
        }
    }
}

int count_neighbors(Universe *universe, int x, int y) {
    int neighbors = 0;

    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;

            int new_x = x + dx;
            int new_y = y + dy;

            if (new_x < 0 || new_x >= universe->width || new_y < 0 || new_y >= universe->height) continue;

            neighbors += universe->cells[new_y][new_x];
        }
    }

    return neighbors;
}

void update_universe(Universe *universe) {
    int new_cells[HEIGHT][WIDTH];

    for (int y = 0; y < universe->height; y++) {
        for (int x = 0; x < universe->width; x++) {
            int neighbors = count_neighbors(universe, x, y);

            new_cells[y][x] = universe->cells[y][x];

            if (universe->cells[y][x] == MAX_CELL) {
                if (neighbors < 2 || neighbors > 3) {
                    new_cells[y][x] = MIN_CELL;
                }
            } else if (neighbors == 3) {
                new_cells[y][x] = MAX_CELL;
            }
        }
    }

    for (int y = 0; y < universe->height; y++) {
        for (int x = 0; x < universe->width; x++) {
            universe->cells[y][x] = new_cells[y][x];
        }
    }
}

void destroy_universe(Universe *universe) {
    for (int i = 0; i < universe->height; i++) {
        free(universe->cells[i]);
    }

    free(universe->cells);
    free(universe);
}

int main() {
    Universe *universe = create_universe();

    randomize_universe(universe);
    print_universe(universe);

    for (int i = 0; i < 50; i++) {
        update_universe(universe);
        print_universe(universe);
        sleep(100); // Add a delay to make the output readable
    }

    destroy_universe(universe);

    return 0;
}