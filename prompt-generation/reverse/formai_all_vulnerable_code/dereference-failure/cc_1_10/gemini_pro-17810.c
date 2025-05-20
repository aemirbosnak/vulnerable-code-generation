//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: paranoid
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
    if (path->size >= MAX_SIZE) {
        fprintf(stderr, "Error: Path is full.\n");
        exit(1);
    }
    path->points[path->size++] = point;
}

void path_print(Path *path) {
    for (int i = 0; i < path->size; i++) {
        printf("(%d, %d)\n", path->points[i].x, path->points[i].y);
    }
}

int main() {
    Path *path = path_new();

    Point start = {0, 0};
    Point end = {10, 10};

    // Add points to the path.
    path_add(path, start);
    path_add(path, end);

    // Print the path.
    path_print(path);

    // Free the path.
    path_free(path);

    return 0;
}