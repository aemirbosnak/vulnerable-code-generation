//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int npoints;
} Polygon;

Polygon *create_polygon(int npoints) {
    Polygon *polygon = malloc(sizeof(Polygon));
    polygon->points = malloc(npoints * sizeof(Point));
    polygon->npoints = npoints;
    return polygon;
}

void free_polygon(Polygon *polygon) {
    free(polygon->points);
    free(polygon);
}

void print_polygon(Polygon *polygon) {
    for (int i = 0; i < polygon->npoints; i++) {
        printf("(%f, %f)\n", polygon->points[i].x, polygon->points[i].y);
    }
}

double polygon_area(Polygon *polygon) {
    double area = 0;
    for (int i = 0; i < polygon->npoints; i++) {
        Point p1 = polygon->points[i];
        Point p2 = polygon->points[(i + 1) % polygon->npoints];
        area += (p1.x * p2.y - p1.y * p2.x) / 2;
    }
    return fabs(area);
}

int main() {
    Polygon *polygon = create_polygon(4);
    polygon->points[0] = (Point) {0, 0};
    polygon->points[1] = (Point) {1, 0};
    polygon->points[2] = (Point) {1, 1};
    polygon->points[3] = (Point) {0, 1};

    printf("Polygon:\n");
    print_polygon(polygon);

    printf("Area: %f\n", polygon_area(polygon));

    free_polygon(polygon);

    return 0;
}