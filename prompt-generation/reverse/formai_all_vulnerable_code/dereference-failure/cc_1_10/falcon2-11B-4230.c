//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point* points;
    int numPoints;
} Shape;

Shape* createShape(int numPoints) {
    Shape* shape = (Shape*)malloc(sizeof(Shape));
    shape->points = (Point*)malloc(numPoints * sizeof(Point));
    shape->numPoints = numPoints;
    return shape;
}

void destroyShape(Shape* shape) {
    free(shape->points);
    free(shape);
}

void printShape(Shape* shape) {
    for (int i = 0; i < shape->numPoints; i++) {
        printf("(%d, %d) ", shape->points[i].x, shape->points[i].y);
    }
    printf("\n");
}

int main() {
    Shape* shape1 = createShape(4);
    shape1->points[0].x = 10;
    shape1->points[0].y = 10;
    shape1->points[1].x = 20;
    shape1->points[1].y = 10;
    shape1->points[2].x = 30;
    shape1->points[2].y = 20;
    shape1->points[3].x = 40;
    shape1->points[3].y = 30;

    printShape(shape1);

    destroyShape(shape1);

    return 0;
}