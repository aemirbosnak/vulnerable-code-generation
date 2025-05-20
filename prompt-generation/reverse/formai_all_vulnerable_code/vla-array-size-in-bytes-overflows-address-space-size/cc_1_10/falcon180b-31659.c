//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371.01 // Earth's radius in km
#define PI 3.14159265358979323846

struct location {
    double latitude;
    double longitude;
};

double distance(struct location l1, struct location l2) {
    double dlat = l2.latitude - l1.latitude;
    double dlon = l2.longitude - l1.longitude;

    double a = sin(dlat / 2) * sin(dlat / 2) + cos(l1.latitude * PI / 180) * cos(l2.latitude * PI / 180) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

int main() {
    int num_locations;
    printf("Enter the number of locations: ");
    scanf("%d", &num_locations);

    struct location locations[num_locations];

    for (int i = 0; i < num_locations; i++) {
        printf("Enter the latitude and longitude for location %d: ", i + 1);
        scanf("%lf %lf", &locations[i].latitude, &locations[i].longitude);
    }

    int num_routes;
    printf("Enter the number of routes: ");
    scanf("%d", &num_routes);

    for (int i = 0; i < num_routes; i++) {
        int num_stops;
        printf("Enter the number of stops for route %d: ", i + 1);
        scanf("%d", &num_stops);

        int stops[num_stops];
        printf("Enter the location IDs for the stops (separated by spaces): ");
        for (int j = 0; j < num_stops; j++) {
            scanf("%d", &stops[j]);
        }

        double total_distance = 0;
        for (int j = 0; j < num_stops - 1; j++) {
            int location1 = stops[j];
            int location2 = stops[j + 1];

            total_distance += distance(locations[location1], locations[location2]);
        }

        printf("The total distance for route %d is %.2lf km.\n", i + 1, total_distance);
    }

    return 0;
}