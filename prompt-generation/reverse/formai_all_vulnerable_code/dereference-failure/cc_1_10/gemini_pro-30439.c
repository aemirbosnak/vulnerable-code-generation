//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Polygon;

Polygon *create_polygon(int num_points) {
    Polygon *poly = malloc(sizeof(Polygon));
    poly->points = malloc(sizeof(Point) * num_points);
    poly->num_points = num_points;
    return poly;
}

void free_polygon(Polygon *poly) {
    free(poly->points);
    free(poly);
}

void set_point(Polygon *poly, int index, int x, int y) {
    poly->points[index].x = x;
    poly->points[index].y = y;
}

double polygon_area(Polygon *poly) {
    double area = 0;
    for (int i = 0; i < poly->num_points; i++) {
        Point p1 = poly->points[i];
        Point p2 = poly->points[(i + 1) % poly->num_points];
        area += p1.x * p2.y - p1.y * p2.x;
    }
    return area / 2;
}

int main() {
    srand(time(NULL));

    Polygon *poly = create_polygon(rand() % 10 + 3);
    for (int i = 0; i < poly->num_points; i++) {
        set_point(poly, i, rand() % 100, rand() % 100);
    }

    double area = polygon_area(poly);
    printf("The area of the polygon is: %f\n", area);

    free_polygon(poly);
    return 0;
}