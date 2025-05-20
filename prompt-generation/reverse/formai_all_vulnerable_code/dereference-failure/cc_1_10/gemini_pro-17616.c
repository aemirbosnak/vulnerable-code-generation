//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the Euclidean distance between two points
double euclidean_distance(double *point1, double *point2, int num_dimensions) {
    double sum = 0;
    for (int i = 0; i < num_dimensions; i++) {
        sum += pow(point1[i] - point2[i], 2);
    }
    return sqrt(sum);
}

// Function to find the closest centroid to a given point
int find_closest_centroid(double *point, double **centroids, int num_centroids, int num_dimensions) {
    int closest_centroid_index = -1;
    double min_distance = INFINITY;
    for (int i = 0; i < num_centroids; i++) {
        double distance = euclidean_distance(point, centroids[i], num_dimensions);
        if (distance < min_distance) {
            min_distance = distance;
            closest_centroid_index = i;
        }
    }
    return closest_centroid_index;
}

// Function to update the centroids of the clusters
void update_centroids(double **data, int *cluster_assignments, int num_data_points, int num_dimensions, int num_clusters, double **centroids) {
    for (int i = 0; i < num_clusters; i++) {
        for (int j = 0; j < num_dimensions; j++) {
            double sum = 0;
            int count = 0;
            for (int k = 0; k < num_data_points; k++) {
                if (cluster_assignments[k] == i) {
                    sum += data[k][j];
                    count++;
                }
            }
            centroids[i][j] = sum / count;
        }
    }
}

// Function to perform k-means clustering on a given dataset
void k_means(double **data, int num_data_points, int num_dimensions, int num_clusters, double **centroids, int max_iterations) {
    // Initialize the cluster assignments randomly
    int *cluster_assignments = malloc(num_data_points * sizeof(int));
    for (int i = 0; i < num_data_points; i++) {
        cluster_assignments[i] = rand() % num_clusters;
    }

    // Iterate until the centroids no longer change or the maximum number of iterations is reached
    int iteration = 0;
    while (iteration < max_iterations) {
        // Update the centroids of the clusters
        update_centroids(data, cluster_assignments, num_data_points, num_dimensions, num_clusters, centroids);

        // Find the closest centroid to each point and update the cluster assignments
        for (int i = 0; i < num_data_points; i++) {
            cluster_assignments[i] = find_closest_centroid(data[i], centroids, num_clusters, num_dimensions);
        }

        iteration++;
    }

    // Print the final cluster assignments
    for (int i = 0; i < num_data_points; i++) {
        printf("Point %d belongs to cluster %d\n", i, cluster_assignments[i]);
    }

    // Free the allocated memory
    free(cluster_assignments);
}

int main() {
    // Initialize the data and the centroids
    double data[][2] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}, {9, 10}};
    double centroids[][2] = {{2, 3}, {6, 7}};

    // Perform k-means clustering
    k_means(data, 5, 2, 2, centroids, 10);

    return 0;
}