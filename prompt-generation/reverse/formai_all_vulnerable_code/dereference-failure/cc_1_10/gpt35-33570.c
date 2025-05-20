//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RADIUS 6371 //Radius of the Earth in km

double deg2rad(double deg) {
    return deg * (M_PI / 180);
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dLat = deg2rad(lat2 - lat1);
    double dLon = deg2rad(lon2 - lon1);
    double a = sin(dLat / 2) * sin(dLat / 2) + cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double d = RADIUS * c;
    return d;
}

typedef struct {
    double lat;
    double lon;
} Position;

typedef struct {
    Position* route;
    int size;
} Route;

void navigate(Route* r, Position p) {
    double minDistance = INFINITY;
    int index = 0;
    for (int i = 0; i < r->size; i++) {
        double d = distance(p.lat, p.lon, r->route[i].lat, r->route[i].lon);
        if (d < minDistance) {
            minDistance = d;
            index = i;
        }
    }
    printf("The closest point on the route is at position (%lf, %lf)\n", r->route[index].lat, r->route[index].lon);
}

int main() {
    // Creating a route with 3 points
    Route r;
    r.size = 3;
    r.route = (Position*) malloc(r.size * sizeof(Position));
    r.route[0].lat = 47.6062;
    r.route[0].lon = -122.3321;
    r.route[1].lat = 37.7749;
    r.route[1].lon = -122.4194;
    r.route[2].lat = 45.5231;
    r.route[2].lon = -122.6765;

    // Current position of the user
    Position p;
    p.lat = 33.6844;
    p.lon = -117.8265;

    // Navigate to the closest point on the route
    navigate(&r, p);

    // Free the memory allocated for the route
    free(r.route);

    return 0;
}