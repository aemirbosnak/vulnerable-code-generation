//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct Point {
    double x;
    double y;
} Point;

typedef struct ConvexHull {
    Point *points;
    int numPoints;
} ConvexHull;

int comparePoints(const void *p1, const void *p2) {
    Point *point1 = (Point *) p1;
    Point *point2 = (Point *) p2;
    
    if (point1->x < point2->x) {
        return -1;
    }
    if (point1->x > point2->x) {
        return 1;
    }
    if (point1->y < point2->y) {
        return -1;
    }
    if (point1->y > point2->y) {
        return 1;
    }
    return 0;
}

double crossProduct(Point p1, Point p2, Point p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

ConvexHull *grahamScan(ConvexHull *hull) {
    qsort(hull->points, hull->numPoints, sizeof(Point), comparePoints);
    
    Point *stack[hull->numPoints];
    int stackPointer = 0;
    for (int i = 0; i < hull->numPoints; i++) {
        while (stackPointer > 1 && crossProduct(*stack[stackPointer - 2], *stack[stackPointer - 1], hull->points[i]) <= 0) {
            stackPointer--;
        }
        stack[stackPointer++] = &hull->points[i];
    }
    
    int lowerHull = 0;
    for (int i = 1; i < stackPointer; i++) {
        if (stack[i]->y < stack[lowerHull]->y) {
            lowerHull = i;
        }
    }
    
    int upperHull = stackPointer - 1;
    for (int i = stackPointer - 2; i >= 0; i--) {
        if (stack[i]->y > stack[upperHull]->y) {
            upperHull = i;
        }
    }
    
    ConvexHull *convexHull = (ConvexHull *) malloc(sizeof(ConvexHull));
    convexHull->numPoints = upperHull - lowerHull + 1;
    convexHull->points = (Point *) malloc(sizeof(Point) * convexHull->numPoints);
    for (int i = lowerHull, j = 0; i <= upperHull; i++, j++) {
        convexHull->points[j] = *stack[i];
    }
    
    return convexHull;
}

int main() {
    ConvexHull *hull = (ConvexHull *) malloc(sizeof(ConvexHull));
    hull->numPoints = 5;
    hull->points = (Point *) malloc(sizeof(Point) * hull->numPoints);
    
    hull->points[0].x = 0.0;
    hull->points[0].y = 0.0;
    
    hull->points[1].x = 1.0;
    hull->points[1].y = 2.0;
    
    hull->points[2].x = 2.0;
    hull->points[2].y = 0.0;
    
    hull->points[3].x = 3.0;
    hull->points[3].y = 1.0;
    
    hull->points[4].x = 2.0;
    hull->points[4].y = 2.0;
    
    ConvexHull *convexHull = grahamScan(hull);
    
    printf("Convex Hull:\n");
    for (int i = 0; i < convexHull->numPoints; i++) {
        printf("(%f, %f)\n", convexHull->points[i].x, convexHull->points[i].y);
    }
    
    free(hull->points);
    free(hull);
    free(convexHull->points);
    free(convexHull);
    
    return 0;
}