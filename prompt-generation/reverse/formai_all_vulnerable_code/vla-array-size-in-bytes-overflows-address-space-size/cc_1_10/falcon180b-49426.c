//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

typedef struct {
    int x;
    int y;
} Point;

void read_points(Point points[], int n) {
    printf("Enter %d points:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
}

void print_points(Point points[], int n) {
    printf("Points:\n");
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
}

void convex_hull(Point points[], int n) {
    int hull_size = 0;
    Point hull[MAX_POINTS];

    // initialize the convex hull with the first point
    hull[hull_size++] = points[0];

    for (int i = 1; i < n; i++) {
        int j = 0;

        // find the index of the last point in the convex hull
        while (j >= 0 && cross_product(hull[j], hull[j+1], points[i]) <= 0) {
            j--;
        }

        // remove the point that is no longer part of the convex hull
        if (j < 0) {
            hull_size--;
        }

        // add the new point to the convex hull
        hull[hull_size++] = points[i];
    }

    // print the convex hull
    printf("Convex hull:\n");
    for (int i = 0; i < hull_size; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }
}

int cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int main() {
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    if (n > MAX_POINTS) {
        printf("Error: too many points.\n");
        return 1;
    }

    Point points[n];
    read_points(points, n);

    convex_hull(points, n);

    return 0;
}