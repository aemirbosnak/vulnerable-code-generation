//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Point structure
typedef struct {
    double x;
    double y;
} Point;

// Vector structure
typedef struct {
    double x;
    double y;
} Vector;

// Create a point
Point* createPoint(double x, double y) {
    Point* point = malloc(sizeof(Point));
    point->x = x;
    point->y = y;
    return point;
}

// Create a vector
Vector* createVector(double x, double y) {
    Vector* vector = malloc(sizeof(Vector));
    vector->x = x;
    vector->y = y;
    return vector;
}

// Free a point
void freePoint(Point* point) {
    free(point);
}

// Free a vector
void freeVector(Vector* vector) {
    free(vector);
}

// Add two points
Point* addPoints(Point* p1, Point* p2) {
    Point* point = createPoint(p1->x + p2->x, p1->y + p2->y);
    return point;
}

// Subtract two points
Point* subtractPoints(Point* p1, Point* p2) {
    Point* point = createPoint(p1->x - p2->x, p1->y - p2->y);
    return point;
}

// Dot product of two vectors
double dotProduct(Vector* v1, Vector* v2) {
    return v1->x * v2->x + v1->y * v2->y;
}

// Cross product of two vectors
double crossProduct(Vector* v1, Vector* v2) {
    return v1->x * v2->y - v1->y * v2->x;
}

// Magnitude of a vector
double magnitude(Vector* vector) {
    return sqrt(vector->x * vector->x + vector->y * vector->y);
}

// Normalize a vector
Vector* normalize(Vector* vector) {
    double mag = magnitude(vector);
    Vector* normalizedVector = createVector(vector->x / mag, vector->y / mag);
    return normalizedVector;
}

// Reflect a vector about a normal vector
Vector* reflectVector(Vector* vector, Vector* normal) {
    Vector* reflectedVector = createVector(vector->x - 2 * dotProduct(vector, normal) * normal->x, vector->y - 2 * dotProduct(vector, normal) * normal->y);
    return reflectedVector;
}

// Find the intersection of two lines
Point* lineIntersection(Point* p1, Point* p2, Point* q1, Point* q2) {
    Vector* v1 = subtractPoints(p2, p1);
    Vector* v2 = subtractPoints(q2, q1);
    double t = crossProduct(v1, v2) / crossProduct(v1, subtractPoints(q1, p1));
    Point* intersection = addPoints(p1, createVector(t * v1->x, t * v1->y));
    return intersection;
}

// Find the area of a triangle
double triangleArea(Point* p1, Point* p2, Point* p3) {
    Vector* v1 = subtractPoints(p2, p1);
    Vector* v2 = subtractPoints(p3, p1);
    return 0.5 * fabs(crossProduct(v1, v2));
}

// Find the centroid of a triangle
Point* triangleCentroid(Point* p1, Point* p2, Point* p3) {
    Point* centroid = createPoint((p1->x + p2->x + p3->x) / 3, (p1->y + p2->y + p3->y) / 3);
    return centroid;
}

// Find the circumcenter of a triangle
Point* triangleCircumcenter(Point* p1, Point* p2, Point* p3) {
    Vector* v1 = subtractPoints(p2, p1);
    Vector* v2 = subtractPoints(p3, p1);
    double d1 = v1->x * v1->x + v1->y * v1->y;
    double d2 = v2->x * v2->x + v2->y * v2->y;
    double det = v1->x * v2->y - v1->y * v2->x;
    Point* circumcenter = createPoint((d1 * v2->y - d2 * v1->y) / (2 * det), (d2 * v1->x - d1 * v2->x) / (2 * det));
    return circumcenter;
}

int main() {
    // Create three points
    Point* p1 = createPoint(0, 0);
    Point* p2 = createPoint(1, 0);
    Point* p3 = createPoint(0, 1);

    // Find the area of the triangle
    double area = triangleArea(p1, p2, p3);
    printf("The area of the triangle is: %f\n", area);

    // Find the centroid of the triangle
    Point* centroid = triangleCentroid(p1, p2, p3);
    printf("The centroid of the triangle is: (%f, %f)\n", centroid->x, centroid->y);

    // Find the circumcenter of the triangle
    Point* circumcenter = triangleCircumcenter(p1, p2, p3);
    printf("The circumcenter of the triangle is: (%f, %f)\n", circumcenter->x, circumcenter->y);

    // Free the points
    freePoint(p1);
    freePoint(p2);
    freePoint(p3);

    return 0;
}