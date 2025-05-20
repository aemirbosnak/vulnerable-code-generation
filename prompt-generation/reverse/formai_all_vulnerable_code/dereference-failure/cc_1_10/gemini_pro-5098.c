//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 10

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} Polygon;

void draw_polygon(Polygon *polygon) {
    for (int i = 0; i < polygon->size; i++) {
        printf("(%d, %d) ", polygon->points[i].x, polygon->points[i].y);
    }
    printf("\n");
}

void shift_polygon(Polygon *polygon, int dx, int dy) {
    for (int i = 0; i < polygon->size; i++) {
        polygon->points[i].x += dx;
        polygon->points[i].y += dy;
    }
}

int main() {
    Polygon polygon;
    polygon.size = SIZE;
    polygon.points = malloc(sizeof(Point) * SIZE);

    for (int i = 0; i < SIZE; i++) {
        polygon.points[i].x = i;
        polygon.points[i].y = i;
    }

    draw_polygon(&polygon);

    shift_polygon(&polygon, 1, 1);

    draw_polygon(&polygon);

    free(polygon.points);

    return 0;
}