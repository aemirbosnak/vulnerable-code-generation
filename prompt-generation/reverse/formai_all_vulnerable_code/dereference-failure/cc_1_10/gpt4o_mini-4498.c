//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int size;
} Polygon;

Polygon* create_polygon(int num_points) {
    Polygon *poly = (Polygon*)malloc(sizeof(Polygon));
    poly->points = (Point*)malloc(num_points * sizeof(Point));
    poly->size = num_points;
    return poly;
}

void delete_polygon(Polygon *poly) {
    free(poly->points);
    free(poly);
}

void set_point(Polygon *poly, int index, double x, double y) {
    if (index >= 0 && index < poly->size) {
        poly->points[index].x = x;
        poly->points[index].y = y;
    }
}

double area(Polygon *poly) {
    double total_area = 0.0;
    int j = poly->size - 1;

    for (int i = 0; i < poly->size; i++) {
        total_area += (poly->points[j].x + poly->points[i].x) * 
                      (poly->points[j].y - poly->points[i].y);
        j = i;  
    }
    return fabs(total_area / 2.0);
}

double distance(Point a, Point b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

void print_polygon(Polygon *poly) {
    for (int i = 0; i < poly->size; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i, poly->points[i].x, poly->points[i].y);
    }
}

int main() {
    int num_points;
    printf("Enter number of points in the polygon: ");
    scanf("%d", &num_points);

    if (num_points < 3) {
        printf("A polygon must have at least 3 points.\n");
        return -1;
    }

    Polygon *polygon = create_polygon(num_points);
    
    for (int i = 0; i < num_points; i++) {
        double x, y;
        printf("Enter coordinates for point %d (x y): ", i);
        scanf("%lf %lf", &x, &y);
        set_point(polygon, i, x, y);
    }

    print_polygon(polygon);

    double poly_area = area(polygon);
    printf("The area of the polygon is: %.2f\n", poly_area);

    printf("Distances between consecutive points:\n");
    for (int i = 0; i < num_points; i++) {
        int next = (i + 1) % num_points;
        double dist = distance(polygon->points[i], polygon->points[next]);
        printf("Distance from Point %d to Point %d: %.2f\n", i, next, dist);
    }

    delete_polygon(polygon);
    return 0;
}