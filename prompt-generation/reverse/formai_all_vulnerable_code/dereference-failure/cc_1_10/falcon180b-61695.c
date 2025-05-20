//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct point {
    double x;
    double y;
};

struct route {
    int num_points;
    struct point *points;
};

void generate_route(struct route *route, double start_x, double start_y, double end_x, double end_y) {
    int num_points = rand() % 10 + 5;
    route->num_points = num_points;
    route->points = malloc(num_points * sizeof(struct point));
    double dx = end_x - start_x;
    double dy = end_y - start_y;
    double dist = sqrt(dx * dx + dy * dy);
    double step_x = dx / dist;
    double step_y = dy / dist;
    struct point *curr_point = route->points;
    curr_point->x = start_x;
    curr_point->y = start_y;
    for (int i = 1; i < num_points; i++) {
        curr_point->x += step_x;
        curr_point->y += step_y;
        curr_point++;
    }
    curr_point->x = end_x;
    curr_point->y = end_y;
}

void print_route(struct route *route) {
    struct point *curr_point = route->points;
    printf("Route: ");
    for (int i = 0; i < route->num_points; i++) {
        printf("(%f, %f) ", curr_point->x, curr_point->y);
        curr_point++;
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    struct route route;
    generate_route(&route, 0, 0, 10, 10);
    print_route(&route);
    return 0;
}