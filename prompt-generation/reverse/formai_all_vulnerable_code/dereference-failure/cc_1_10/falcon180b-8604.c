//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX 1000

typedef struct {
    int x, y;
} Point;

Point* createPoints(int n) {
    Point* points = (Point*)malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % MAX;
        points[i].y = rand() % MAX;
    }
    return points;
}

void printPoints(Point* points, int n) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
}

bool isConvex(Point* points, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int k = (j + 1) % n;
        if ((points[j].y - points[i].y) * (points[k].x - points[j].x) > (points[k].y - points[i].y) * (points[j].x - points[i].x)) {
            count++;
        }
    }
    return count == n;
}

void convexHull(Point* points, int n) {
    Point* hull = (Point*)malloc(n * sizeof(Point));
    int m = 0;
    for (int i = 0; i < n; i++) {
        while (m >= 2 && (hull[m - 2].x - hull[m - 1].x) * (points[i].y - hull[m - 1].y) <= (hull[m - 1].y - hull[m - 2].y) * (points[i].x - hull[m - 1].x)) {
            m--;
        }
        hull[m++] = points[i];
    }
    printf("Convex Hull:\n");
    printPoints(hull, m);
}

int main() {
    int n = 10;
    Point* points = createPoints(n);
    printPoints(points, n);
    convexHull(points, n);
    free(points);
    return 0;
}