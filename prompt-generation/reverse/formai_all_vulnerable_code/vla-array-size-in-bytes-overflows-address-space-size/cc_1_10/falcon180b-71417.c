//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01 // in km

struct point {
    double latitude;
    double longitude;
};

double distance(struct point p1, struct point p2) {
    double dlat = p2.latitude - p1.latitude;
    double dlon = p2.longitude - p1.longitude;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(p1.latitude) * cos(p2.latitude) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void main() {
    int num_points;
    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    struct point points[num_points];

    for (int i = 0; i < num_points; i++) {
        printf("Enter the latitude and longitude of point %d: ", i + 1);
        scanf("%lf %lf", &points[i].latitude, &points[i].longitude);
    }

    int start_point;
    printf("Enter the starting point: ");
    scanf("%d", &start_point);

    double shortest_distance = distance(points[start_point], points[start_point]);
    int shortest_route_index = start_point;

    for (int i = 0; i < num_points; i++) {
        if (i == start_point)
            continue;

        double distance_to_point = distance(points[start_point], points[i]);
        if (distance_to_point < shortest_distance) {
            shortest_distance = distance_to_point;
            shortest_route_index = i;
        }
    }

    printf("The shortest route is: ");
    for (int i = start_point; i!= shortest_route_index; i = (i + 1) % num_points) {
        printf("%d ", i + 1);
    }
    printf("%d\n", shortest_route_index + 1);
}