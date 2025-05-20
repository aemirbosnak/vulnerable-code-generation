//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

struct point {
    double lat;
    double lon;
};

struct point get_current_location() {
    struct point location;
    printf("Enter current location (latitude and longitude): ");
    scanf("%lf %lf", &location.lat, &location.lon);
    return location;
}

double distance(struct point p1, struct point p2) {
    double dlat = p2.lat - p1.lat;
    double dlon = p2.lon - p1.lon;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(p1.lat) * cos(p2.lat) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void print_route(struct point start, struct point end) {
    printf("The route from %.2lf, %.2lf to %.2lf, %.2lf is %.2lf km long.\n", start.lat, start.lon, end.lat, end.lon, distance(start, end));
}

int main() {
    srand(time(NULL));
    int num_locations = rand() % 10 + 1;
    struct point *locations = malloc(sizeof(struct point) * num_locations);
    for (int i = 0; i < num_locations; i++) {
        locations[i] = get_current_location();
    }

    int num_routes = rand() % num_locations + 1;
    for (int i = 0; i < num_routes; i++) {
        int start_index = rand() % num_locations;
        int end_index = rand() % num_locations;
        while (end_index == start_index) {
            end_index = rand() % num_locations;
        }
        struct point start = locations[start_index];
        struct point end = locations[end_index];
        print_route(start, end);
    }

    free(locations);

    return 0;
}