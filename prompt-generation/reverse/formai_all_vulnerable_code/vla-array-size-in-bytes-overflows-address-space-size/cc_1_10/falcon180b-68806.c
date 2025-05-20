//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

struct point {
    double lat;
    double lon;
};

double distance(struct point p1, struct point p2) {
    double dlat = p2.lat - p1.lat;
    double dlon = p2.lon - p1.lon;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(p1.lat) * cos(p2.lat) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return 6371 * c; // Earth's radius in kilometers
}

void gps_simulation() {
    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);

    struct point points[n];
    printf("Enter latitude and longitude for each point:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &points[i].lat, &points[i].lon);
    }

    int m;
    printf("Enter number of routes: ");
    scanf("%d", &m);

    double distances[m];
    for (int i = 0; i < m; i++) {
        int start, end;
        printf("Enter start and end points for route %d:\n", i + 1);
        scanf("%d %d", &start, &end);
        distances[i] = distance(points[start - 1], points[end - 1]);
    }

    printf("Distances between points:\n");
    for (int i = 0; i < m; i++) {
        printf("Route %d: %.2f km\n", i + 1, distances[i]);
    }
}

int main() {
    gps_simulation();
    return 0;
}