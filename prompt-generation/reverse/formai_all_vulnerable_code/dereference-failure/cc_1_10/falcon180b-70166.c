//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point* points;
    int size;
} Polygon;

void printPolygon(Polygon* polygon) {
    for (int i = 0; i < polygon->size; i++) {
        printf("(%d,%d) ", polygon->points[i].x, polygon->points[i].y);
    }
    printf("\n");
}

void addPoint(Polygon* polygon, int x, int y) {
    polygon->points = realloc(polygon->points, sizeof(Point) * (polygon->size + 1));
    polygon->points[polygon->size].x = x;
    polygon->points[polygon->size].y = y;
    polygon->size++;
}

void generateFractal(int size, int depth) {
    Polygon* polygon = malloc(sizeof(Polygon));
    polygon->points = malloc(sizeof(Point) * 3);
    polygon->size = 3;

    addPoint(polygon, 0, 0);
    addPoint(polygon, size, 0);
    addPoint(polygon, size, size);

    for (int i = 0; i < depth; i++) {
        Polygon* newPolygon = malloc(sizeof(Polygon));
        newPolygon->points = malloc(sizeof(Point) * 3);
        newPolygon->size = 3;

        addPoint(newPolygon, 0, 0);
        addPoint(newPolygon, size / 2, 0);
        addPoint(newPolygon, size / 2, size / 2);
        addPoint(newPolygon, size, size / 2);
        addPoint(newPolygon, size, 0);
        addPoint(newPolygon, 0, size / 2);
        addPoint(newPolygon, size / 2, size);
        addPoint(newPolygon, size, size);

        for (int j = 0; j < 3; j++) {
            addPoint(polygon, newPolygon->points[j].x, newPolygon->points[j].y);
        }

        free(newPolygon->points);
        free(newPolygon);
    }

    printPolygon(polygon);

    for (int i = 0; i < polygon->size; i++) {
        free(polygon->points[i].x);
        free(polygon->points[i].y);
    }
    free(polygon->points);
    free(polygon);
}

int main() {
    generateFractal(500, 5);
    return 0;
}