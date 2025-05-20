//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: paranoid
#include <stdbool.h>
#include <stdlib.h>
#include <inttypes.h>
#include <time.h>
#include <stdio.h>

#define EDGE_NONE 0
#define EDGE_TOP 1
#define EDGE_RIGHT 2
#define EDGE_BOTTOM 4
#define EDGE_LEFT 8
#define EDGE_ALL 15

typedef struct {
    uint8_t x;
    uint8_t y;
} point;

typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *walls;
} grid;

bool grid_valid_point(const grid *g, point p) {
    return (p.x >= 0 && p.x < g->width && p.y >= 0 && p.y < g->height);
}

uint8_t grid_get_edge(const grid *g, point p) {
    if (!grid_valid_point(g, p)) {
        return EDGE_ALL;
    }

    uint8_t index = p.y * g->width + p.x;

    return g->walls[index];
}

void grid_set_edge(grid *g, point p, uint8_t edge) {
    if (!grid_valid_point(g, p)) {
        return;
    }

    uint8_t index = p.y * g->width + p.x;

    g->walls[index] = edge;
}

void grid_open_edge(grid *g, point p, uint8_t edge) {
    if (!grid_valid_point(g, p)) {
        return;
    }

    g->walls[p.y * g->width + p.x] &= ~edge;
}

uint32_t grid_count_open_edges(const grid *g, point p) {
    if (!grid_valid_point(g, p)) {
        return 0;
    }

    uint32_t count = 0;

    if (!(g->walls[p.y * g->width + p.x] & EDGE_TOP)) {
        count++;
    }

    if (!(g->walls[p.y * g->width + p.x] & EDGE_RIGHT)) {
        count++;
    }

    if (!(g->walls[p.y * g->width + p.x] & EDGE_BOTTOM)) {
        count++;
    }

    if (!(g->walls[p.y * g->width + p.x] & EDGE_LEFT)) {
        count++;
    }

    return count;
}

void grid_visit(grid *g, point p, uint32_t *visited) {
    if (!grid_valid_point(g, p) || (visited[p.y * g->width + p.x] & 0x80000000)) {
        return;
    }

    *visited |= 1 << (p.y * g->width + p.x);

    if (!(g->walls[p.y * g->width + p.x] & EDGE_TOP)) {
        grid_visit(g, (point) {p.x, p.y - 1}, visited);
    }

    if (!(g->walls[p.y * g->width + p.x] & EDGE_RIGHT)) {
        grid_visit(g, (point) {p.x + 1, p.y}, visited);
    }

    if (!(g->walls[p.y * g->width + p.x] & EDGE_BOTTOM)) {
        grid_visit(g, (point) {p.x, p.y + 1}, visited);
    }

    if (!(g->walls[p.y * g->width + p.x] & EDGE_LEFT)) {
        grid_visit(g, (point) {p.x - 1, p.y}, visited);
    }
}

grid *grid_create(uint32_t width, uint32_t height) {
    grid *g = malloc(sizeof(grid));

    g->width = width;
    g->height = height;
    g->walls = malloc(width * height);

    for (uint32_t i = 0; i < width * height; i++) {
        g->walls[i] = EDGE_ALL;
    }

    return g;
}

void grid_destroy(grid *g) {
    free(g->walls);
    free(g);
}

grid *grid_generate_maze(uint32_t width, uint32_t height) {
    grid *g = grid_create(width, height);

    point p = {0, 0};
    point next;
    uint8_t edges;
    uint32_t visited = 0;

    srand(time(NULL));

    grid_visit(g, p, &visited);

    while (visited != (1 << (width * height)) - 1) {
        edges = grid_count_open_edges(g, p);

        if (edges == 0) {
            // Dead end, backtrack
            do {
                p.x--;

                if (p.x < 0) {
                    p.x = width - 1;
                    p.y--;
                }
            } while (grid_count_open_edges(g, p) == 0);
        } else {
            // Choose a random open edge
            next = p;

            while (1) {
                edges = rand() % 4;

                switch (edges) {
                    case 0:
                        if (!(g->walls[p.y * g->width + p.x] & EDGE_TOP)) {
                            next.y--;
                        }
                        break;
                    case 1:
                        if (!(g->walls[p.y * g->width + p.x] & EDGE_RIGHT)) {
                            next.x++;
                        }
                        break;
                    case 2:
                        if (!(g->walls[p.y * g->width + p.x] & EDGE_BOTTOM)) {
                            next.y++;
                        }
                        break;
                    case 3:
                        if (!(g->walls[p.y * g->width + p.x] & EDGE_LEFT)) {
                            next.x--;
                        }
                        break;
                }

                if (grid_valid_point(g, next) && !(visited & (1 << (next.y * g->width + next.x)))) {
                    break;
                }
            }

            grid_open_edge(g, next, grid_get_edge(g, p) ^ grid_get_edge(g, next));
            grid_visit(g, next, &visited);
            p = next;
        }
    }

    return g;
}

void grid_print(const grid *g) {
    for (uint32_t y = 1; y < g->height - 1; y++) {
        for (uint32_t x = 1; x < g->width - 1; x++) {
            uint8_t walls = grid_get_edge(g, (point) {x, y});

            printf("%c", walls & EDGE_TOP ? '#' : ' ');
            printf("%c", walls & EDGE_RIGHT ? '#' : ' ');
        }

        printf("#\n");

        for (uint32_t x = 1; x < g->width - 1; x++) {
            uint8_t walls = grid_get_edge(g, (point) {x, y});

            printf("%c", walls & EDGE_LEFT ? '#' : ' ');
            printf("%c", walls & EDGE_BOTTOM ? '#' : ' ');
        }

        printf("#\n");
    }

    for (uint32_t x = 1; x < g->width - 1; x++) {
        printf("#");
    }

    printf("#\n");
}

int main(int argc, char **argv) {
    grid *g = grid_generate_maze(100, 100);

    grid_print(g);

    grid_destroy(g);

    return 0;
}