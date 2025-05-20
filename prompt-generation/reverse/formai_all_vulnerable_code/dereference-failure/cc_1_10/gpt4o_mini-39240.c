//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: mathematical
#include <stdio.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point* vertices;
    int num_vertices;
} Polygon;

// Function to calculate the area of the polygon using the Shoelace theorem
double polygonArea(Polygon* poly) {
    double area = 0.0;
    for (int i = 0; i < poly->num_vertices; i++) {
        int j = (i + 1) % poly->num_vertices;
        area += (poly->vertices[i].x * poly->vertices[j].y) - (poly->vertices[j].x * poly->vertices[i].y);
    }
    return 0.5 * area < 0 ? -0.5 * area : 0.5 * area;  // Area must be positive
}

// Function to check if a point is inside the polygon using Ray-Casting algorithm
int isPointInsidePolygon(Polygon* poly, Point pt) {
    int count = 0;
    for (int i = 0; i < poly->num_vertices; i++) {
        int j = (i + 1) % poly->num_vertices;
        
        if (((poly->vertices[i].y <= pt.y) && (pt.y < poly->vertices[j].y)) ||
            ((poly->vertices[j].y <= pt.y) && (pt.y < poly->vertices[i].y))) {
            double vt = (double)(pt.y - poly->vertices[i].y) / (poly->vertices[j].y - poly->vertices[i].y);
            if (pt.x < poly->vertices[i].x + vt * (poly->vertices[j].x - poly->vertices[i].x)) {
                count++;
            }
        }
    }
    return count % 2;  // Odd count indicates the point is inside
}

int main() {
    printf("Geometric Algorithms - Polygon Area and Point Inclusion\n");
    
    // Define vertices for a polygon (Triangle)
    Polygon poly;
    poly.num_vertices = 3;
    poly.vertices = (Point*)malloc(poly.num_vertices * sizeof(Point));
    
    poly.vertices[0] = (Point){0.0, 0.0};
    poly.vertices[1] = (Point){5.0, 0.0};
    poly.vertices[2] = (Point){2.5, 5.0};

    // Compute and print the area of the polygon
    double area = polygonArea(&poly);
    printf("Area of the polygon: %.2f\n", area);

    // Define a point to check
    Point pt1 = {2.5, 2.0};  // Inside
    Point pt2 = {6.0, 2.0};  // Outside

    // Check if point 1 is inside the polygon
    printf("Point (%.2f, %.2f) is %s the polygon.\n", pt1.x, pt1.y, 
           isPointInsidePolygon(&poly, pt1) ? "inside" : "outside");
    
    // Check if point 2 is inside the polygon
    printf("Point (%.2f, %.2f) is %s the polygon.\n", pt2.x, pt2.y, 
           isPointInsidePolygon(&poly, pt2) ? "inside" : "outside");

    // Clean up allocated memory
    free(poly.vertices);

    return 0;
}