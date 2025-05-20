//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int count;
} Polygon;

void polygon_init(Polygon *polygon) {
    polygon->points = NULL;
    polygon->count = 0;
}

void polygon_add_point(Polygon *polygon, int x, int y) {
    Point *point = malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    polygon->points = realloc(polygon->points, polygon->count + 1);
    polygon->points[polygon->count++] = *point;
    free(point);
}

void polygon_print(Polygon *polygon) {
    for (int i = 0; i < polygon->count; i++) {
        printf("(%d,%d) ", polygon->points[i].x, polygon->points[i].y);
    }
    printf("\n");
}

void polygon_free(Polygon *polygon) {
    free(polygon->points);
}

int main() {
    Polygon polygon;
    polygon_init(&polygon);
    polygon_add_point(&polygon, 0, 0);
    polygon_add_point(&polygon, 10, 0);
    polygon_add_point(&polygon, 10, 10);
    polygon_add_point(&polygon, 0, 10);
    polygon_print(&polygon);
    polygon_free(&polygon);
    return 0;
}