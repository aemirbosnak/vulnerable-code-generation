//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.14159265358979323846
#define MAX_POINTS 1000000

typedef struct {
    double x;
    double y;
} Point;

void generatePoints(int n, Point *points) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        points[i].x = rand() % 1000;
        points[i].y = rand() % 1000;
    }
}

void sortPoints(int n, Point *points) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (points[i].x > points[j].x) {
                Point temp = points[i];
                points[i] = points[j];
                points[j] = temp;
            }
        }
    }
}

int convexHull(int n, Point *points) {
    int hullSize = 0;
    Point *hull = (Point *) malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        if (hullSize == 0) {
            hull[hullSize++] = points[i];
        } else {
            int j = 0;
            while (j < hullSize - 1 && (hull[j].x - points[i].x) * (hull[j + 1].y - points[i].y) > (hull[j + 1].x - points[i].x) * (hull[j].y - points[i].y)) {
                j++;
            }
            if (j == hullSize - 1) {
                hull[hullSize++] = points[i];
            }
        }
    }
    free(hull);
    return hullSize;
}

int main(int argc, char *argv[]) {
    int n;
    Point *points;

    printf("Enter the number of points: ");
    scanf("%d", &n);

    points = (Point *) malloc(n * sizeof(Point));

    generatePoints(n, points);

    sortPoints(n, points);

    int hullSize = convexHull(n, points);

    printf("The convex hull has %d points.\n", hullSize);

    free(points);

    return 0;
}