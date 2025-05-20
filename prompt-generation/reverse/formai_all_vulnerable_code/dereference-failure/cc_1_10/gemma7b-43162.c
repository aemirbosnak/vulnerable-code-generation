//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct Shape {
    int type;
    union {
        struct Circle {
            int radius;
        } circle;
        struct Rectangle {
            int length;
            int width;
        } rectangle;
    } data;
} Shape;

Shape* createShape(int type, int radius, int length, int width) {
    Shape* shape = (Shape*)malloc(sizeof(Shape));
    shape->type = type;

    switch (type) {
        case 1:
            shape->data.circle.radius = radius;
            break;
        case 2:
            shape->data.rectangle.length = length;
            shape->data.rectangle.width = width;
            break;
    }

    return shape;
}

void printShape(Shape* shape) {
    switch (shape->type) {
        case 1:
            printf("Circle: radius = %d\n", shape->data.circle.radius);
            break;
        case 2:
            printf("Rectangle: length = %d, width = %d\n", shape->data.rectangle.length, shape->data.rectangle.width);
            break;
    }
}

int main() {
    Shape* shape = createShape(1, 5, 0, 0);
    printShape(shape);

    shape = createShape(2, 0, 10, 20);
    printShape(shape);

    return 0;
}