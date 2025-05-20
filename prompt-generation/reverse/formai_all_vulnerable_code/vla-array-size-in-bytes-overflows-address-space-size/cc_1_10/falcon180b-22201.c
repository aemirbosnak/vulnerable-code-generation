//Falcon-180B DATASET v1.0 Category: GPS Navigation Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    double x, y, z;
};

void print_point(struct Point p) {
    printf("(%f, %f, %f)\n", p.x, p.y, p.z);
}

double distance(struct Point a, struct Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void gps_simulation() {
    int num_points;
    scanf("%d", &num_points);

    struct Point points[num_points];
    for (int i = 0; i < num_points; i++) {
        scanf("%lf %lf %lf", &points[i].x, &points[i].y, &points[i].z);
    }

    int num_routes;
    scanf("%d", &num_routes);

    for (int i = 0; i < num_routes; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        double distance_total = 0.0;
        int num_segments = 0;

        for (int j = start; j <= end; j++) {
            double distance_segment = 0.0;

            if (j > start) {
                distance_segment += distance(points[j-1], points[j]);
                num_segments++;
            }

            if (j < end) {
                distance_segment += distance(points[j], points[j+1]);
                num_segments++;
            }

            distance_total += distance_segment;
        }

        printf("Route %d: %d segments, %.2f km\n", i+1, num_segments, distance_total/1000.0);
    }
}

int main() {
    gps_simulation();
    return 0;
}