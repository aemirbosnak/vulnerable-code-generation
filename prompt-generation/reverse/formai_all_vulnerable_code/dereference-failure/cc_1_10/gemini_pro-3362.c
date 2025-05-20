//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int size;
} PointArray;

PointArray *create_point_array(int size) {
    PointArray *array = malloc(sizeof(PointArray));
    array->points = malloc(sizeof(Point) * size);
    array->size = size;
    return array;
}

void destroy_point_array(PointArray *array) {
    free(array->points);
    free(array);
}

void print_point_array(PointArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("(%d, %d)\n", array->points[i].x, array->points[i].y);
    }
}

// Compare two points by their x-coordinates
int compare_points_by_x(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return p1->x - p2->x;
}

// Compare two points by their y-coordinates
int compare_points_by_y(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return p1->y - p2->y;
}

int main() {
    // Create an array of points
    PointArray *array = create_point_array(5);
    array->points[0] = (Point){1, 2};
    array->points[1] = (Point){3, 4};
    array->points[2] = (Point){5, 6};
    array->points[3] = (Point){7, 8};
    array->points[4] = (Point){9, 10};

    // Sort the array of points by their x-coordinates
    qsort(array->points, array->size, sizeof(Point), compare_points_by_x);

    // Print the sorted array of points by their x-coordinates
    printf("Sorted by x-coordinates:\n");
    print_point_array(array);

    // Sort the array of points by their y-coordinates
    qsort(array->points, array->size, sizeof(Point), compare_points_by_y);

    // Print the sorted array of points by their y-coordinates
    printf("\nSorted by y-coordinates:\n");
    print_point_array(array);

    // Destroy the array of points
    destroy_point_array(array);

    return 0;
}