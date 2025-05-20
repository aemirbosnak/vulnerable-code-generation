//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef struct {
    int x, y;
} Point;

Point create_point(int x, int y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

int distance(Point a, Point b) {
    int dx = abs(a.x - b.x);
    int dy = abs(a.y - b.y);
    return dx + dy;
}

void print_points(Point *points, int n) {
    for (int i = 0; i < n; i++) {
        printf("(%d, %d)\n", points[i].x, points[i].y);
    }
}

void koch_snowflake(Point *points, int n, int depth) {
    if (depth == 0) {
        return;
    }

    Point a = points[n - 1];
    Point b = points[0];
    Point c = create_point(a.x + b.x, a.y + b.y);
    Point d = create_point(a.x + (b.y - a.y), a.y + (b.x - a.x));

    Point *new_points = malloc(sizeof(Point) * 4);
    new_points[0] = a;
    new_points[1] = b;
    new_points[2] = c;
    new_points[3] = d;

    koch_snowflake(new_points, 4, depth - 1);

    free(new_points);
}

int main() {
    int n = 3;
    Point *points = malloc(sizeof(Point) * n);
    points[0] = create_point(0, 0);
    points[1] = create_point(1, 0);
    points[2] = create_point(0, 1);

    koch_snowflake(points, n, 5);

    print_points(points, n);

    free(points);
    return 0;
}