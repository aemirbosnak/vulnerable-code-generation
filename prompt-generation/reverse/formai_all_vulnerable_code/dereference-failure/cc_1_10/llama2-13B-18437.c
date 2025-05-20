//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 1024
#define HEIGHT 1024

typedef struct {
    int x;
    int y;
    int alive;
} Cell;

void init_cells(Cell* cells, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            cells[i * height + j].x = i;
            cells[i * height + j].y = j;
            cells[i * height + j].alive = (rand() % 2) ? 1 : 0;
        }
    }
}

void update_cells(Cell* cells, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            int alive_neighbors = 0;
            int x = cells[i * height + j].x - 1;
            int y = cells[i * height + j].y - 1;
            while (x >= 0 && x < width && y >= 0 && y < height) {
                if (cells[x * height + y].alive) {
                    alive_neighbors++;
                }
                x++;
                y++;
            }
            cells[i * height + j].alive = (alive_neighbors >= 2 && alive_neighbors <= 3) ? 1 : 0;
        }
    }
}

void draw_cells(Cell* cells, int width, int height) {
    int i, j;
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            if (cells[i * height + j].alive) {
                printf("O ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Cell* cells = malloc(WIDTH * HEIGHT * sizeof(Cell));
    init_cells(cells, WIDTH, HEIGHT);
    for (int i = 0; i < 100; i++) {
        update_cells(cells, WIDTH, HEIGHT);
        draw_cells(cells, WIDTH, HEIGHT);
    }
    free(cells);
    return 0;
}