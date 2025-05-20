//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int n;
} Polygon;

Polygon *create_polygon(int n) {
    Polygon *polygon = (Polygon *) malloc(sizeof(Polygon));
    polygon->n = n;
    polygon->points = (Point *) malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        polygon->points[i].x = rand() % 100;
        polygon->points[i].y = rand() % 100;
    }
    return polygon;
}

void print_polygon(Polygon *polygon) {
    for (int i = 0; i < polygon->n; i++) {
        printf("(%lf, %lf) ", polygon->points[i].x, polygon->points[i].y);
    }
    printf("\n");
}

void rotate_polygon(Polygon *polygon, double angle) {
    double cosine = cos(angle);
    double sine = sin(angle);
    for (int i = 0; i < polygon->n; i++) {
        double x = polygon->points[i].x;
        double y = polygon->points[i].y;
        double new_x = x * cosine - y * sine;
        double new_y = x * sine + y * cosine;
        polygon->points[i].x = new_x;
        polygon->points[i].y = new_y;
    }
}

void translate_polygon(Polygon *polygon, double dx, double dy) {
    for (int i = 0; i < polygon->n; i++) {
        polygon->points[i].x += dx;
        polygon->points[i].y += dy;
    }
}

void scale_polygon(Polygon *polygon, double factor) {
    for (int i = 0; i < polygon->n; i++) {
        polygon->points[i].x *= factor;
        polygon->points[i].y *= factor;
    }
}

void reflect_polygon(Polygon *polygon, double angle) {
    double cosine = cos(angle);
    double sine = sin(angle);
    for (int i = 0; i < polygon->n; i++) {
        double x = polygon->points[i].x;
        double y = polygon->points[i].y;
        double new_x = x * cosine + y * sine;
        double new_y = -x * sine + y * cosine;
        polygon->points[i].x = new_x;
        polygon->points[i].y = new_y;
    }
}

int main() {
    Polygon *polygon = create_polygon(6);
    print_polygon(polygon);
    rotate_polygon(polygon, M_PI / 4);
    print_polygon(polygon);
    translate_polygon(polygon, 50, 50);
    print_polygon(polygon);
    scale_polygon(polygon, 2);
    print_polygon(polygon);
    reflect_polygon(polygon, M_PI / 2);
    print_polygon(polygon);
    free(polygon->points);
    free(polygon);
    return 0;
}