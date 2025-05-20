//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} Shape;

typedef enum {
    CIRCLE,
    SQUARE,
    TRIANGLE
} ShapeType;

Shape *create_shape(ShapeType type) {
    Shape *shape = malloc(sizeof(Shape));
    shape->points = NULL;
    shape->num_points = 0;
    switch (type) {
        case CIRCLE:
            shape->points = malloc(sizeof(Point));
            shape->points[0].x = 0;
            shape->points[0].y = 0;
            shape->num_points = 1;
            break;
        case SQUARE:
            shape->points = malloc(sizeof(Point) * 4);
            shape->points[0].x = 0;
            shape->points[0].y = 0;
            shape->points[1].x = 0;
            shape->points[1].y = 10;
            shape->points[2].x = 10;
            shape->points[2].y = 10;
            shape->points[3].x = 10;
            shape->points[3].y = 0;
            shape->num_points = 4;
            break;
        case TRIANGLE:
            shape->points = malloc(sizeof(Point) * 3);
            shape->points[0].x = 0;
            shape->points[0].y = 0;
            shape->points[1].x = 10;
            shape->points[1].y = 0;
            shape->points[2].x = 5;
            shape->points[2].y = 10;
            shape->num_points = 3;
            break;
        default:
            free(shape);
            return NULL;
    }
    return shape;
}

void draw_shape(Shape *shape) {
    switch (shape->num_points) {
        case 1:
            printf("O");
            break;
        case 4:
            printf("+---+");
            break;
        case 3:
            printf(" /\ ");
            break;
        default:
            break;
    }
}

void free_shape(Shape *shape) {
    if (shape->points) {
        free(shape->points);
    }
    free(shape);
}

int main() {
    Shape *shape = create_shape(CIRCLE);
    draw_shape(shape);
    free_shape(shape);
    return 0;
}