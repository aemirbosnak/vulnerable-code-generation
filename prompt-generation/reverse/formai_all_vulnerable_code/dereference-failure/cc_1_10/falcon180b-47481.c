//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371.0

struct Coordinate {
    double latitude;
    double longitude;
};

struct Route {
    int num_coords;
    struct Coordinate *coords;
};

double calc_distance(struct Coordinate c1, struct Coordinate c2) {
    double dlat = c2.latitude - c1.latitude;
    double dlon = c2.longitude - c1.longitude;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(c1.latitude) * cos(c2.latitude) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void add_coordinate(struct Route *route, double lat, double lon) {
    struct Coordinate *new_coords = realloc(route->coords, sizeof(struct Coordinate) * (route->num_coords + 1));
    if (new_coords == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    route->coords = new_coords;
    route->coords[route->num_coords].latitude = lat;
    route->coords[route->num_coords].longitude = lon;
    route->num_coords++;
}

int main() {
    struct Route route;
    route.num_coords = 0;
    route.coords = NULL;

    double start_lat, start_lon, end_lat, end_lon;
    printf("Enter starting coordinates (latitude, longitude): ");
    scanf("%lf %lf", &start_lat, &start_lon);
    printf("Enter ending coordinates (latitude, longitude): ");
    scanf("%lf %lf", &end_lat, &end_lon);

    add_coordinate(&route, start_lat, start_lon);
    add_coordinate(&route, end_lat, end_lon);

    double total_distance = 0.0;
    int i;
    for (i = 0; i < route.num_coords - 1; i++) {
        total_distance += calc_distance(route.coords[i], route.coords[i+1]);
    }

    printf("Total distance: %.2lf km\n", total_distance);

    return 0;
}