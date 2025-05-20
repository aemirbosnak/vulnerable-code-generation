//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 10000000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} PointSet;

PointSet *create_point_set(int num_points) {
    PointSet *set = malloc(sizeof(PointSet));
    set->points = malloc(num_points * sizeof(Point));
    set->num_points = num_points;
    for (int i = 0; i < num_points; i++) {
        set->points[i].x = rand() % MAX_SIZE;
        set->points[i].y = rand() % MAX_SIZE;
    }
    return set;
}

void destroy_point_set(PointSet *set) {
    free(set->points);
    free(set);
}

void print_point(Point p) {
    printf("(%d,%d)\n", p.x, p.y);
}

void print_point_set(PointSet *set) {
    for (int i = 0; i < set->num_points; i++) {
        print_point(set->points[i]);
    }
}

int main() {
    srand(time(NULL));
    int num_points = 1000000;
    PointSet *set = create_point_set(num_points);
    printf("Generated %d points:\n", num_points);
    print_point_set(set);
    destroy_point_set(set);
    return 0;
}