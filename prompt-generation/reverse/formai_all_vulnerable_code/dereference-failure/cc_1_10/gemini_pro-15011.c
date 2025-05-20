//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    int z;
} point_t;

typedef struct {
    point_t *points;
    int num_points;
} point_cloud_t;

point_cloud_t *create_point_cloud(int num_points) {
    point_cloud_t *cloud = malloc(sizeof(point_cloud_t));
    cloud->points = malloc(sizeof(point_t) * num_points);
    cloud->num_points = num_points;
    return cloud;
}

void destroy_point_cloud(point_cloud_t *cloud) {
    free(cloud->points);
    free(cloud);
}

void add_point(point_cloud_t *cloud, int x, int y, int z) {
    point_t *point = &cloud->points[cloud->num_points];
    point->x = x;
    point->y = y;
    point->z = z;
    cloud->num_points++;
}

double calculate_distance(point_t *p1, point_t *p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    double dz = p1->z - p2->z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <num_points>\n", argv[0]);
        return 1;
    }

    int num_points = atoi(argv[1]);
    point_cloud_t *cloud = create_point_cloud(num_points);

    for (int i = 0; i < num_points; i++) {
        int x = rand() % 100;
        int y = rand() % 100;
        int z = rand() % 100;
        add_point(cloud, x, y, z);
    }

    double max_distance = 0;
    for (int i = 0; i < cloud->num_points; i++) {
        for (int j = i + 1; j < cloud->num_points; j++) {
            double distance = calculate_distance(&cloud->points[i], &cloud->points[j]);
            if (distance > max_distance) {
                max_distance = distance;
            }
        }
    }

    printf("Maximum distance: %f\n", max_distance);

    destroy_point_cloud(cloud);
    return 0;
}