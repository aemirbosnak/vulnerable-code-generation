//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point start;
    Point end;
} Path;

typedef struct {
    int *map;
    int width;
    int height;
} Map;

Map *map_create(int width, int height) {
    Map *map = malloc(sizeof(Map));
    map->map = malloc(width * height * sizeof(int));
    map->width = width;
    map->height = height;
    return map;
}

void map_destroy(Map *map) {
    free(map->map);
    free(map);
}

int map_get(Map *map, Point point) {
    return map->map[point.y * map->width + point.x];
}

void map_set(Map *map, Point point, int value) {
    map->map[point.y * map->width + point.x] = value;
}

int map_is_valid(Map *map, Point point) {
    return point.x >= 0 && point.x < map->width && point.y >= 0 && point.y < map->height;
}

Path *path_create(Point start, Point end) {
    Path *path = malloc(sizeof(Path));
    path->start = start;
    path->end = end;
    return path;
}

void path_destroy(Path *path) {
    free(path);
}

int path_is_valid(Path *path) {
    return path->start.x >= 0 && path->start.x < MAP_WIDTH && path->start.y >= 0 && path->start.y < MAP_HEIGHT &&
           path->end.x >= 0 && path->end.x < MAP_WIDTH && path->end.y >= 0 && path->end.y < MAP_HEIGHT;
}

int path_length(Path *path) {
    return abs(path->end.x - path->start.x) + abs(path->end.y - path->start.y);
}

Point *path_next_point(Path *path) {
    Point *next_point = malloc(sizeof(Point));
    if (path->start.x == path->end.x) {
        next_point->x = path->start.x;
        if (path->start.y < path->end.y) {
            next_point->y = path->start.y + 1;
        } else {
            next_point->y = path->start.y - 1;
        }
    } else {
        next_point->y = path->start.y;
        if (path->start.x < path->end.x) {
            next_point->x = path->start.x + 1;
        } else {
            next_point->x = path->start.x - 1;
        }
    }
    return next_point;
}

int main() {
    Map *map = map_create(MAP_WIDTH, MAP_HEIGHT);

    // Set up the map
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map_set(map, (Point) {x, y}, rand() % 2);
        }
    }

    // Find a path from the start to the end
    Path *path = path_create((Point) {0, 0}, (Point) {MAP_WIDTH - 1, MAP_HEIGHT - 1});
    while (!path_is_valid(path)) {
        Point *next_point = path_next_point(path);
        if (map_is_valid(map, *next_point) && map_get(map, *next_point) == 0) {
            path->start = *next_point;
        } else {
            path_destroy(path);
            return 1;
        }
        free(next_point);
    }

    // Print the path
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (path->start.x == x && path->start.y == y) {
                printf("S");
            } else if (path->end.x == x && path->end.y == y) {
                printf("E");
            } else if (map_get(map, (Point) {x, y}) == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    // Clean up
    path_destroy(path);
    map_destroy(map);

    return 0;
}