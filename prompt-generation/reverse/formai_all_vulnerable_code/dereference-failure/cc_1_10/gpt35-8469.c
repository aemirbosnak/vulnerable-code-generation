//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Custom data structure for representing a point in 3D space
typedef struct _point {
    float x;
    float y;
    float z;
} Point;

// Function to calculate the Euclidean distance between two points
float euclidean_dist(Point p1, Point p2) {
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    float dz = p1.z - p2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Function to assign initial centroids to clusters
void assign_initial_centroids(Point* data_points, int num_points, Point* centroids, int num_clusters) {
    // Let's choose the first k points as initial centroids
    for (int i = 0; i < num_clusters; i++) {
        centroids[i].x = data_points[i].x;
        centroids[i].y = data_points[i].y;
        centroids[i].z = data_points[i].z;
    }
}

// Function to perform the clustering using the k-means algorithm
void k_means_clustering(Point* data_points, int num_points, int num_clusters) {
    // Allocate memory for the centroid points
    Point* centroids = (Point*)malloc(num_clusters * sizeof(Point));

    // Assign initial centroids to clusters
    assign_initial_centroids(data_points, num_points, centroids, num_clusters);

    // Create an array to hold the cluster assignments for each data point
    int* cluster_assignments = (int*)calloc(num_points, sizeof(int));

    // Create an array to hold the number of points in each cluster
    int* cluster_counts = (int*)calloc(num_clusters, sizeof(int));

    // Loop until convergence
    int max_iterations = 1000;
    int iterations = 0;
    float threshold = 0.001;
    while (iterations < max_iterations) {
        // Clear the cluster counts
        for (int i = 0; i < num_clusters; i++) {
            cluster_counts[i] = 0;
        }

        // Assign each data point to a cluster
        for (int i = 0; i < num_points; i++) {
            float min_dist = INFINITY;
            int min_cluster = 0;
            for (int j = 0; j < num_clusters; j++) {
                float dist = euclidean_dist(data_points[i], centroids[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    min_cluster = j;
                }
            }
            cluster_assignments[i] = min_cluster;
            cluster_counts[min_cluster]++;
        }

        // Update the centroids
        for (int i = 0; i < num_clusters; i++) {
            Point new_centroid = {0, 0, 0};
            int count = 0;
            for (int j = 0; j < num_points; j++) {
                if (cluster_assignments[j] == i) {
                    new_centroid.x += data_points[j].x;
                    new_centroid.y += data_points[j].y;
                    new_centroid.z += data_points[j].z;
                    count++;
                }
            }
            new_centroid.x /= count;
            new_centroid.y /= count;
            new_centroid.z /= count;
            if (euclidean_dist(new_centroid, centroids[i]) > threshold) {
                centroids[i] = new_centroid;
            }
        }

        // Check for convergence
        int converged = 1;
        for (int i = 0; i < num_clusters; i++) {
            if (cluster_counts[i] == 0) {
                assign_initial_centroids(data_points, num_points, centroids, num_clusters);
                converged = 0;
                break;
            }
        }
        if (converged) {
            break;
        }

        iterations++;
    }

    // Print the cluster assignments
    printf("Cluster assignments:\n");
    for (int i = 0; i < num_points; i++) {
        printf("%d ", cluster_assignments[i]);
    }

    // Free memory
    free(centroids);
    free(cluster_assignments);
    free(cluster_counts);
}

// Test the algorithm on some sample data
int main() {
    Point data_points[] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
        {10.0, 11.0, 12.0},
        {13.0, 14.0, 15.0},
        {16.0, 17.0, 18.0},
        {19.0, 20.0, 21.0},
        {22.0, 23.0, 24.0},
        {25.0, 26.0, 27.0},
        {28.0, 29.0, 30.0}
    };
    int num_points = sizeof(data_points) / sizeof(Point);
    int num_clusters = 3;

    k_means_clustering(data_points, num_points, num_clusters);

    return 0;
}