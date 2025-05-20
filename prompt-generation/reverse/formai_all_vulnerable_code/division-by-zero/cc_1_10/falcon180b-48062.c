//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Polygon;

void read_points(Polygon *poly) {
    printf("Enter number of vertices (max %d): ", MAX_POINTS);
    scanf("%d", &poly->num_points);

    poly->points = (Point *) malloc(poly->num_points * sizeof(Point));

    for (int i = 0; i < poly->num_points; i++) {
        printf("Enter vertex %d (x,y): ", i + 1);
        scanf("%d,%d", &poly->points[i].x, &poly->points[i].y);
    }
}

void print_polygon(Polygon *poly) {
    for (int i = 0; i < poly->num_points; i++) {
        printf("(%d,%d) ", poly->points[i].x, poly->points[i].y);
    }
    printf("\n");
}

int is_convex(Polygon *poly) {
    int n = poly->num_points;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int k = (j + 1) % n;

        Point a = poly->points[i];
        Point b = poly->points[j];
        Point c = poly->points[k];

        int cross_product = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);

        if (cross_product < 0) {
            sum++;
        }
    }

    return (sum % n == 0);
}

int is_concave(Polygon *poly) {
    return!is_convex(poly);
}

int main() {
    Polygon poly;
    read_points(&poly);
    printf("Polygon: ");
    print_polygon(&poly);

    if (is_convex(&poly)) {
        printf("The polygon is convex.\n");
    } else {
        printf("The polygon is concave.\n");
    }

    return 0;
}