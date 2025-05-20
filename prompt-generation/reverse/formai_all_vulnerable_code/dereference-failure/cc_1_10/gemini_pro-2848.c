//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the number of data points and features
#define NUM_DATA_POINTS 100
#define NUM_FEATURES 10

// Define the data type for a data point
typedef struct {
    double features[NUM_FEATURES];
    int label;
} DataPoint;

// Define the data type for a cluster
typedef struct {
    DataPoint centroid;
    int num_points;
    DataPoint* points;
} Cluster;

// Define the k-means algorithm
void k_means(DataPoint* data_points, int num_data_points, int num_clusters, Cluster* clusters) {
    // Initialize the clusters randomly
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid = data_points[rand() % num_data_points];
        clusters[i].num_points = 0;
        clusters[i].points = NULL;
    }

    // Iterate until the clusters no longer change
    int converged = 0;
    while (!converged) {
        // Assign each data point to the nearest cluster
        for (int i = 0; i < num_data_points; i++) {
            double min_distance = INFINITY;
            int min_cluster_index = -1;
            for (int j = 0; j < num_clusters; j++) {
                double distance = 0;
                for (int k = 0; k < NUM_FEATURES; k++) {
                    distance += pow(data_points[i].features[k] - clusters[j].centroid.features[k], 2);
                }
                distance = sqrt(distance);
                if (distance < min_distance) {
                    min_distance = distance;
                    min_cluster_index = j;
                }
            }
            clusters[min_cluster_index].num_points++;
            clusters[min_cluster_index].points = realloc(clusters[min_cluster_index].points, clusters[min_cluster_index].num_points * sizeof(DataPoint));
            clusters[min_cluster_index].points[clusters[min_cluster_index].num_points - 1] = data_points[i];
        }

        // Update the centroids of the clusters
        for (int i = 0; i < num_clusters; i++) {
            for (int j = 0; j < NUM_FEATURES; j++) {
                clusters[i].centroid.features[j] = 0;
                for (int k = 0; k < clusters[i].num_points; k++) {
                    clusters[i].centroid.features[j] += clusters[i].points[k].features[j];
                }
                clusters[i].centroid.features[j] /= clusters[i].num_points;
            }
        }

        // Check if the clusters have converged
        converged = 1;
        for (int i = 0; i < num_clusters; i++) {
            for (int j = 0; j < NUM_FEATURES; j++) {
                if (fabs(clusters[i].centroid.features[j] - clusters[i].points[0].features[j]) > 0.01) {
                    converged = 0;
                    break;
                }
            }
        }
    }
}

// Print the clusters
void print_clusters(Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < NUM_FEATURES; j++) {
            printf("%f ", clusters[i].centroid.features[j]);
        }
        printf("\n");
        for (int j = 0; j < clusters[i].num_points; j++) {
            for (int k = 0; k < NUM_FEATURES; k++) {
                printf("%f ", clusters[i].points[j].features[k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Generate random data points
DataPoint* generate_data_points(int num_data_points) {
    DataPoint* data_points = malloc(num_data_points * sizeof(DataPoint));
    for (int i = 0; i < num_data_points; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            data_points[i].features[j] = (double)rand() / RAND_MAX;
        }
        data_points[i].label = rand() % 2;
    }
    return data_points;
}

// Main function
int main() {
    // Generate random data points
    DataPoint* data_points = generate_data_points(NUM_DATA_POINTS);

    // Create clusters
    Cluster* clusters = malloc(3 * sizeof(Cluster));

    // Perform k-means clustering
    k_means(data_points, NUM_DATA_POINTS, 3, clusters);

    // Print the clusters
    print_clusters(clusters, 3);

    // Free the allocated memory
    free(data_points);
    for (int i = 0; i < 3; i++) {
        free(clusters[i].points);
    }
    free(clusters);

    return 0;
}