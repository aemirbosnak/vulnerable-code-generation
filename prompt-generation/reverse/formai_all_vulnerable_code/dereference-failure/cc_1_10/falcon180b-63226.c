//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371.01

struct Point {
    double latitude;
    double longitude;
};

struct Path {
    struct Point *points;
    int num_points;
};

void init_path(struct Path *path, int num_points) {
    path->points = (struct Point *)malloc(num_points * sizeof(struct Point));
    path->num_points = num_points;
}

void free_path(struct Path *path) {
    free(path->points);
}

double distance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;
    double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_RADIUS * c;
}

void get_path(struct Point start, struct Point end, struct Path *path) {
    int num_points = 2;
    init_path(path, num_points);
    path->points[0] = start;
    path->points[1] = end;
}

void print_path(struct Path *path) {
    int i;
    for (i = 0; i < path->num_points; i++) {
        printf("%.6f, %.6f\n", path->points[i].latitude, path->points[i].longitude);
    }
}

int main() {
    srand(time(NULL));
    struct Point start = {rand() % 360 - 180, rand() % 180 - 90};
    struct Point end = {rand() % 360 - 180, rand() % 180 - 90};
    struct Path path;
    get_path(start, end, &path);
    printf("Total distance: %.2f km\n", distance(start.latitude, start.longitude, end.latitude, end.longitude));
    printf("Path:\n");
    print_path(&path);
    free_path(&path);
    return 0;
}