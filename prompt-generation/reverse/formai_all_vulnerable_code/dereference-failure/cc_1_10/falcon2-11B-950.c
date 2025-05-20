//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int width;
    int height;
    Point* points;
} Map;

void initMap(Map* map, int width, int height) {
    map->width = width;
    map->height = height;
    map->points = (Point*)malloc(sizeof(Point) * width * height);
}

void addPoint(Map* map, int x, int y) {
    if (map->width == 0 || map->height == 0) {
        return;
    }

    if (x < 0 || x >= map->width || y < 0 || y >= map->height) {
        return;
    }

    Point* point = &(map->points[x + map->width * y]);
    point->x = x;
    point->y = y;
}

void printMap(Map* map) {
    if (map->width == 0 || map->height == 0) {
        return;
    }

    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->height; j++) {
            Point* point = &(map->points[i + map->width * j]);
            printf("%d ", point->x);
        }
        printf("\n");
    }
}

int main() {
    int width = 10;
    int height = 10;
    Map map;
    initMap(&map, width, height);

    addPoint(&map, 0, 0);
    addPoint(&map, 1, 0);
    addPoint(&map, 0, 1);
    addPoint(&map, 1, 1);
    addPoint(&map, 0, 2);
    addPoint(&map, 1, 2);
    addPoint(&map, 2, 2);
    addPoint(&map, 2, 3);
    addPoint(&map, 3, 3);
    addPoint(&map, 3, 4);
    addPoint(&map, 4, 4);
    addPoint(&map, 4, 5);
    addPoint(&map, 5, 5);
    addPoint(&map, 5, 6);
    addPoint(&map, 6, 6);
    addPoint(&map, 6, 7);
    addPoint(&map, 7, 7);
    addPoint(&map, 7, 8);
    addPoint(&map, 8, 8);
    addPoint(&map, 8, 9);
    addPoint(&map, 9, 9);
    addPoint(&map, 9, 10);
    addPoint(&map, 10, 10);
    addPoint(&map, 10, 0);
    addPoint(&map, 0, 10);
    addPoint(&map, 1, 10);
    addPoint(&map, 2, 10);
    addPoint(&map, 3, 10);
    addPoint(&map, 4, 10);
    addPoint(&map, 5, 10);
    addPoint(&map, 6, 10);
    addPoint(&map, 7, 10);
    addPoint(&map, 8, 10);
    addPoint(&map, 9, 10);
    addPoint(&map, 10, 10);

    printMap(&map);

    return 0;
}