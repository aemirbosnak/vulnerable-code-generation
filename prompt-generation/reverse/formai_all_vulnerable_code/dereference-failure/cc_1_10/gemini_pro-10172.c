//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} Polygon;

Polygon *createPolygon(int n) {
    Polygon *p = malloc(sizeof(Polygon));
    p->points = malloc(sizeof(Point) * n);
    p->size = n;
    return p;
}

void destroyPolygon(Polygon *p) {
    free(p->points);
    free(p);
}

void addPoint(Polygon *p, Point point) {
    p->points[p->size] = point;
    p->size++;
}

void printPolygon(Polygon *p) {
    for (int i = 0; i < p->size; i++) {
        printf("(%d, %d)\n", p->points[i].x, p->points[i].y);
    }
}

int main() {
    Polygon *p = createPolygon(4);

    Point point1 = {0, 0};
    Point point2 = {10, 0};
    Point point3 = {10, 10};
    Point point4 = {0, 10};

    addPoint(p, point1);
    addPoint(p, point2);
    addPoint(p, point3);
    addPoint(p, point4);

    printPolygon(p);

    destroyPolygon(p);

    return 0;
}