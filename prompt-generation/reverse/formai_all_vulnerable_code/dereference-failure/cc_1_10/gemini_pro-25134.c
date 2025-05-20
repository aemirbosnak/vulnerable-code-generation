//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} Path;

Path *path_new() {
    Path *path = malloc(sizeof(Path));
    path->points = malloc(sizeof(Point) * MAX_SIZE);
    path->size = 0;
    return path;
}

void path_free(Path *path) {
    free(path->points);
    free(path);
}

void path_add(Path *path, Point point) {
    path->points[path->size++] = point;
}

Point point_new(int x, int y) {
    Point point;
    point.x = x;
    point.y = y;
    return point;
}

int main() {
    Path *path = path_new();
    Point point = point_new(0, 0);
    path_add(path, point);
    point = point_new(1, 1);
    path_add(path, point);
    point = point_new(2, 2);
    path_add(path, point);
    point = point_new(3, 3);
    path_add(path, point);
    point = point_new(4, 4);
    path_add(path, point);
    for (int i = 0; i < path->size; i++) {
        printf("(%d, %d)\n", path->points[i].x, path->points[i].y);
    }
    path_free(path);
    return 0;
}