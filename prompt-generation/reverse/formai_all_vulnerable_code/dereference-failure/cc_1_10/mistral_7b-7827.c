//MISTRAL-7B DATASET v1.0 Category: GPS Navigation Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_POINTS 1000
#define PI 3.14159265358979323846

typedef struct {
    double lat;
    double lon;
} Point;

typedef struct {
    Point start;
    Point end;
    Point *points;
    int num_points;
} Route;

Route generate_random_route(int num_points) {
    Route route;
    int i;

    route.start.lat = 40.7128;
    route.start.lon = -74.0060;

    route.end.lat = 37.7749;
    route.end.lon = -122.4194;

    route.points = malloc(num_points * sizeof(Point));

    for (i = 0; i < num_points; i++) {
        route.points[i].lat = rand() * (180.0 / RAND_MAX) * PI / 180.0 + route.start.lat;
        route.points[i].lon = rand() * (360.0 / RAND_MAX) * PI / 180.0 + route.start.lon;
    }

    route.num_points = num_points;

    return route;
}

void print_route(Route route) {
    int i;

    printf("Route from (%f, %f) to (%f, %f):\n", route.start.lat, route.start.lon, route.end.lat, route.end.lon);

    for (i = 0; i < route.num_points; i++) {
        printf("Point %d: (%f, %f)\n", i, route.points[i].lat, route.points[i].lon);
    }
}

void free_route(Route *route) {
    free(route->points);
    *route = (Route){0};
}

int main() {
    Route route;
    int num_points = 5;

    route = generate_random_route(num_points);

    printf("\nRandom route generated:\n");
    print_route(route);

    free_route(&route);

    return 0;
}