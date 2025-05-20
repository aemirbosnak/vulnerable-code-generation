//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 21
#define HEIGHT 21
#define CAPACITY 1000

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point *points;
    int capacity;
    int size;
} Vector;

Vector create_vector() {
    Vector v = {0};
    v.points = (Point *)malloc(CAPACITY * sizeof(Point));
    v.capacity = CAPACITY;
    v.size = 0;
    return v;
}

void destroy_vector(Vector *v) {
    free(v->points);
    v->points = 0;
    v->capacity = 0;
    v->size = 0;
}

void add_point(Vector *v, int x, int y) {
    if (v->size >= v->capacity) {
        v->capacity += CAPACITY;
        v->points = (Point *)realloc(v->points, v->capacity * sizeof(Point));
    }
    v->points[v->size].x = x;
    v->points[v->size].y = y;
    v->size++;
}

void print_vector(Vector v) {
    for (int i = 0; i < v.size; i++) {
        printf("(%d, %d)\n", v.points[i].x, v.points[i].y);
    }
}

int main() {
    srand(time(0));
    Vector v = create_vector();
    add_point(&v, 0, 0);
    add_point(&v, 0, 1);
    add_point(&v, 1, 1);
    add_point(&v, 1, 0);
    print_vector(v);
    destroy_vector(&v);
    return 0;
}