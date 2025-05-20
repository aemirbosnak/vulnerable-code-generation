//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 10
#define M 5

typedef struct {
    int x;
    int y;
} point_t;

typedef struct {
    point_t p1;
    point_t p2;
} line_t;

typedef struct {
    line_t *lines;
    int num_lines;
} grid_t;

grid_t *create_grid(int size) {
    grid_t *g = (grid_t *)calloc(1, sizeof(grid_t));
    g->num_lines = size;
    g->lines = (line_t *)calloc(size, sizeof(line_t));
    return g;
}

void print_grid(grid_t *g) {
    for (int i = 0; i < g->num_lines; i++) {
        line_t *line = g->lines + i;
        printf("Line %d: (%d, %d)\n", i, line->p1.x, line->p1.y);
        printf("Line %d: (%d, %d)\n", i, line->p2.x, line->p2.y);
    }
}

void add_line(grid_t *g, int x1, int y1, int x2, int y2) {
    line_t *line = (line_t *)calloc(1, sizeof(line_t));
    line->p1.x = x1;
    line->p1.y = y1;
    line->p2.x = x2;
    line->p2.y = y2;
    g->lines[g->num_lines] = *line;
    g->num_lines++;
}

int main() {
    srand(time(NULL));
    grid_t *g = create_grid(N);
    for (int i = 0; i < M; i++) {
        int x = rand() % N;
        int y = rand() % N;
        add_line(g, x, y, x + rand() % 3 - 1, y + rand() % 3 - 1);
    }
    print_grid(g);
    return 0;
}