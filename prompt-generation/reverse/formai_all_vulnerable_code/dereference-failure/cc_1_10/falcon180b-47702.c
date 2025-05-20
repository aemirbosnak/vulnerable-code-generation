//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int n;
} Polygon;

void generate_random_points(Point *points, int n) {
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % 1000;
        points[i].y = rand() % 1000;
    }
}

void convex_hull(Polygon *polygon) {
    int n = polygon->n;
    Point *points = polygon->points;
    int i = 0;

    while (i < n) {
        int j = (i + 1) % n;
        while (j < n) {
            if (points[j].y < points[i].y) {
                i = j;
            }
            j = (j + 1) % n;
        }
        i = (i + 1) % n;
    }

    for (int k = 0; k < n; k++) {
        if (k!= i) {
            points[k] = points[i];
        }
    }
    polygon->n = i + 1;
}

int main() {
    srand(time(NULL));

    int n = 100000;
    Point *points = malloc(n * sizeof(Point));
    generate_random_points(points, n);

    Polygon polygon;
    polygon.points = points;
    polygon.n = n;

    convex_hull(&polygon);

    for (int i = 0; i < polygon.n; i++) {
        printf("%d %d\n", polygon.points[i].x, polygon.points[i].y);
    }

    free(points);
    return 0;
}