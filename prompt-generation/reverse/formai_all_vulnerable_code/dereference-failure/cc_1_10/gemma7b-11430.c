//Gemma-7B DATASET v1.0 Category: Performance-Critical Component ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct Shape
{
    int type;
    union
    {
        struct Circle
        {
            int radius;
        } circle;

        struct Rectangle
        {
            int length;
            int width;
        } rectangle;

        struct Triangle
        {
            int sideA;
            int sideB;
            int sideC;
        } triangle;
    } data;
} Shape;

void drawShape(Shape* shape)
{
    switch (shape->type)
    {
        case 1:
            printf("Drawing a circle with radius %d\n", shape->data.circle.radius);
            break;
        case 2:
            printf("Drawing a rectangle with length %d and width %d\n", shape->data.rectangle.length, shape->data.rectangle.width);
            break;
        case 3:
            printf("Drawing a triangle with side A %d, side B %d, and side C %d\n", shape->data.triangle.sideA, shape->data.triangle.sideB, shape->data.triangle.sideC);
            break;
    }
}

int main()
{
    Shape* shape = malloc(sizeof(Shape));
    shape->type = 2;
    shape->data.rectangle.length = 10;
    shape->data.rectangle.width = 20;

    drawShape(shape);

    free(shape);

    return 0;
}