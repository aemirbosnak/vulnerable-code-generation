//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

/**
 * This program calculates the area of a polygon using a recursive algorithm.
 * The polygon is defined by a set of vertices given in clockwise order.
 * We assume that the polygon is simple (i.e., non-self-intersecting).
 */

typedef struct {
    double x;
    double y;
} Point;

double crossProduct(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

double triangleArea(Point a, Point b, Point c) {
    Point ab = {b.x - a.x, b.y - a.y};
    Point ac = {c.x - a.x, c.y - a.y};
    return crossProduct(ab, ac) / 2.0;
}

double polygonArea(Point* polygon, int n) {
    if (n < 3) {
        return 0.0;
    } else {
        double a = triangleArea(polygon[0], polygon[1], polygon[2]);
        Point* newPolygon = (Point*) malloc((n - 1) * sizeof(Point));
        for (int i = 0; i < n - 1; i++) {
            newPolygon[i] = polygon[i + 1];
        }
        return a + polygonArea(newPolygon, n - 1);
    }
}

int main() {
    Point polygon[] = {
        {0.0, 0.0},
        {1.0, 0.0},
        {1.0, 1.0},
        {0.5, 1.0},
        {0.0, 0.5}
    };
    int n = sizeof(polygon) / sizeof(Point);
    double area = polygonArea(polygon, n);
    printf("The polygon has area: %f\n", area);
    return 0;
}