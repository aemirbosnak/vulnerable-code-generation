//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point *points;
    int n;
} Polygon;

Polygon *create_polygon(int n) {
    Polygon *polygon = (Polygon *)malloc(sizeof(Polygon));
    polygon->points = (Point *)malloc(n * sizeof(Point));
    polygon->n = n;
    return polygon;
}

void destroy_polygon(Polygon *polygon) {
    free(polygon->points);
    free(polygon);
}

void add_point(Polygon *polygon, double x, double y) {
    Point *point = &polygon->points[polygon->n];
    point->x = x;
    point->y = y;
    polygon->n++;
}

double calculate_area(Polygon *polygon) {
    double area = 0.0;
    Point *prev_point = &polygon->points[polygon->n - 1];
    for (int i = 0; i < polygon->n; i++) {
        Point *point = &polygon->points[i];
        area += prev_point->x * point->y - prev_point->y * point->x;
        prev_point = point;
    }
    return fabs(area) / 2.0;
}

int main() {
    Polygon *polygon = create_polygon(4);
    add_point(polygon, 0.0, 0.0);
    add_point(polygon, 1.0, 0.0);
    add_point(polygon, 1.0, 1.0);
    add_point(polygon, 0.0, 1.0);
    double area = calculate_area(polygon);
    printf("The area of the polygon is %.2lf\n", area);
    destroy_polygon(polygon);
    return 0;
}