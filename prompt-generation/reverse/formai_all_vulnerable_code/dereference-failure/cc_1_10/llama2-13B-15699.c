//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define M 100

struct point {
    int x;
    int y;
};

struct line {
    struct point start;
    struct point end;
};

struct grid {
    struct line **lines;
    int width;
    int height;
};

void generate_grid(struct grid *g) {
    int i, j;

    for (i = 0; i < g->width; i++) {
        g->lines[i] = calloc(g->height, sizeof(struct line));

        for (j = 0; j < g->height; j++) {
            struct point p;
            p.x = i * 10 + random() % 5;
            p.y = j * 10 + random() % 5;
            g->lines[i][j] = (struct line) { p, p };
        }
    }
}

void print_grid(struct grid *g) {
    int i, j;

    for (i = 0; i < g->width; i++) {
        for (j = 0; j < g->height; j++) {
            printf("(%d, %d) ", g->lines[i][j].start.x, g->lines[i][j].start.y);
        }
        printf("\n");
    }
}

int main() {
    struct grid g;

    srand(time(NULL));

    g.width = N;
    g.height = M;
    g.lines = calloc(g.width, sizeof(struct line *));

    for (int i = 0; i < g.width; i++) {
        g.lines[i] = calloc(g.height, sizeof(struct line));
    }

    generate_grid(&g);

    print_grid(&g);

    return 0;
}