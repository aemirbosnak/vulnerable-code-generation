//Falcon2-11B DATASET v1.0 Category: Game of Life ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int state;
} Cell;

Cell* create_cell(int x, int y) {
    Cell* cell = (Cell*) malloc(sizeof(Cell));
    cell->x = x;
    cell->y = y;
    cell->state = 0;
    return cell;
}

void free_cell(Cell* cell) {
    free(cell);
}

void print_cell(Cell* cell) {
    printf("(%d, %d, %d)\n", cell->x, cell->y, cell->state);
}

void simulate(int width, int height, int generations) {
    srand(time(NULL));

    Cell** cells = (Cell**) malloc(width * sizeof(Cell*));

    for (int i = 0; i < width * height; i++) {
        cells[i] = create_cell(i % width, i / width);
    }

    for (int gen = 0; gen < generations; gen++) {
        for (int i = 0; i < width * height; i++) {
            int live_neighbors = 0;
            for (int j = i - 1; j <= i + 1; j++) {
                for (int k = j - 1; k <= j + 1; k++) {
                    if (j >= 0 && j < width && k >= 0 && k < height) {
                        live_neighbors += cells[i * width + j * height + k]->state;
                    }
                }
            }
            if (cells[i]->state == 1) {
                if (live_neighbors < 2 || live_neighbors > 3) {
                    cells[i]->state = 0;
                }
            } else {
                if (live_neighbors == 3) {
                    cells[i]->state = 1;
                }
            }
        }
    }

    for (int i = 0; i < width * height; i++) {
        print_cell(cells[i]);
    }
}

int main() {
    int width = 10;
    int height = 10;
    int generations = 100;

    printf("Generating initial state...\n");
    simulate(width, height, generations);

    printf("Simulating %d generations...\n", generations);
    simulate(width, height, generations);

    printf("Done!\n");

    return 0;
}