//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    int x, y;
} point;

typedef struct {
    point *points;
    int size;
} path;

typedef struct {
    int **data;
    int width, height;
} maze;

maze *maze_new(int width, int height) {
    maze *m = malloc(sizeof(maze));
    m->data = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        m->data[i] = malloc(sizeof(int) * width);
    }
    m->width = width;
    m->height = height;
    return m;
}

void maze_free(maze *m) {
    for (int i = 0; i < m->height; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

int maze_get(maze *m, int x, int y) {
    return m->data[y][x];
}

int maze_set(maze *m, int x, int y, int value) {
    m->data[y][x] = value;
}

path *path_new() {
    path *p = malloc(sizeof(path));
    p->points = malloc(sizeof(point));
    p->size = 1;
    return p;
}

void path_free(path *p) {
    free(p->points);
    free(p);
}

void path_add(path *p, point point) {
    p->points = realloc(p->points, sizeof(point) * (p->size + 1));
    p->points[p->size] = point;
    p->size++;
}

int path_is_valid(path *p, maze *m) {
    for (int i = 0; i < p->size; i++) {
        if (p->points[i].x < 0 || p->points[i].x >= m->width || p->points[i].y < 0 || p->points[i].y >= m->height) {
            return 0;
        }
        if (maze_get(m, p->points[i].x, p->points[i].y) == 0) {
            return 0;
        }
    }
    return 1;
}

int path_is_complete(path *p, maze *m) {
    return p->points[p->size - 1].x == m->width - 1 && p->points[p->size - 1].y == m->height - 1;
}

path *path_find(maze *m, point start, point end) {
    path *p = path_new();
    path_add(p, start);
    while (!path_is_complete(p, m)) {
        point next = p->points[p->size - 1];
        if (next.x + 1 < m->width && maze_get(m, next.x + 1, next.y) == 1) {
            path_add(p, (point){next.x + 1, next.y});
        } else if (next.y + 1 < m->height && maze_get(m, next.x, next.y + 1) == 1) {
            path_add(p, (point){next.x, next.y + 1});
        } else if (next.x - 1 >= 0 && maze_get(m, next.x - 1, next.y) == 1) {
            path_add(p, (point){next.x - 1, next.y});
        } else if (next.y - 1 >= 0 && maze_get(m, next.x, next.y - 1) == 1) {
            path_add(p, (point){next.x, next.y - 1});
        } else {
            path_free(p);
            return NULL;
        }
    }
    return p;
}

void maze_print(maze *m) {
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            printf("%d ", maze_get(m, j, i));
        }
        printf("\n");
    }
}

int main() {
    int width, height;
    scanf("%d %d", &width, &height);
    maze *m = maze_new(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &m->data[i][j]);
        }
    }
    point start = {0, 0};
    point end = {width - 1, height - 1};
    path *p = path_find(m, start, end);
    if (p == NULL) {
        printf("No path found\n");
    } else {
        for (int i = 0; i < p->size; i++) {
            printf("(%d, %d) ", p->points[i].x, p->points[i].y);
        }
        printf("\n");
    }
    maze_free(m);
    path_free(p);
    return 0;
}