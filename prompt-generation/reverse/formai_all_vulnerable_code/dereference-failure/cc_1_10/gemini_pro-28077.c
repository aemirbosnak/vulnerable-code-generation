//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
    int z;
} Point;

typedef struct {
    Point points[MAX_SIZE];
    int size;
} PointSet;

PointSet* createPointSet() {
    PointSet* pointSet = (PointSet*) malloc(sizeof(PointSet));
    pointSet->size = 0;
    return pointSet;
}

void addPoint(PointSet* pointSet, Point point) {
    if (pointSet->size >= MAX_SIZE) {
        printf("Error: Point set is full.\n");
        return;
    }
    pointSet->points[pointSet->size] = point;
    pointSet->size++;
}

void printPointSet(PointSet* pointSet) {
    for (int i = 0; i < pointSet->size; i++) {
        printf("(%d, %d, %d)\n", pointSet->points[i].x, pointSet->points[i].y, pointSet->points[i].z);
    }
}

int main() {
    PointSet* pointSet = createPointSet();

    Point point1 = {1, 2, 3};
    Point point2 = {4, 5, 6};
    Point point3 = {7, 8, 9};

    addPoint(pointSet, point1);
    addPoint(pointSet, point2);
    addPoint(pointSet, point3);

    printPointSet(pointSet);

    return 0;
}