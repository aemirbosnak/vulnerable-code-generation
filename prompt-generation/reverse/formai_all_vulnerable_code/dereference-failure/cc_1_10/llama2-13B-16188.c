//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CELL_SIZE 10
#define WINDOW_WIDTH (CELL_SIZE * 10)
#define WINDOW_HEIGHT (CELL_SIZE * 20)

typedef struct {
    int x;
    int y;
} cell_t;

cell_t generate_random_cell(void) {
    int x = rand() % WINDOW_WIDTH;
    int y = rand() % WINDOW_HEIGHT;
    return (cell_t) {x, y};
}

void draw_cell(cell_t cell, int x, int y) {
    printf("%d ", cell.x + x);
    printf("%d ", cell.y + y);
    printf("\n");
}

void update_cells(cell_t *cells, int num_cells) {
    for (int i = 0; i < num_cells; i++) {
        cell_t cell = cells[i];
        if (rand() % 2) {
            cell.x += 1;
            cell.y += 1;
        } else {
            cell.x -= 1;
            cell.y -= 1;
        }
        draw_cell(cell, cell.x, cell.y);
    }
}

int main() {
    srand(time(NULL));

    cell_t *cells = malloc(WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(cell_t));
    for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++) {
        cells[i] = generate_random_cell();
    }

    update_cells(cells, WINDOW_WIDTH * WINDOW_HEIGHT);

    for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++) {
        draw_cell(cells[i], cells[i].x, cells[i].y);
    }

    return 0;
}