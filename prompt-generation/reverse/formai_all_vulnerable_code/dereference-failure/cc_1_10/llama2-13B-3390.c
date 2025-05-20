//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define LEN 100
#define MAGIC 42

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point p1, p2;
} Line;

typedef struct {
    Line l1, l2;
} Triangle;

Triangle *create_triangle(void) {
    Triangle *t = malloc(sizeof(Triangle));
    t->l1.p1.x = 1;
    t->l1.p1.y = 2;
    t->l1.p2.x = 3;
    t->l1.p2.y = 4;
    t->l2.p1.x = 5;
    t->l2.p1.y = 6;
    t->l2.p2.x = 7;
    t->l2.p2.y = 8;
    return t;
}

void print_triangle(Triangle *t) {
    printf("Triangle with vertices at (%d, %d), (%d, %d), and (%d, %d)\n",
           t->l1.p1.x, t->l1.p1.y, t->l1.p2.x, t->l1.p2.y,
           t->l2.p1.x, t->l2.p1.y, t->l2.p2.x, t->l2.p2.y);
}

int area(Triangle *t) {
    int x1 = t->l1.p1.x, x2 = t->l1.p2.x, y1 = t->l1.p1.y, y2 = t->l1.p2.y;
    int x3 = t->l2.p1.x, x4 = t->l2.p2.x, y3 = t->l2.p1.y, y4 = t->l2.p2.y;
    return (x2 - x1) * (y4 - y1) - (x4 - x3) * (y2 - y3);
}

int main() {
    srand(time(NULL));
    Triangle *t = create_triangle();
    print_triangle(t);
    printf("Area of triangle: %d\n", area(t));
    free(t);
    return 0;
}