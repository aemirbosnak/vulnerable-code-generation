//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Shape {
    int width;
    int height;
    char **data;
} Shape;

Shape *createShape(int w, int h) {
    Shape *shape = malloc(sizeof(Shape));
    shape->width = w;
    shape->height = h;
    shape->data = malloc(h * w * sizeof(char));
    return shape;
}

void drawShape(Shape *shape) {
    for (int r = 0; r < shape->height; r++) {
        for (int c = 0; c < shape->width; c++) {
            printf("%c ", shape->data[r * shape->width + c]);
        }
        printf("\n");
    }
}

int main() {
    Shape *shape = createShape(5, 5);

    // Draw a rectangle
    shape->data[0] = 'X';
    shape->data[1] = 'X';
    shape->data[2] = 'X';
    shape->data[3] = 'X';
    shape->data[4] = 'X';

    // Draw a circle
    shape->data[10] = 'O';
    shape->data[11] = 'O';
    shape->data[12] = 'O';
    shape->data[13] = 'O';

    drawShape(shape);

    free(shape->data);
    free(shape);

    return 0;
}