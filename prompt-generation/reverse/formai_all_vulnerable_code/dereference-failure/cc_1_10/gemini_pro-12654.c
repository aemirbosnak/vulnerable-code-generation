//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

struct point {
    int x;
    int y;
};

struct rectangle {
    struct point top_left;
    struct point bottom_right;
};

struct circle {
    struct point center;
    int radius;
};

enum shape_type {
    SHAPE_POINT,
    SHAPE_RECTANGLE,
    SHAPE_CIRCLE
};

struct shape {
    enum shape_type type;
    void *data;
};

void *allocate_shape(enum shape_type type) {
    switch (type) {
        case SHAPE_POINT:
            return malloc(sizeof(struct point));
        case SHAPE_RECTANGLE:
            return malloc(sizeof(struct rectangle));
        case SHAPE_CIRCLE:
            return malloc(sizeof(struct circle));
        default:
            return NULL;
    }
}

void free_shape(void *shape) {
    free(shape);
}

struct point *create_point(int x, int y) {
    struct point *point = allocate_shape(SHAPE_POINT);
    if (point == NULL) {
        return NULL;
    }
    point->x = x;
    point->y = y;
    return point;
}

struct rectangle *create_rectangle(struct point top_left, struct point bottom_right) {
    struct rectangle *rectangle = allocate_shape(SHAPE_RECTANGLE);
    if (rectangle == NULL) {
        return NULL;
    }
    rectangle->top_left = top_left;
    rectangle->bottom_right = bottom_right;
    return rectangle;
}

struct circle *create_circle(struct point center, int radius) {
    struct circle *circle = allocate_shape(SHAPE_CIRCLE);
    if (circle == NULL) {
        return NULL;
    }
    circle->center = center;
    circle->radius = radius;
    return circle;
}

void print_shape(struct shape *shape) {
    switch (shape->type) {
        case SHAPE_POINT:
            printf("Point: (%d, %d)\n", ((struct point *)shape->data)->x, ((struct point *)shape->data)->y);
            break;
        case SHAPE_RECTANGLE:
            printf("Rectangle: (%d, %d) - (%d, %d)\n", ((struct rectangle *)shape->data)->top_left.x, ((struct rectangle *)shape->data)->top_left.y, ((struct rectangle *)shape->data)->bottom_right.x, ((struct rectangle *)shape->data)->bottom_right.y);
            break;
        case SHAPE_CIRCLE:
            printf("Circle: (%d, %d) - %d\n", ((struct circle *)shape->data)->center.x, ((struct circle *)shape->data)->center.y, ((struct circle *)shape->data)->radius);
            break;
    }
}

int main() {
    struct point *point = create_point(10, 20);
    struct rectangle *rectangle = create_rectangle(*point, *create_point(30, 40));
    struct circle *circle = create_circle(*point, 50);

    print_shape((struct shape *)point);
    print_shape((struct shape *)rectangle);
    print_shape((struct shape *)circle);

    free_shape(point);
    free_shape(rectangle);
    free_shape(circle);
    return 0;
}