//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000
#define PI 3.14159

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Polygon;

void init_polygon(Polygon *polygon) {
    polygon->points = malloc(MAX_SIZE * sizeof(Point));
    polygon->num_points = 0;
}

void add_point(Polygon *polygon, int x, int y) {
    Point *point = polygon->points + polygon->num_points++;
    *point = (Point){x, y};
}

void draw_polygon(Polygon *polygon) {
    for (int i = 0; i < polygon->num_points; i++) {
        Point *point = polygon->points + i;
        printf("(%d, %d)\n", point->x, point->y);
    }
}

void transform_polygon(Polygon *polygon, double angle) {
    for (int i = 0; i < polygon->num_points; i++) {
        Point *point = polygon->points + i;
        point->x += cos(angle) * 10;
        point->y += sin(angle) * 10;
    }
}

int main() {
    Polygon polygon;
    init_polygon(&polygon);
    add_point(&polygon, 0, 0);
    add_point(&polygon, 10, 0);
    add_point(&polygon, 10, 10);
    add_point(&polygon, 0, 10);
    draw_polygon(&polygon);
    transform_polygon(&polygon, 0);
    draw_polygon(&polygon);
    transform_polygon(&polygon, PI/4);
    draw_polygon(&polygon);
    transform_polygon(&polygon, PI/2);
    draw_polygon(&polygon);
    transform_polygon(&polygon, 3*PI/4);
    draw_polygon(&polygon);
    return 0;
}