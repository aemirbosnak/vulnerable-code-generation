//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

struct Point {
    double x;
    double y;
};

struct Route {
    int num_points;
    struct Point* points;
};

void init_route(struct Route* route, int num_points) {
    route->num_points = num_points;
    route->points = (struct Point*) malloc(num_points * sizeof(struct Point));
}

void free_route(struct Route* route) {
    free(route->points);
}

void add_point(struct Route* route, double x, double y) {
    route->points[route->num_points - 1].x = x;
    route->points[route->num_points - 1].y = y;
}

double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

void print_route(struct Route* route) {
    printf("Route:\n");
    for (int i = 0; i < route->num_points; i++) {
        printf("(%f, %f)\n", route->points[i].x, route->points[i].y);
    }
}

int main() {
    struct Route route;
    init_route(&route, 5);

    add_point(&route, 0, 0);
    add_point(&route, 1, 1);
    add_point(&route, 2, 2);
    add_point(&route, 3, 1);
    add_point(&route, 4, 0);

    print_route(&route);

    free_route(&route);

    return 0;
}