//LLAMA2-13B DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 640
#define HEIGHT 480
#define CELL_SIZE 10
#define BACKGROUND_COLOR 0x000000
#define CELL_COLOR 0xffffff

struct cell {
    int x, y;
    int alive;
};

struct grid {
    struct cell **grid;
    int rows, cols;
};

void init_grid(struct grid *g) {
    g->grid = calloc(HEIGHT, sizeof(struct cell *));
    for (int i = 0; i < HEIGHT; i++) {
        g->grid[i] = calloc(WIDTH, sizeof(struct cell));
    }
    g->rows = HEIGHT;
    g->cols = WIDTH;
}

void draw_grid(struct grid *g) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (g->grid[i][j].alive) {
                printf("%c", CELL_COLOR);
            } else {
                printf("%c", BACKGROUND_COLOR);
            }
        }
        printf("\n");
    }
}

void update_grid(struct grid *g) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (g->grid[i][j].alive) {
                if (rand() % 2) {
                    g->grid[i][j].alive = 0;
                } else {
                    g->grid[i][j].alive = 1;
                }
            }
        }
    }
}

int main() {
    struct grid g;
    init_grid(&g);

    while (1) {
        update_grid(&g);
        draw_grid(&g);
        printf("Press any key to continue...");
        getchar();
    }

    return 0;
}