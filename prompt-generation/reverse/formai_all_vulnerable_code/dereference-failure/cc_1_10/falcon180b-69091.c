//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    int numVertices;
    Point *vertices;
} Polygon;

Polygon *generatePolygon(int numVertices, double xMin, double xMax, double yMin, double yMax) {
    Polygon *polygon = malloc(sizeof(Polygon));
    polygon->numVertices = numVertices;
    polygon->vertices = malloc(numVertices * sizeof(Point));

    double angleIncrement = 2 * M_PI / numVertices;
    double radius = (xMax - xMin) / 2;
    double x = xMin + radius;
    double y = yMin + radius;

    for (int i = 0; i < numVertices; i++) {
        polygon->vertices[i].x = x;
        polygon->vertices[i].y = y;
        x += cos(i * angleIncrement);
        y += sin(i * angleIncrement);
    }

    return polygon;
}

void printPolygon(Polygon *polygon) {
    for (int i = 0; i < polygon->numVertices; i++) {
        printf("(%f, %f) ", polygon->vertices[i].x, polygon->vertices[i].y);
    }
    printf("\n");
}

int main() {
    int numVertices = 6;
    double xMin = -2;
    double xMax = 2;
    double yMin = -2;
    double yMax = 2;

    Polygon *polygon = generatePolygon(numVertices, xMin, xMax, yMin, yMax);
    printPolygon(polygon);

    return 0;
}