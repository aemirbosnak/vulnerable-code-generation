//Falcon2-11B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Function to calculate Euclidean distance between two points
double euclidean_distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

// Function to cluster points based on Euclidean distance
void cluster_points(double* points, int num_points, int num_clusters, double* cluster_centers) {
    // Initialize cluster centers
    for (int i = 0; i < num_clusters; i++) {
        cluster_centers[i] = points[rand() % num_points];
    }

    // Initialize cluster assignments
    for (int i = 0; i < num_points; i++) {
        int cluster = -1;

        // Find closest cluster center
        double min_distance = euclidean_distance(points[i], points[0], cluster_centers[0], cluster_centers[0]);
        int min_index = 0;
        for (int j = 1; j < num_clusters; j++) {
            double distance = euclidean_distance(points[i], points[0], cluster_centers[j], cluster_centers[j]);
            if (distance < min_distance) {
                min_distance = distance;
                min_index = j;
            }
        }

        // Assign point to closest cluster center
        cluster_centers[min_index] = points[i];
        cluster = min_index;

        // Update cluster assignments
        for (int j = 0; j < num_points; j++) {
            if (points[j] == points[i]) {
                points[j] = cluster_centers[cluster];
            }
        }
    }
}

// Function to print cluster assignments
void print_cluster_assignments(double* points, int num_points, int* cluster_assignments) {
    for (int i = 0; i < num_points; i++) {
        printf("%d %f\n", cluster_assignments[i], points[i]);
    }
}

// Function to generate random points
void generate_random_points(double* points, int num_points) {
    for (int i = 0; i < num_points; i++) {
        points[i] = (double)rand() / RAND_MAX;
    }
}

int main() {
    // Generate random points
    int num_points = 1000;
    double* points = malloc(num_points * sizeof(double));
    generate_random_points(points, num_points);

    // Cluster points
    int num_clusters = 3;
    double* cluster_centers = malloc(num_clusters * sizeof(double));
    cluster_points(points, num_points, num_clusters, cluster_centers);

    // Print cluster assignments
    int* cluster_assignments = malloc(num_points * sizeof(int));
    for (int i = 0; i < num_points; i++) {
        cluster_assignments[i] = i % num_clusters;
    }
    print_cluster_assignments(points, num_points, cluster_assignments);

    // Free memory
    free(points);
    free(cluster_centers);
    free(cluster_assignments);

    return 0;
}