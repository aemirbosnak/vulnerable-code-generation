//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Polygon;

// Function to calculate the area of a polygon using the Shoelace theorem
double areaOfPolygon(Polygon *poly) {
    double area = 0.0;
    for (int i = 0; i < poly->num_points; i++) {
        int j = (i + 1) % poly->num_points; // Wrap around
        area += (poly->points[i].x * poly->points[j].y) - (poly->points[j].x * poly->points[i].y);
    }
    return fabs(area) / 2.0;
}

// Function to check if a point is inside a polygon using the ray-casting algorithm
int isPointInPolygon(Polygon *poly, Point p) {
    int count = 0;
    for (int i = 0; i < poly->num_points; i++) {
        int j = (i + 1) % poly->num_points;
        // Check if the point is on an edge
        if ((poly->points[i].y > p.y) != (poly->points[j].y > p.y) &&
            (p.x < (poly->points[j].x - poly->points[i].x) * (p.y - poly->points[i].y) /
            (poly->points[j].y - poly->points[i].y) + poly->points[i].x)) {
            count++;
        }
    }
    return count % 2 == 1; // Odd count means the point is inside
}

// Function to create a polygon from a list of points
Polygon* createPolygon(Point points[], int num_points) {
    Polygon *poly = (Polygon *)malloc(sizeof(Polygon));
    poly->points = (Point *)malloc(num_points * sizeof(Point));
    poly->num_points = num_points;
    for (int i = 0; i < num_points; i++) {
        poly->points[i] = points[i];
    }
    return poly;
}

// Function to free memory allocated for the polygon
void freePolygon(Polygon *poly) {
    free(poly->points);
    free(poly);
}

// Function to print the points of the polygon
void printPolygon(Polygon *poly) {
    printf("Polygon with %d points:\n", poly->num_points);
    for (int i = 0; i < poly->num_points; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, poly->points[i].x, poly->points[i].y);
    }
}

int main() {
    // Create a simple polygon (a triangle in this case)
    Point points[] = {
        {0.0, 0.0},
        {5.0, 0.0},
        {2.5, 5.0}
    };
    int num_points = sizeof(points) / sizeof(points[0]);

    Polygon *poly = createPolygon(points, num_points);

    // Print the polygon
    printPolygon(poly);

    // Calculate and print the area of the polygon
    double area = areaOfPolygon(poly);
    printf("Area of the polygon: %.2f\n", area);

    // Test points
    Point testPoint1 = {2.5, 1.0};
    Point testPoint2 = {6.0, 1.0};

    // Check if test points are inside the polygon
    if (isPointInPolygon(poly, testPoint1)) {
        printf("Point (%.2f, %.2f) is inside the polygon.\n", testPoint1.x, testPoint1.y);
    } else {
        printf("Point (%.2f, %.2f) is outside the polygon.\n", testPoint1.x, testPoint1.y);
    }

    if (isPointInPolygon(poly, testPoint2)) {
        printf("Point (%.2f, %.2f) is inside the polygon.\n", testPoint2.x, testPoint2.y);
    } else {
        printf("Point (%.2f, %.2f) is outside the polygon.\n", testPoint2.x, testPoint2.y);
    }

    // Clean up
    freePolygon(poly);
    return 0;
}