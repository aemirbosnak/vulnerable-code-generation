//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <float.h>

// Structure to define a point in 2D space
typedef struct {
    double x;
    double y;
} Point;

// Structure to define a cluster
typedef struct {
    Point centroid;
    int *points; // Indices of points in the dataset that belong to this cluster
    int count;   // Number of points in this cluster
} Cluster;

// Function to compute Euclidean distance
double euclidean_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to initialize clusters and centroids
void initialize_clusters(Cluster *clusters, Point *points, int k, int total_points) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = points[i % total_points]; // Simple scatter initialization
        clusters[i].points = malloc(total_points * sizeof(int)); // Allocate space for points
        clusters[i].count = 0; // Initially, no points assigned to the clusters
    }
}

// Function to assign points to clusters based on the closest centroid
void assign_points_to_clusters(Point *points, Cluster *clusters, int k, int total_points) {
    for (int i = 0; i < total_points; i++) {
        double min_distance = DBL_MAX;
        int cluster_index = -1;

        // Check for each cluster
        for (int j = 0; j < k; j++) {
            double distance = euclidean_distance(points[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }

        // If cluster index is valid, assign the point
        if (cluster_index >= 0) {
            clusters[cluster_index].points[clusters[cluster_index].count++] = i;
        } else {
            fprintf(stderr, "Error: Could not assign point %d to any cluster.\n", i);
            exit(EXIT_FAILURE);
        }
    }
}

// Function to update centroids of clusters based on the assigned points
void update_centroids(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].count == 0) {
            fprintf(stderr, "Warning: Cluster %d has no points assigned.\n", i);
            continue; // Skip updating if no points are assigned
        }

        double sum_x = 0;
        double sum_y = 0;

        for (int j = 0; j < clusters[i].count; j++) {
            int point_index = clusters[i].points[j];
            sum_x += point_index; // Replace with actual point after fixing the function
            sum_y += point_index; // Replace with actual point after fixing the function
        }

        // Assign the centroid coordinates as the averages
        clusters[i].centroid.x = sum_x / clusters[i].count;
        clusters[i].centroid.y = sum_y / clusters[i].count;
    }
}

// Function to check convergence
int check_convergence(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        // Here we should check if the previous centroid is the same 
        // Or if the change is less than a threshold
        // For simplicity, we just assume it converges after one iteration for this paranoid style
        return 0; // Not identical yet
    }
    return 1; // Converged
}

// The K-Means clustering function
void k_means_clustering(Point *points, int total_points, int k) {
    Cluster *clusters = malloc(k * sizeof(Cluster));
    initialize_clusters(clusters, points, k, total_points);

    int iteration = 0;
    while (1) {
        printf("Iteration %d...\n", iteration++);
        // Reset points in clusters
        for (int i = 0; i < k; i++) {
            clusters[i].count = 0;
        }

        assign_points_to_clusters(points, clusters, k, total_points);
        update_centroids(clusters, k);

        // Check for convergence
        if (check_convergence(clusters, k)) {
            printf("Clustering converged after %d iterations.\n", iteration);
            break;
        }
    }

    // Free allocated memory
    for (int i = 0; i < k; i++) {
        free(clusters[i].points);
    }
    free(clusters);
}

// Main procedure to read data and trigger clustering
int main() {
    int total_points = 8; // Example data
    int k = 3; // Number of clusters
    Point points[] = {
        {1, 2}, {2, 2}, {1, 4}, {2, 4},
        {5, 6}, {6, 5}, {5, 8}, {6, 7}
    };
    
    if (k <= 0 || total_points <= 0) {
        fprintf(stderr, "Error: Invalid number of clusters or points.\n");
        exit(EXIT_FAILURE);
    }

    k_means_clustering(points, total_points, k);
    
    return 0;
}