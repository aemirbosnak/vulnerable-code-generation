//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CLUSTERS 10

typedef struct Cluster {
    int cluster_id;
    double average_distance;
    struct Cluster* next;
} Cluster;

Cluster* create_cluster(int cluster_id) {
    Cluster* cluster = (Cluster*)malloc(sizeof(Cluster));
    cluster->cluster_id = cluster_id;
    cluster->average_distance = 0.0;
    cluster->next = NULL;
    return cluster;
}

void add_point_to_cluster(Cluster* cluster, double point) {
    cluster->average_distance += point;
    cluster->next = create_cluster(cluster->cluster_id);
    add_point_to_cluster(cluster->next, point);
}

void find_clusters(Cluster* clusters, double threshold) {
    for (Cluster* cluster = clusters; cluster; cluster = cluster->next) {
        if (cluster->average_distance < threshold) {
            printf("Point %f belongs to Cluster %d\n", cluster->average_distance, cluster->cluster_id);
        }
    }
}

int main() {
    Cluster* clusters = NULL;
    int i;

    // Create a few clusters
    for (i = 0; i < MAX_CLUSTERS; i++) {
        clusters = create_cluster(i);
        add_point_to_cluster(clusters, i * 2);
        add_point_to_cluster(clusters, i * 2 + 1);
        add_point_to_cluster(clusters, i * 2 + 2);
    }

    // Find clusters with average distance less than 3
    find_clusters(clusters, 3.0);

    return 0;
}