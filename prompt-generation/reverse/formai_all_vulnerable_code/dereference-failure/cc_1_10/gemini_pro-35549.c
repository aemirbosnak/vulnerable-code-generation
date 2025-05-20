//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point *points;
    int num_points;
} PointSet;

void print_point(Point point) {
    printf("(%f, %f)\n", point.x, point.y);
}

void print_point_set(PointSet point_set) {
    for (int i = 0; i < point_set.num_points; i++) {
        print_point(point_set.points[i]);
    }
}

double distance_between_points(Point point1, Point point2) {
    return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

PointSet generate_random_point_set(int num_points) {
    PointSet point_set;
    point_set.points = malloc(sizeof(Point) * num_points);
    point_set.num_points = num_points;
    for (int i = 0; i < num_points; i++) {
        point_set.points[i].x = (double)rand() / (double)RAND_MAX;
        point_set.points[i].y = (double)rand() / (double)RAND_MAX;
    }
    return point_set;
}

double mean_distance_between_points(PointSet point_set) {
    double total_distance = 0;
    for (int i = 0; i < point_set.num_points; i++) {
        for (int j = i + 1; j < point_set.num_points; j++) {
            total_distance += distance_between_points(point_set.points[i], point_set.points[j]);
        }
    }
    return total_distance / (point_set.num_points * (point_set.num_points - 1) / 2);
}

int main() {
    int num_points = 1000;
    PointSet point_set = generate_random_point_set(num_points);
    double mean_distance = mean_distance_between_points(point_set);
    printf("Mean distance between points: %f\n", mean_distance);
    return 0;
}