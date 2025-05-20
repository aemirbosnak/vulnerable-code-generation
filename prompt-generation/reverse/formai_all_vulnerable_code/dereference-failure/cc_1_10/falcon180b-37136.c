//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

struct Route {
    struct Point *points;
    int num_points;
};

void init_route(struct Route *route) {
    route->points = (struct Point *)malloc(sizeof(struct Point));
    route->num_points = 0;
}

void add_point(struct Route *route, double x, double y) {
    route->points = (struct Point *)realloc(route->points, sizeof(struct Point) * ++route->num_points);
    route->points[route->num_points - 1].x = x;
    route->points[route->num_points - 1].y = y;
}

void print_route(struct Route *route) {
    for (int i = 0; i < route->num_points; i++) {
        printf("(%f, %f)\n", route->points[i].x, route->points[i].y);
    }
}

void free_route(struct Route *route) {
    free(route->points);
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    struct Route route1, route2;
    init_route(&route1);
    init_route(&route2);

    add_point(&route1, 0, 0);
    add_point(&route1, 10, 0);
    add_point(&route1, 10, 10);
    add_point(&route1, 0, 10);

    add_point(&route2, 5, 5);
    add_point(&route2, 15, 5);
    add_point(&route2, 15, 15);
    add_point(&route2, 5, 15);

    printf("Route 1:\n");
    print_route(&route1);

    printf("Route 2:\n");
    print_route(&route2);

    double shortest_distance = 999999;
    int shortest_index = -1;

    for (int i = 0; i < route1.num_points; i++) {
        for (int j = 0; j < route2.num_points; j++) {
            double distance_between_points = distance(route1.points[i].x, route1.points[i].y, route2.points[j].x, route2.points[j].y);

            if (distance_between_points < shortest_distance) {
                shortest_distance = distance_between_points;
                shortest_index = i;
            }
        }
    }

    printf("Shortest distance between routes: %f\n", shortest_distance);
    printf("Point on route 1: (%f, %f)\n", route1.points[shortest_index].x, route1.points[shortest_index].y);
    printf("Point on route 2: (%f, %f)\n", route2.points[shortest_index % route2.num_points].x, route2.points[shortest_index % route2.num_points].y);

    free_route(&route1);
    free_route(&route2);

    return 0;
}