//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point *points;
    int n; // Number of points
} Polygon;

// Function to calculate the area of a polygon using the shoelace formula
double polygon_area(Polygon *poly) {
    double area = 0.0;
    for (int i = 0; i < poly->n; i++) {
        Point p1 = poly->points[i];
        Point p2 = poly->points[(i + 1) % poly->n];
        area += (p1.x * p2.y) - (p2.x * p1.y);
    }
    return fabs(area) / 2.0;
}

// Function to check if two lines intersect
int do_lines_intersect(Point p1, Point p2, Point p3, Point p4) {
    double d1 = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
    double d2 = (p2.x - p1.x) * (p4.y - p1.y) - (p2.y - p1.y) * (p4.x - p1.x);
    double d3 = (p4.x - p3.x) * (p1.y - p3.y) - (p4.y - p3.y) * (p1.x - p3.x);
    double d4 = (p4.x - p3.x) * (p2.y - p3.y) - (p4.y - p3.y) * (p2.x - p3.x);
    
    if ((d1 * d2 < 0) && (d3 * d4 < 0)) return 1; // Lines intersect
    return 0; // Lines do not intersect
}

// Function to check if two polygons intersect
int do_polygons_intersect(Polygon *a, Polygon *b) {
    for (int i = 0; i < a->n; i++) {
        Point p1 = a->points[i];
        Point p2 = a->points[(i + 1) % a->n];
        for (int j = 0; j < b->n; j++) {
            Point p3 = b->points[j];
            Point p4 = b->points[(j + 1) % b->n];
            if (do_lines_intersect(p1, p2, p3, p4)) {
                return 1; // Polygons intersect
            }
        }
    }
    return 0; // Polygons do not intersect
}

// Function to create a polygon
Polygon create_polygon(Point *points, int n) {
    Polygon poly;
    poly.points = (Point *)malloc(n * sizeof(Point));
    poly.n = n;
    for (int i = 0; i < n; i++) {
        poly.points[i] = points[i];
    }
    return poly;
}

// Function to free the polygon
void free_polygon(Polygon *poly) {
    free(poly->points);
}

// Main function
int main() {
    Point poly1_points[] = {
        {0, 0}, {4, 0}, {4, 4}, {0, 4}
    };

    Point poly2_points[] = {
        {2, 2}, {6, 2}, {6, 6}, {2, 6}
    };

    Polygon poly1 = create_polygon(poly1_points, 4);
    Polygon poly2 = create_polygon(poly2_points, 4);

    printf("Area of Polygon 1: %.2f\n", polygon_area(&poly1));
    printf("Area of Polygon 2: %.2f\n", polygon_area(&poly2));

    if (do_polygons_intersect(&poly1, &poly2)) {
        printf("Polygons intersect.\n");
    } else {
        printf("Polygons do not intersect.\n");
    }

    // Clean up
    free_polygon(&poly1);
    free_polygon(&poly2);

    return 0;
}