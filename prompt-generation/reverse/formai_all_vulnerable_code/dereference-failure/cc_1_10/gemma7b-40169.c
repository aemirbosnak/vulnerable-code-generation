//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: brave
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_CLUSTER_SIZE 10

typedef struct Cluster {
    int num_points;
    double center[2];
    double points[MAX_CLUSTER_SIZE][2];
} Cluster;

Cluster* create_cluster(int num_points) {
    Cluster* cluster = (Cluster*)malloc(sizeof(Cluster));
    cluster->num_points = num_points;
    cluster->center[0] = cluster->center[1] = 0.0;
    for (int i = 0; i < num_points; i++) {
        cluster->points[i][0] = cluster->points[i][1] = 0.0;
    }
    return cluster;
}

void add_point_to_cluster(Cluster* cluster, double x, double y) {
    cluster->points[cluster->num_points][0] = x;
    cluster->points[cluster->num_points][1] = y;
    cluster->num_points++;
    double new_center_x = (cluster->points[0][0] + cluster->points[1][0]) / 2.0;
    double new_center_y = (cluster->points[0][1] + cluster->points[1][1]) / 2.0;
    cluster->center[0] = new_center_x;
    cluster->center[1] = new_center_y;
}

void print_cluster(Cluster* cluster) {
    printf("Number of points: %d\n", cluster->num_points);
    printf("Center: (%f, %f)\n", cluster->center[0], cluster->center[1]);
    for (int i = 0; i < cluster->num_points; i++) {
        printf("Point: (%f, %f)\n", cluster->points[i][0], cluster->points[i][1]);
    }
}

int main() {
    Cluster* cluster = create_cluster(5);
    add_point_to_cluster(cluster, 1.0, 2.0);
    add_point_to_cluster(cluster, 3.0, 4.0);
    add_point_to_cluster(cluster, 2.0, 6.0);
    add_point_to_cluster(cluster, 4.0, 5.0);
    add_point_to_cluster(cluster, 3.0, 8.0);

    print_cluster(cluster);

    return 0;
}