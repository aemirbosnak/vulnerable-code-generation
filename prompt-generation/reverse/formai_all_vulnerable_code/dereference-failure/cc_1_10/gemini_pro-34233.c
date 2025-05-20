//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    int num_points;
    point *points;
} cluster;

double distance(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

cluster *create_cluster(int num_points) {
    cluster *cluster = malloc(sizeof(cluster));
    cluster->num_points = num_points;
    cluster->points = malloc(sizeof(point) * num_points);
    return cluster;
}

void destroy_cluster(cluster *cluster) {
    free(cluster->points);
    free(cluster);
}

int main() {
    // Create a set of points
    point points[] = {
        {0, 0},
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0},
    };

    // Create a cluster for each point
    cluster *clusters[5];
    for (int i = 0; i < 5; i++) {
        clusters[i] = create_cluster(1);
        clusters[i]->points[0] = points[i];
    }

    // Iterate over all pairs of points
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            // Calculate the distance between the two points
            double dist = distance(points[i], points[j]);

            // If the distance is less than the threshold, merge the two clusters
            if (dist < 1) {
                // Merge the two clusters
                clusters[i]->num_points += clusters[j]->num_points;
                for (int k = 0; k < clusters[j]->num_points; k++) {
                    clusters[i]->points[clusters[i]->num_points + k] = clusters[j]->points[k];
                }

                // Destroy the second cluster
                destroy_cluster(clusters[j]);
            }
        }
    }

    // Print the final clusters
    for (int i = 0; i < 5; i++) {
        printf("Cluster %d: ", i);
        for (int j = 0; j < clusters[i]->num_points; j++) {
            printf("(%lf, %lf) ", clusters[i]->points[j].x, clusters[i]->points[j].y);
        }
        printf("\n");
    }

    // Destroy all clusters
    for (int i = 0; i < 5; i++) {
        destroy_cluster(clusters[i]);
    }

    return 0;
}