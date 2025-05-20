//LLAMA2-13B DATASET v1.0 Category: Geometric algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Randomly generated geometric shapes
typedef struct shape {
    int type; // 0: point, 1: line, 2: circle, 3: triangle
    union {
        int x, y; // point
        int a, b; // line
        int radius, x_center, y_center; // circle
        int sides[3]; // triangle
    } data;
} shape;

// Randomly generate a geometric shape
shape *random_shape(void) {
    shape *s = malloc(sizeof(shape));
    s->type = rand() % 4;
    switch (s->type) {
        case 0: // point
            s->data.x = rand() % 100 - 50;
            s->data.y = rand() % 100 - 50;
            break;
        case 1: // line
            s->data.a = rand() % 100 - 50;
            s->data.b = rand() % 100 - 50;
            break;
        case 2: // circle
            s->data.radius = rand() % 50 + 25;
            s->data.x_center = rand() % 100 - 50;
            s->data.y_center = rand() % 100 - 50;
            break;
        case 3: // triangle
            s->data.sides[0] = rand() % 100 - 50;
            s->data.sides[1] = rand() % 100 - 50;
            s->data.sides[2] = rand() % 100 - 50;
            break;
    }
    return s;
}

// Draw the geometric shape
void draw_shape(shape *s, int x, int y) {
    switch (s->type) {
        case 0: // point
            printf("(%d, %d)", x, y);
            break;
        case 1: // line
            printf("(%d, %d) -- (%d, %d)", x, y, x + s->data.a, y + s->data.b);
            break;
        case 2: // circle
            printf("(%.2f, %.2f) -- radius = %.2f", x + s->data.x_center, y + s->data.y_center, s->data.radius);
            break;
        case 3: // triangle
            printf("(%.2f, %.2f) -- (%.2f, %.2f) -- (%.2f, %.2f)",
                   x + s->data.sides[0], y + s->data.sides[1],
                   x + s->data.sides[1], y + s->data.sides[2],
                   x + s->data.sides[2], y + s->data.sides[0]);
            break;
    }
}

int main() {
    srand(time(NULL)); // seed random number generator
    shape *s = random_shape();
    int x = 50;
    int y = 50;
    draw_shape(s, x, y);
    free(s);
    return 0;
}