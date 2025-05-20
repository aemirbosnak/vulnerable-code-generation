//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool is_valid_point(Point point) {
    return point.x >= 0 && point.x < MAP_WIDTH && point.y >= 0 && point.y < MAP_HEIGHT;
}

bool is_point_in_path(Path path, Point point) {
    for (int i = 0; i < path.size; i++) {
        if (path.points[i].x == point.x && path.points[i].y == point.y) {
            return true;
        }
    }
    return false;
}

Path *find_path(Point start, Point end) {
    Path *path = malloc(sizeof(Path));
    path->size = 0;
    path->points = malloc(sizeof(Point) * MAP_WIDTH * MAP_HEIGHT);

    Point current_point = start;
    while (current_point.x != end.x || current_point.y != end.y) {
        // Check if the current point is valid
        if (!is_valid_point(current_point)) {
            free(path);
            return NULL;
        }

        // Check if the current point is already in the path
        if (is_point_in_path(*path, current_point)) {
            free(path);
            return NULL;
        }

        // Add the current point to the path
        path->points[path->size] = current_point;
        path->size++;

        // Check if the current point is the end point
        if (current_point.x == end.x && current_point.y == end.y) {
            return path;
        }

        // Move the current point to the next point in the path
        if (current_point.x < end.x) {
            current_point.x++;
        } else if (current_point.x > end.x) {
            current_point.x--;
        } else if (current_point.y < end.y) {
            current_point.y++;
        } else if (current_point.y > end.y) {
            current_point.y--;
        }
    }

    return path;
}

void print_path(Path *path) {
    for (int i = 0; i < path->size; i++) {
        printf("(%d, %d)\n", path->points[i].x, path->points[i].y);
    }
}

int main() {
    Point start = {0, 0};
    Point end = {9, 9};

    Path *path = find_path(start, end);

    if (path == NULL) {
        printf("No path found.\n");
    } else {
        printf("Path found:\n");
        print_path(path);
        free(path->points);
        free(path);
    }

    return 0;
}