//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>
#include <float.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

#define PI 3.14159265358979323846
#define MAX_SIZE 100
#define MIN_SIZE 10

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *vertices;
    int numVertices;
} Polygon;

void generateRandomPolygon(Polygon *polygon) {
    srand(time(NULL));
    polygon->numVertices = rand() % MAX_SIZE + MIN_SIZE;
    polygon->vertices = malloc(polygon->numVertices * sizeof(Point));
    for (int i = 0; i < polygon->numVertices; i++) {
        polygon->vertices[i].x = rand() % 1000 - 500;
        polygon->vertices[i].y = rand() % 1000 - 500;
    }
}

int isConvex(Polygon *polygon) {
    int prevCrossProduct = 0;
    int currentCrossProduct = 0;
    for (int i = 0; i < polygon->numVertices; i++) {
        Point *currentVertex = &polygon->vertices[i];
        Point *prevVertex = &polygon->vertices[(i + polygon->numVertices - 1) % polygon->numVertices];
        Point *nextVertex = &polygon->vertices[(i + 1) % polygon->numVertices];
        currentCrossProduct = (currentVertex->x - prevVertex->x) * (nextVertex->y - prevVertex->y) - (currentVertex->y - prevVertex->y) * (nextVertex->x - prevVertex->x);
        if (currentCrossProduct * prevCrossProduct < 0) {
            return 0;
        }
        prevCrossProduct = currentCrossProduct;
    }
    return 1;
}

int isConcave(Polygon *polygon) {
    return!isConvex(polygon);
}

int main() {
    Polygon polygon;
    generateRandomPolygon(&polygon);
    if (isConvex(&polygon)) {
        printf("The polygon is convex.\n");
    } else {
        printf("The polygon is concave.\n");
    }
    return 0;
}