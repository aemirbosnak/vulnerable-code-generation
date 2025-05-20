//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point* points;
    int num_points;
    int capacity;
} PointSet;

void initialize_point_set(PointSet* set, int capacity) {
    set->points = (Point*)malloc(capacity * sizeof(Point));
    set->num_points = 0;
    set->capacity = capacity;
}

void add_point(PointSet* set, int x, int y) {
    if (set->num_points >= set->capacity) {
        printf("Error: Point set is full.\n");
        return;
    }

    set->points[set->num_points].x = x;
    set->points[set->num_points].y = y;
    set->num_points++;
}

void print_point_set(PointSet* set) {
    printf("Point set:\n");
    for (int i = 0; i < set->num_points; i++) {
        printf("(%d, %d)\n", set->points[i].x, set->points[i].y);
    }
}

void free_point_set(PointSet* set) {
    free(set->points);
}

int main() {
    int num_points = 1000000;
    int capacity = num_points + 1000; // Add some extra capacity for safety

    PointSet point_set;
    initialize_point_set(&point_set, capacity);

    srand(time(0));
    for (int i = 0; i < num_points; i++) {
        int x = rand() % 1000000;
        int y = rand() % 1000000;
        add_point(&point_set, x, y);
    }

    print_point_set(&point_set);

    free_point_set(&point_set);

    return 0;
}