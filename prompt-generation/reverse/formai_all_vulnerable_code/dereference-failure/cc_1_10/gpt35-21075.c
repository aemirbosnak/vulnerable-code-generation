//FormAI DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DATASET_SIZE 1000
#define NUM_FEATURES 10
#define NUM_CLUSTERS 5

typedef struct {
    double features[NUM_FEATURES];
} DataPoint;

typedef struct {
    double centroid[NUM_FEATURES];
    int num_points;
    DataPoint *points;
} Cluster;

// Generate random data points (for demonstration purposes)
DataPoint *generate_data_points() {
    DataPoint *points = malloc(sizeof(DataPoint) * DATASET_SIZE);

    for (int i = 0; i < DATASET_SIZE; i++) {
        for (int j = 0; j < NUM_FEATURES; j++) {
            points[i].features[j] = ((double) rand() / RAND_MAX) * 10.0;
        }
    }

    return points;
}

// Initialize clusters randomly using k-means++
void initialize_clusters(DataPoint *data, Cluster *clusters) {
    // Choose the first centroid randomly
    int first_centroid = rand() % DATASET_SIZE;
    for (int i = 0; i < NUM_FEATURES; i++) {
        clusters[0].centroid[i] = data[first_centroid].features[i];
    }
    clusters[0].num_points = 0;
    clusters[0].points = NULL;

    // Choose the remaining centroids using k-means++
    for (int i = 1; i < NUM_CLUSTERS; i++) {
        double max_distance = 0.0;
        double *distances = malloc(sizeof(double) * DATASET_SIZE);

        // Calculate the distance from each data point to the nearest cluster
        for (int j = 0; j < DATASET_SIZE; j++) {
            double min_distance = INFINITY;
            for (int k = 0; k < i; k++) {
                double distance = 0.0;
                for (int l = 0; l < NUM_FEATURES; l++) {
                    double diff = data[j].features[l] - clusters[k].centroid[l];
                    distance += diff * diff;
                }
                if (distance < min_distance) {
                    min_distance = distance;
                }
            }
            distances[j] = min_distance;
        }

        // Choose the next centroid randomly weighted by distance squared
        double total_distance_squared = 0.0;
        for (int j = 0; j < DATASET_SIZE; j++) {
            total_distance_squared += distances[j];
        }
        double random = ((double) rand() / RAND_MAX) * total_distance_squared;
        double running_total = 0.0;
        for (int j = 0; j < DATASET_SIZE; j++) {
            running_total += distances[j];
            if (running_total > random) {
                for (int k = 0; k < NUM_FEATURES; k++) {
                    clusters[i].centroid[k] = data[j].features[k];
                }
                clusters[i].num_points = 0;
                clusters[i].points = NULL;
                break;
            }
        }

        free(distances);
    }
}

// Assign each data point to the nearest cluster
void assign_points_to_clusters(DataPoint *data, Cluster *clusters) {
    for (int i = 0; i < DATASET_SIZE; i++) {
        int nearest_cluster = 0;
        double min_distance = INFINITY;
        for (int j = 0; j < NUM_CLUSTERS; j++) {
            double distance = 0.0;
            for (int k = 0; k < NUM_FEATURES; k++) {
                double diff = data[i].features[k] - clusters[j].centroid[k];
                distance += diff * diff;
            }
            if (distance < min_distance) {
                nearest_cluster = j;
                min_distance = distance;
            }
        }

        clusters[nearest_cluster].num_points++;
        clusters[nearest_cluster].points = realloc(clusters[nearest_cluster].points,
            sizeof(DataPoint) * clusters[nearest_cluster].num_points);
        clusters[nearest_cluster].points[clusters[nearest_cluster].num_points - 1] = data[i];
    }
}

// Recalculate the centroids of each cluster as the mean of its data points
void recalculate_centroids(Cluster *clusters) {
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        if (clusters[i].num_points == 0) {
            continue;
        }
        for (int j = 0; j < NUM_FEATURES; j++) {
            double sum = 0.0;
            for (int k = 0; k < clusters[i].num_points; k++) {
                sum += clusters[i].points[k].features[j];
            }
            clusters[i].centroid[j] = sum / clusters[i].num_points;
        }
    }
}

int main() {
    // Generate random data points
    DataPoint *data = generate_data_points();

    // Initialize clusters randomly using k-means++
    Cluster *clusters = malloc(sizeof(Cluster) * NUM_CLUSTERS);
    initialize_clusters(data, clusters);

    // Run k-means algorithm
    for (int i = 0; i < 100; i++) {
        assign_points_to_clusters(data, clusters);
        recalculate_centroids(clusters);
        printf("Iteration %d:\n", i + 1);
        for (int j = 0; j < NUM_CLUSTERS; j++) {
            printf("Cluster %d:\n", j + 1);
            printf("\tCentroid: (");
            for (int k = 0; k < NUM_FEATURES; k++) {
                printf("%lf", clusters[j].centroid[k]);
                if (k != NUM_FEATURES - 1) {
                    printf(", ");
                }
            }
            printf(")\n");
            printf("\tNum points: %d\n", clusters[j].num_points);
        }
    }

    // Free memory
    free(data);
    for (int i = 0; i < NUM_CLUSTERS; i++) {
        free(clusters[i].points);
    }
    free(clusters);

    return 0;
}