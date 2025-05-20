//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Define the max number of clusters and data points
#define MAX_CLUSTERS 100
#define MAX_DATA_POINTS 10000

// Define the data point structure
typedef struct {
    double x;
    double y;
} data_point;

// Define the cluster structure
typedef struct {
    data_point centroid;
    int num_points;
    data_point* points;
} cluster;

// Define the clustering algorithm function
void clustering(data_point* data_points, int num_data_points, int num_clusters) {
    // Initialize the clusters
    cluster* clusters = malloc(sizeof(cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = 0;
        clusters[i].centroid.y = 0;
        clusters[i].num_points = 0;
        clusters[i].points = malloc(sizeof(data_point) * MAX_DATA_POINTS);
    }

    // Assign each data point to a cluster
    for (int i = 0; i < num_data_points; i++) {
        int cluster_index = 0;
        double min_distance = INFINITY;
        for (int j = 0; j < num_clusters; j++) {
            double distance = sqrt(pow(data_points[i].x - clusters[j].centroid.x, 2) + pow(data_points[i].y - clusters[j].centroid.y, 2));
            if (distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }
        clusters[cluster_index].points[clusters[cluster_index].num_points] = data_points[i];
        clusters[cluster_index].num_points++;
    }

    // Update the cluster centroids
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = 0;
        clusters[i].centroid.y = 0;
        for (int j = 0; j < clusters[i].num_points; j++) {
            clusters[i].centroid.x += clusters[i].points[j].x;
            clusters[i].centroid.y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x /= clusters[i].num_points;
        clusters[i].centroid.y /= clusters[i].num_points;
    }

    // Repeat the above steps until the clusters converge
    int converged = 0;
    while (!converged) {
        converged = 1;
        for (int i = 0; i < num_data_points; i++) {
            int cluster_index = 0;
            double min_distance = INFINITY;
            for (int j = 0; j < num_clusters; j++) {
                double distance = sqrt(pow(data_points[i].x - clusters[j].centroid.x, 2) + pow(data_points[i].y - clusters[j].centroid.y, 2));
                if (distance < min_distance) {
                    min_distance = distance;
                    cluster_index = j;
                }
            }
            if (cluster_index != i) {
                converged = 0;
                clusters[cluster_index].points[clusters[cluster_index].num_points] = data_points[i];
                clusters[cluster_index].num_points++;
                clusters[i].num_points--;
            }
        }
        for (int i = 0; i < num_clusters; i++) {
            clusters[i].centroid.x = 0;
            clusters[i].centroid.y = 0;
            for (int j = 0; j < clusters[i].num_points; j++) {
                clusters[i].centroid.x += clusters[i].points[j].x;
                clusters[i].centroid.y += clusters[i].points[j].y;
            }
            clusters[i].centroid.x /= clusters[i].num_points;
            clusters[i].centroid.y /= clusters[i].num_points;
        }
    }

    // Print the clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    // Free the memory allocated for the clusters
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);
}

// Main function
int main() {
    // Generate some random data points
    data_point* data_points = malloc(sizeof(data_point) * MAX_DATA_POINTS);
    for (int i = 0; i < MAX_DATA_POINTS; i++) {
        data_points[i].x = rand() % 100;
        data_points[i].y = rand() % 100;
    }

    // Perform clustering on the data points
    clustering(data_points, MAX_DATA_POINTS, 10);

    // Free the memory allocated for the data points
    free(data_points);

    return 0;
}