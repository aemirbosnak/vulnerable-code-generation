//LLAMA2-13B DATASET v1.0 Category: Geometric algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Definition of the geometric shape
typedef struct {
    int x, y;
    int size;
} shape_t;

// Function to generate a random shape
shape_t* generate_shape() {
    int x, y;
    int size;

    do {
        x = rand() % 100 - 50;
        y = rand() % 100 - 50;
        size = rand() % 10 + 1;
    } while (x == 0 || y == 0 || size == 0);

    shape_t* shape = malloc(sizeof(shape_t));
    shape->x = x;
    shape->y = y;
    shape->size = size;

    return shape;
}

// Function to draw a shape
void draw_shape(shape_t* shape) {
    int x, y;

    for (int i = 0; i < shape->size; i++) {
        x = shape->x + i * (shape->x - shape->y);
        y = shape->y + i * (shape->x - shape->y);

        printf("{%d, %d}", x, y);

        if (i != shape->size - 1) {
            printf(" ");
        }
    }

    printf("\n");
}

int main() {
    shape_t* shape1 = generate_shape();
    shape_t* shape2 = generate_shape();

    draw_shape(shape1);
    draw_shape(shape2);

    free(shape1);
    free(shape2);

    return 0;
}