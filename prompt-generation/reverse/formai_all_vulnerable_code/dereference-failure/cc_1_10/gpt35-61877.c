//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complex
#include <stdio.h>
#include <math.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    int size;
    Point* points;
} Polygon;

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double perimeter(Polygon* polygon) {
    double p = 0;
    for(int i = 0; i < polygon->size; ++i) {
        p += distance(polygon->points[i], polygon->points[(i+1)%polygon->size]);
    }
    return p;
}

double area(Polygon* polygon) {
    double a = 0;
    for(int i = 0; i < polygon->size; ++i) {
        a += polygon->points[i].x * polygon->points[(i+1)%polygon->size].y - polygon->points[(i+1)%polygon->size].x * polygon->points[i].y;
    }
    return 0.5 * a;
}

double angle(Point p1, Point p2) {
    return atan2(p2.y - p1.y, p2.x - p1.x);
}

double orientation(Point p1, Point p2, Point p3) {
    double val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

Polygon convexHull(Polygon* polygon) {
    if (polygon->size <= 2) return *polygon;

    Polygon hull;
    hull.size = 0;
    hull.points = (Point*)malloc((2 * polygon->size) * sizeof(Point));

    int l = 0;
    for(int i = 1; i < polygon->size; ++i) {
        if (polygon->points[i].x < polygon->points[l].x) {
            l = i;
        }
    }

    int p = l, q;
    do {
        hull.points[hull.size++] = polygon->points[p];
        q = (p + 1) % polygon->size;
        for(int i = 0; i < polygon->size; ++i) {
            if (orientation(polygon->points[p], polygon->points[i], polygon->points[q]) == 2) {
                q = i;
            }
        }
        p = q;
    } while (p != l);

    hull.points = (Point*)realloc(hull.points, hull.size * sizeof(Point));
    return hull;
}

int main() {
    Polygon polygon;
    polygon.size = 4;
    polygon.points = (Point*)malloc(polygon.size * sizeof(Point));
    polygon.points[0].x = 1; polygon.points[0].y = 1;
    polygon.points[1].x = 2; polygon.points[1].y = 3;
    polygon.points[2].x = 4; polygon.points[2].y = 2;
    polygon.points[3].x = 3; polygon.points[3].y = 1;

    Polygon hull = convexHull(&polygon);
    printf("Polygon area: %lf\n", area(&polygon));
    printf("Conver hull perimeter: %lf\n", perimeter(&hull));

    free(polygon.points);
    free(hull.points);

    return 0;
}