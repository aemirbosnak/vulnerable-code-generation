//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ Clusters 10

typedef struct Cluster {
    int idx;
    double avg_dist;
    struct Cluster *next;
} Cluster;

void calculate_distances(Cluster *cluster, int n);
void update_clusters(Cluster *cluster, int n);

int main() {

    int n = 10;
    Cluster *clusters = NULL;

    // Create n clusters
    for (int i = 0; i < n; i++) {
        Cluster *new_cluster = (Cluster *)malloc(sizeof(Cluster));
        new_cluster->idx = i;
        new_cluster->avg_dist = 0.0;
        new_cluster->next = clusters;
        clusters = new_cluster;
    }

    // Calculate distances for each cluster
    calculate_distances(clusters, n);

    // Update clusters based on distances
    update_clusters(clusters, n);

    // Print cluster information
    for (Cluster *curr = clusters; curr; curr = curr->next) {
        printf("Cluster %d: avg_dist = %.2lf\n", curr->idx, curr->avg_dist);
    }

    return 0;
}

void calculate_distances(Cluster *cluster, int n) {
    for (int i = 0; i < n; i++) {
        // Calculate distance between cluster and each data point
        double distance = sqrt(pow(cluster->idx - i, 2) + pow(cluster->avg_dist - 0.0, 2));
        cluster->avg_dist = (distance + cluster->avg_dist) / 2;
    }
}

void update_clusters(Cluster *cluster, int n) {
    for (int i = 0; i < n; i++) {
        // Find the nearest cluster to each data point
        Cluster *nearest_cluster = cluster;
        double nearest_distance = 1000.0;
        for (Cluster *curr = cluster; curr; curr = curr->next) {
            if (curr != nearest_cluster) {
                double distance = sqrt(pow(curr->idx - i, 2) + pow(curr->avg_dist - 0.0, 2));
                if (distance < nearest_distance) {
                    nearest_cluster = curr;
                    nearest_distance = distance;
                }
            }
        }

        // Update the average distance of the nearest cluster
        nearest_cluster->avg_dist = (nearest_distance + nearest_cluster->avg_dist) / 2;
    }
}