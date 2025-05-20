//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: protected
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} Path;

bool map[MAP_WIDTH][MAP_HEIGHT];

void init_map() {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            map[i][j] = false;
        }
    }
}

void print_map() {
    for (int i = 0; i < MAP_WIDTH; i++) {
        for (int j = 0; j < MAP_HEIGHT; j++) {
            printf("%c", map[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

bool is_valid_point(Point point) {
    return point.x >= 0 && point.x < MAP_WIDTH && point.y >= 0 && point.y < MAP_HEIGHT && !map[point.x][point.y];
}

Path *find_path(Point start, Point end) {
    if (!is_valid_point(start) || !is_valid_point(end)) {
        return NULL;
    }

    Path *path = malloc(sizeof(Path));
    path->points = malloc(sizeof(Point));
    path->size = 0;

    Point current = start;
    while (current.x != end.x || current.y != end.y) {
        Point next;
        if (current.x < end.x) {
            next.x = current.x + 1;
        } else if (current.x > end.x) {
            next.x = current.x - 1;
        } else {
            next.x = current.x;
        }

        if (current.y < end.y) {
            next.y = current.y + 1;
        } else if (current.y > end.y) {
            next.y = current.y - 1;
        } else {
            next.y = current.y;
        }

        if (!is_valid_point(next)) {
            free(path->points);
            free(path);
            return NULL;
        }

        path->points = realloc(path->points, sizeof(Point) * (path->size + 1));
        path->points[path->size++] = next;
        current = next;
    }

    return path;
}

void free_path(Path *path) {
    free(path->points);
    free(path);
}

int main() {
    init_map();

    Point start = {0, 0};
    Point end = {MAP_WIDTH - 1, MAP_HEIGHT - 1};

    Path *path = find_path(start, end);
    if (path == NULL) {
        printf("No path found.\n");
    } else {
        printf("Path found:\n");
        for (int i = 0; i < path->size; i++) {
            printf("(%d, %d)\n", path->points[i].x, path->points[i].y);
        }
        free_path(path);
    }

    return 0;
}