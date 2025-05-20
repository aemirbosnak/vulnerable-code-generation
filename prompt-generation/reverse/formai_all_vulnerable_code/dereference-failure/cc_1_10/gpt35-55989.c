//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point* points;
    int size;
    int capacity;
} PointArray;

PointArray* create_point_array(int capacity) {
    PointArray* arr = malloc(sizeof(PointArray));
    arr->points = malloc(capacity * sizeof(Point));
    arr->size = 0;
    arr->capacity = capacity;
    return arr;
}

void destroy_point_array(PointArray* arr) {
    free(arr->points);
    free(arr);
}

void append_point(PointArray* arr, Point p) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
        arr->points = realloc(arr->points, arr->capacity * sizeof(Point));
    }
    arr->points[arr->size] = p;
    arr->size++;
}

void print_point(Point p) {
    printf("(%d, %d)", p.x, p.y);
}

void print_point_array(PointArray* arr) {
    printf("[ ");
    for (int i = 0; i < arr->size; i++) {
        print_point(arr->points[i]);
        if (i < arr->size - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

int main() {
    PointArray* arr = create_point_array(4);
    Point p1 = {1, 2};
    Point p2 = {3, 4};
    Point p3 = {5, 6};
    Point p4 = {7, 8};
    append_point(arr, p1);
    append_point(arr, p2);
    printf("Size: %d, Capacity: %d\n", arr->size, arr->capacity);
    print_point_array(arr);
    append_point(arr, p3);
    append_point(arr, p4);
    printf("Size: %d, Capacity: %d\n", arr->size, arr->capacity);
    print_point_array(arr);
    destroy_point_array(arr);
    return 0;
}