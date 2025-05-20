//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_NUM_CLUSTERS 10

typedef struct Cluster {
    int num_points;
    double center_x;
    double center_y;
    double **points;
} Cluster;

Cluster **create_cluster(int num_points) {
    Cluster **cluster = malloc(sizeof(Cluster) * num_points);

    for (int i = 0; i < num_points; i++) {
        cluster[i] = malloc(sizeof(Cluster));
        cluster[i]->num_points = 0;
        cluster[i]->center_x = 0.0;
        cluster[i]->center_y = 0.0;
        cluster[i]->points = NULL;
    }

    return cluster;
}

void add_point_to_cluster(Cluster *cluster, double x, double y) {
    cluster->num_points++;
    cluster->points = realloc(cluster->points, sizeof(double *) * cluster->num_points);
    cluster->points[cluster->num_points - 1] = malloc(sizeof(double) * 2);
    cluster->points[cluster->num_points - 1][0] = x;
    cluster->points[cluster->num_points - 1][1] = y;
}

void calculate_cluster_center(Cluster *cluster) {
    double total_x = 0.0;
    double total_y = 0.0;

    for (int i = 0; i < cluster->num_points; i++) {
        total_x += cluster->points[i][0];
        total_y += cluster->points[i][1];
    }

    cluster->center_x = total_x / cluster->num_points;
    cluster->center_y = total_y / cluster->num_points;
}

void print_clusters(Cluster **clusters) {
    for (int i = 0; i < MAX_NUM_CLUSTERS; i++) {
        if (clusters[i] != NULL) {
            printf("Cluster %d:\n", i);
            printf("  Number of points: %d\n", clusters[i]->num_points);
            printf("  Center: (%f, %f)\n", clusters[i]->center_x, clusters[i]->center_y);
            printf("  Points:\n");
            for (int j = 0; j < clusters[i]->num_points; j++) {
                printf("    (%f, %f)\n", clusters[i]->points[j][0], clusters[i]->points[j][1]);
            }
            printf("\n");
        }
    }
}

int main() {
    Cluster **clusters = create_cluster(MAX_NUM_CLUSTERS);

    add_point_to_cluster(clusters[0], 1.0, 1.0);
    add_point_to_cluster(clusters[0], 2.0, 2.0);
    add_point_to_cluster(clusters[0], 3.0, 3.0);

    add_point_to_cluster(clusters[1], 4.0, 4.0);
    add_point_to_cluster(clusters[1], 5.0, 5.0);
    add_point_to_cluster(clusters[1], 6.0, 6.0);

    calculate_cluster_center(clusters[0]);
    calculate_cluster_center(clusters[1]);

    print_clusters(clusters);

    return 0;
}