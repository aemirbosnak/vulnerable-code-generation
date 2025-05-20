//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point* points;
    int count;
} Polygon;

Polygon* create_polygon(int count) {
    Polygon* polygon = (Polygon*)malloc(sizeof(Polygon));
    polygon->points = (Point*)malloc(count * sizeof(Point));
    polygon->count = count;
    return polygon;
}

void free_polygon(Polygon* polygon) {
    free(polygon->points);
    free(polygon);
}

double area_of_polygon(Polygon* polygon) {
    double area = 0.0;
    for (int i = 0; i < polygon->count; i++) {
        int j = (i + 1) % polygon->count;
        area += (polygon->points[i].x * polygon->points[j].y);
        area -= (polygon->points[j].x * polygon->points[i].y);
    }
    return fabs(area) / 2.0;
}

void print_polygon(Polygon* polygon) {
    printf("Polygon with %d vertices:\n", polygon->count);
    for (int i = 0; i < polygon->count; i++) {
        printf("Vertex %d: (%.2f, %.2f)\n", i + 1, polygon->points[i].x, polygon->points[i].y);
    }
}

int main() {
    int n;
    printf("Enter the number of vertices for the polygon (maximum %d): ", MAX_POINTS);
    scanf("%d", &n);

    if (n < 3 || n > MAX_POINTS) {
        printf("A polygon must have at least 3 vertices and cannot exceed %d.\n", MAX_POINTS);
        return 1;
    }

    Polygon* polygon = create_polygon(n);
    
    printf("Enter the coordinates of the vertices (x y):\n");
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i + 1);
        scanf("%lf %lf", &polygon->points[i].x, &polygon->points[i].y);
    }

    print_polygon(polygon);
    
    double area = area_of_polygon(polygon);
    printf("The area of the polygon is: %.2f\n", area);

    free_polygon(polygon);
    return 0;
}