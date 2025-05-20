//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define custom data types
typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point* points;
    int size;
} Polygon;

// Define function to calculate area of a polygon
double get_polygon_area(Polygon* poly) {
    double area = 0.0;

    // Calculate signed area of polygon using shoelace formula
    for (int i = 0; i < poly->size; i++) {
        int j = (i + 1) % poly->size;
        area += (poly->points[i].x * poly->points[j].y) - (poly->points[j].x * poly->points[i].y);
    }

    // Return absolute value of area
    return abs(area / 2);
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Create polygon
    Polygon poly;
    poly.size = 6;
    poly.points = (Point*) malloc(sizeof(Point) * poly.size);
    
    // Generate random points for polygon
    for (int i = 0; i < poly.size; i++) {
        poly.points[i].x = rand() % 10;
        poly.points[i].y = rand() % 10;
    }

    // Calculate area of polygon
    double area = get_polygon_area(&poly);
    printf("Polygon area: %f\n", area);

    // Clean up memory
    free(poly.points);

    return 0;
}