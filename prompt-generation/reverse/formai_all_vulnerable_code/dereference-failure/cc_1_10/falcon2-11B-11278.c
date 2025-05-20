//Falcon2-11B DATASET v1.0 Category: Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

struct Shape {
    int x, y, width, height;
};

struct Shape* createShape(int x, int y, int width, int height) {
    struct Shape* shape = malloc(sizeof(struct Shape));
    shape->x = x;
    shape->y = y;
    shape->width = width;
    shape->height = height;
    return shape;
}

void printShape(struct Shape* shape) {
    printf("Shape: %d,%d,%d,%d\n", shape->x, shape->y, shape->width, shape->height);
}

void changeShape(struct Shape* shape) {
    if (shape->width == 1 && shape->height == 1) {
        printf("Shape is already a square!\n");
        return;
    }

    int newX = shape->x;
    int newY = shape->y;
    int newWidth = shape->width - 1;
    int newHeight = shape->height - 1;

    struct Shape* newShape = createShape(newX, newY, newWidth, newHeight);
    printShape(newShape);

    free(shape);
    shape = newShape;
}

int main() {
    struct Shape* shape = createShape(0, 0, 5, 5);
    printShape(shape);

    changeShape(shape);
    printShape(shape);

    changeShape(shape);
    printShape(shape);

    return 0;
}