//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x, y;
} point;

typedef struct {
    point *points;
    int num_points;
} path;

typedef struct {
    int **grid;
    int width, height;
} map;

map *map_create(int width, int height) {
    map *m = malloc(sizeof(map));
    m->grid = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        m->grid[i] = malloc(sizeof(int) * width);
    }
    m->width = width;
    m->height = height;
    return m;
}

void map_destroy(map *m) {
    for (int i = 0; i < m->height; i++) {
        free(m->grid[i]);
    }
    free(m->grid);
    free(m);
}

void map_print(map *m) {
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            printf("%d ", m->grid[i][j]);
        }
        printf("\n");
    }
}

int map_get(map *m, int x, int y) {
    if (x < 0 || x >= m->width || y < 0 || y >= m->height) {
        return 0;
    }
    return m->grid[y][x];
}

void map_set(map *m, int x, int y, int value) {
    if (x < 0 || x >= m->width || y < 0 || y >= m->height) {
        return;
    }
    m->grid[y][x] = value;
}

path *path_create() {
    path *p = malloc(sizeof(path));
    p->points = malloc(sizeof(point));
    p->num_points = 0;
    return p;
}

void path_destroy(path *p) {
    free(p->points);
    free(p);
}

void path_add_point(path *p, point point) {
    p->points = realloc(p->points, sizeof(point) * (p->num_points + 1));
    p->points[p->num_points] = point;
    p->num_points++;
}

int path_length(path *p) {
    return p->num_points;
}

point path_get_point(path *p, int index) {
    if (index < 0 || index >= p->num_points) {
        return (point){-1, -1};
    }
    return p->points[index];
}

int path_distance(path *p) {
    int distance = 0;
    for (int i = 0; i < p->num_points - 1; i++) {
        point p1 = path_get_point(p, i);
        point p2 = path_get_point(p, i + 1);
        distance += abs(p2.x - p1.x) + abs(p2.y - p1.y);
    }
    return distance;
}

path *path_find(map *m, point start, point end) {
    path *p = path_create();
    path_add_point(p, start);

    while (path_get_point(p, path_length(p) - 1).x != end.x || path_get_point(p, path_length(p) - 1).y != end.y) {
        point current = path_get_point(p, path_length(p) - 1);
        int best_x = -1;
        int best_y = -1;
        int best_distance = 999999999;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                int x = current.x + i;
                int y = current.y + j;

                if (map_get(m, x, y) == 1) {
                    continue;
                }

                int distance = abs(x - end.x) + abs(y - end.y);

                if (distance < best_distance) {
                    best_distance = distance;
                    best_x = x;
                    best_y = y;
                }
            }
        }

        path_add_point(p, (point){best_x, best_y});
    }

    return p;
}

int main() {
    srand(time(NULL));

    int width = 20;
    int height = 20;

    map *m = map_create(width, height);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (rand() % 10 == 0) {
                map_set(m, i, j, 1);
            }
        }
    }

    map_print(m);

    point start = {0, 0};
    point end = {width - 1, height - 1};

    path *p = path_find(m, start, end);

    printf("Path length: %d\n", path_length(p));
    printf("Path distance: %d\n", path_distance(p));

    for (int i = 0; i < path_length(p); i++) {
        point point = path_get_point(p, i);
        printf("(%d, %d)\n", point.x, point.y);
    }

    path_destroy(p);
    map_destroy(m);

    return 0;
}