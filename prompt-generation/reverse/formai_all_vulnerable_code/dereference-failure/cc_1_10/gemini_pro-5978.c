//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} point;

typedef struct {
    point *points;
    int size;
} path;

path *path_new(int size) {
    path *p = malloc(sizeof(path));
    p->points = malloc(sizeof(point) * size);
    p->size = size;
    return p;
}

void path_free(path *p) {
    free(p->points);
    free(p);
}

int path_add_point(path *p, point point) {
    if (p->size == 0) {
        p->points = malloc(sizeof(point));
        p->size = 1;
    } else {
        p->points = realloc(p->points, sizeof(point) * ++p->size);
    }
    p->points[p->size - 1] = point;
    return 0;
}

int path_get_length(path *p) {
    return p->size;
}

point path_get_point(path *p, int index) {
    return p->points[index];
}

int path_compare(path *p1, path *p2) {
    if (p1->size != p2->size) {
        return -1;
    }
    for (int i = 0; i < p1->size; i++) {
        if (p1->points[i].x != p2->points[i].x || p1->points[i].y != p2->points[i].y) {
            return -1;
        }
    }
    return 0;
}

void path_print(path *p) {
    printf("Path: ");
    for (int i = 0; i < p->size; i++) {
        printf("(%d, %d) ", p->points[i].x, p->points[i].y);
    }
    printf("\n");
}

int main() {
    path *p = path_new(0);
    path_add_point(p, (point){0, 0});
    path_add_point(p, (point){1, 0});
    path_add_point(p, (point){1, 1});
    path_add_point(p, (point){0, 1});
    path_print(p);
    path_free(p);
    return 0;
}