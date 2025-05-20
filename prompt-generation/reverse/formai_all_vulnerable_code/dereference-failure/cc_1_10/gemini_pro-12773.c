//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_GENERATIONS 1000

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point *cells;
    int size;
} grid;

grid *create_grid() {
    grid *g = malloc(sizeof(grid));
    g->cells = malloc(WIDTH * HEIGHT * sizeof(point));
    g->size = 0;
    return g;
}

void destroy_grid(grid *g) {
    free(g->cells);
    free(g);
}

void add_cell(grid *g, int x, int y) {
    g->cells[g->size++] = (point){x, y};
}

void print_grid(grid *g) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int alive = 0;
            for (int i = 0; i < g->size; i++) {
                if (g->cells[i].x == x && g->cells[i].y == y) {
                    alive = 1;
                    break;
                }
            }
            printf("%c", alive ? '#' : '.');
        }
        printf("\n");
    }
}

int count_neighbors(grid *g, int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int nx = x + i;
            int ny = y + j;
            if (nx < 0 || nx >= WIDTH || ny < 0 || ny >= HEIGHT) continue;
            for (int k = 0; k < g->size; k++) {
                if (g->cells[k].x == nx && g->cells[k].y == ny) {
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}

void update_grid(grid *g) {
    grid *new_g = create_grid();
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int neighbors = count_neighbors(g, x, y);
            int alive = 0;
            for (int i = 0; i < g->size; i++) {
                if (g->cells[i].x == x && g->cells[i].y == y) {
                    alive = 1;
                    break;
                }
            }
            if (alive) {
                if (neighbors == 2 || neighbors == 3) {
                    add_cell(new_g, x, y);
                }
            } else {
                if (neighbors == 3) {
                    add_cell(new_g, x, y);
                }
            }
        }
    }
    destroy_grid(g);
    g = new_g;
}

int main() {
    grid *g = create_grid();
    add_cell(g, 40, 12);
    add_cell(g, 41, 12);
    add_cell(g, 42, 12);
    add_cell(g, 40, 13);
    add_cell(g, 42, 13);
    add_cell(g, 40, 14);
    add_cell(g, 41, 14);
    add_cell(g, 42, 14);
    printf("Generation 0:\n");
    print_grid(g);
    for (int i = 1; i <= MAX_GENERATIONS; i++) {
        update_grid(g);
        printf("Generation %d:\n", i);
        print_grid(g);
    }
    destroy_grid(g);
    return 0;
}