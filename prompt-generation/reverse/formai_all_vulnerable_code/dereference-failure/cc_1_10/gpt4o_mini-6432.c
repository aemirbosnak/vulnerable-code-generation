//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point* vertices;
    int vertexCount;
} Polygon;

// Function to determine whether a point lies inside a polygon
int isInside(Polygon* polygon, Point p) {
    int count = 0;
    double xIntersect;
    int n = polygon->vertexCount;

    for (int i = 0; i < n; i++) {
        Point v1 = polygon->vertices[i];
        Point v2 = polygon->vertices[(i + 1) % n];

        // Check if edge crosses the line from point to the right
        if (((v1.y > p.y) != (v2.y > p.y)) &&
            (p.x < (v2.x - v1.x) * (p.y - v1.y) / (v2.y - v1.y) + v1.x)) {
            count++;
        }
    }
    return count % 2; // Inside polygon if odd number of crossings
}

// Function to create a polygon
Polygon createPolygon(Point* vertices, int vertexCount) {
    Polygon polygon;
    polygon.vertices = (Point*)malloc(vertexCount * sizeof(Point));
    for (int i = 0; i < vertexCount; i++) {
        polygon.vertices[i] = vertices[i];
    }
    polygon.vertexCount = vertexCount;
    return polygon;
}

// Function to free memory allocated for polygon
void freePolygon(Polygon* polygon) {
    free(polygon->vertices);
}

// Main function
int main() {
    // Define a simple polygon (a square)
    Point vertices[] = {
        {0, 0},
        {5, 0},
        {5, 5},
        {0, 5}
    };
    int vertexCount = sizeof(vertices) / sizeof(vertices[0]);

    // Create the polygon
    Polygon polygon = createPolygon(vertices, vertexCount);

    // Points to test
    Point testPoints[] = {
        {1, 1},   // Inside
        {3, 3},   // Inside
        {5, 1},   // On edge
        {6, 6},   // Outside
        {2.5, 5}, // On edge
        {5, 5}    // Vertex
    };
    int testPointCount = sizeof(testPoints) / sizeof(testPoints[0]);

    // Check each test point
    for (int i = 0; i < testPointCount; i++) {
        int result = isInside(&polygon, testPoints[i]);
        if (result) {
            printf("Point (%.2f, %.2f) is inside the polygon.\n", testPoints[i].x, testPoints[i].y);
        } else {
            printf("Point (%.2f, %.2f) is outside the polygon.\n", testPoints[i].x, testPoints[i].y);
        }
    }

    // Free allocated memory for polygon
    freePolygon(&polygon);

    return 0;
}