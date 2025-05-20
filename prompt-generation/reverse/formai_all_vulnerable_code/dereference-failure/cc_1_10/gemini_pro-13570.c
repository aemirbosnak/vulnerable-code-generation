//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: calm
// C program to demonstrate data mining using k-means clustering.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data structure to represent a data point.
typedef struct DataPoint {
    double x;
    double y;
} DataPoint;

// Function to calculate the Euclidean distance between two data points.
double calculate_distance(DataPoint p1, DataPoint p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Function to assign a data point to the nearest cluster.
int assign_cluster(DataPoint data_point, DataPoint* centroids, int num_clusters) {
    double min_distance = INFINITY;
    int assigned_cluster = -1;
    for (int i = 0; i < num_clusters; i++) {
        double distance = calculate_distance(data_point, centroids[i]);
        if (distance < min_distance) {
            min_distance = distance;
            assigned_cluster = i;
        }
    }
    return assigned_cluster;
}

// Function to update the cluster centroids.
void update_centroids(DataPoint* data_points, int* cluster_assignments, DataPoint* centroids, int num_clusters, int num_data_points) {
    for (int i = 0; i < num_clusters; i++) {
        int count = 0;
        centroids[i].x = 0;
        centroids[i].y = 0;
        for (int j = 0; j < num_data_points; j++) {
            if (cluster_assignments[j] == i) {
                centroids[i].x += data_points[j].x;
                centroids[i].y += data_points[j].y;
                count++;
            }
        }
        if (count > 0) {
            centroids[i].x /= count;
            centroids[i].y /= count;
        }
    }
}

// Function to perform k-means clustering.
void k_means_clustering(DataPoint* data_points, int num_data_points, int num_clusters, int max_iterations) {
    // Initialize cluster centroids randomly.
    DataPoint* centroids = malloc(sizeof(DataPoint) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        centroids[i].x = rand() % 100;
        centroids[i].y = rand() % 100;
    }

    // Assign each data point to the nearest cluster.
    int* cluster_assignments = malloc(sizeof(int) * num_data_points);
    for (int i = 0; i < num_data_points; i++) {
        cluster_assignments[i] = assign_cluster(data_points[i], centroids, num_clusters);
    }

    // Iterate until the cluster centroids no longer change.
    int iteration = 0;
    while (iteration < max_iterations) {
        // Update the cluster centroids.
        update_centroids(data_points, cluster_assignments, centroids, num_clusters, num_data_points);

        // Reassign each data point to the nearest cluster.
        int changed = 0;
        for (int i = 0; i < num_data_points; i++) {
            int new_cluster = assign_cluster(data_points[i], centroids, num_clusters);
            if (new_cluster != cluster_assignments[i]) {
                cluster_assignments[i] = new_cluster;
                changed = 1;
            }
        }

        // If no data point changed cluster, stop iterating.
        if (!changed) {
            break;
        }

        iteration++;
    }

    // Print the cluster assignments.
    for (int i = 0; i < num_data_points; i++) {
        printf("Data point (%f, %f) belongs to cluster %d\n", data_points[i].x, data_points[i].y, cluster_assignments[i]);
    }

    // Free the allocated memory.
    free(centroids);
    free(cluster_assignments);
}

// Main function.
int main() {
    // Define the data points.
    DataPoint data_points[] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10},
        {11, 12},
        {13, 14},
        {15, 16},
        {17, 18},
        {19, 20}
    };
    int num_data_points = sizeof(data_points) / sizeof(data_points[0]);

    // Perform k-means clustering with 3 clusters and a maximum of 10 iterations.
    k_means_clustering(data_points, num_data_points, 3, 10);

    return 0;
}