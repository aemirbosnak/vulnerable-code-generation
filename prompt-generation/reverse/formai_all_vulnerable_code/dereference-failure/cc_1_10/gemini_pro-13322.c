//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _carriage {
    int x, y;
    int dx, dy;
    char symbol;
} carriage;

typedef struct _map {
    int width, height;
    char **cells;
} map;

void init_map(map *m, int width, int height) {
    m->width = width;
    m->height = height;
    m->cells = malloc(sizeof(char *) * height);
    for (int i = 0; i < height; i++) {
        m->cells[i] = malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++) {
            m->cells[i][j] = '.';
        }
    }
}

void free_map(map *m) {
    for (int i = 0; i < m->height; i++) {
        free(m->cells[i]);
    }
    free(m->cells);
}

void print_map(map *m) {
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            printf("%c", m->cells[i][j]);
        }
        printf("\n");
    }
}

void init_carriage(carriage *c, int x, int y, int dx, int dy, char symbol) {
    c->x = x;
    c->y = y;
    c->dx = dx;
    c->dy = dy;
    c->symbol = symbol;
}

void move_carriage(carriage *c, map *m) {
    c->x += c->dx;
    c->y += c->dy;

    if (c->x < 0 || c->x >= m->width || c->y < 0 || c->y >= m->height) {
        c->dx = -c->dx;
        c->dy = -c->dy;
        c->x += c->dx;
        c->y += c->dy;
    }

    if (m->cells[c->y][c->x] != '.') {
        c->dx = -c->dx;
        c->dy = -c->dy;
        c->x += c->dx;
        c->y += c->dy;
    }

    m->cells[c->y][c->x] = c->symbol;
}

int main() {
    srand(time(NULL));

    map m;
    init_map(&m, 80, 25);

    carriage c;
    init_carriage(&c, rand() % m.width, rand() % m.height, 1, 0, 'C');

    while (1) {
        move_carriage(&c, &m);
        print_map(&m);
    }

    return 0;
}