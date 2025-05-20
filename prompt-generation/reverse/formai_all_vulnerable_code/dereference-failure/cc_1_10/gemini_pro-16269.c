//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} point;

typedef struct cluster {
    point centroid;
    int num_points;
    point *points;
} cluster;

double distance(point a, point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

cluster *create_cluster(point centroid, int num_points, point *points) {
    cluster *c = malloc(sizeof(cluster));
    c->centroid = centroid;
    c->num_points = num_points;
    c->points = points;
    return c;
}

void free_cluster(cluster *c) {
    free(c->points);
    free(c);
}

cluster *kmeans(point *points, int num_points, int num_clusters) {
    // Initialize clusters
    cluster *clusters = malloc(sizeof(cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = *create_cluster(points[i], 1, &points[i]);
    }

    // Iterate until convergence
    int converged = 0;
    while (!converged) {
        // Assign points to clusters
        for (int i = 0; i < num_points; i++) {
            double min_distance = INFINITY;
            int min_cluster_index = -1;
            for (int j = 0; j < num_clusters; j++) {
                double distance_to_centroid = distance(points[i], clusters[j].centroid);
                if (distance_to_centroid < min_distance) {
                    min_distance = distance_to_centroid;
                    min_cluster_index = j;
                }
            }
            clusters[min_cluster_index].points[clusters[min_cluster_index].num_points++] = points[i];
        }

        // Update cluster centroids
        for (int i = 0; i < num_clusters; i++) {
            double sum_x = 0;
            double sum_y = 0;
            for (int j = 0; j < clusters[i].num_points; j++) {
                sum_x += clusters[i].points[j].x;
                sum_y += clusters[i].points[j].y;
            }
            clusters[i].centroid.x = sum_x / clusters[i].num_points;
            clusters[i].centroid.y = sum_y / clusters[i].num_points;
        }

        // Check for convergence
        converged = 1;
        for (int i = 0; i < num_clusters; i++) {
            if (clusters[i].num_points != clusters[i].num_points) {
                converged = 0;
                break;
            }
        }
    }

    return clusters;
}

int main() {
    // Generate some random points
    int num_points = 100;
    point *points = malloc(sizeof(point) * num_points);
    for (int i = 0; i < num_points; i++) {
        points[i].x = rand() % 100;
        points[i].y = rand() % 100;
    }

    // Perform k-means clustering
    int num_clusters = 3;
    cluster *clusters = kmeans(points, num_points, num_clusters);

    // Print the clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    // Free the clusters
    for (int i = 0; i < num_clusters; i++) {
        free_cluster(&clusters[i]);
    }
    free(clusters);

    return 0;
}