//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data point structure
typedef struct {
    double x;
    double y;
} data_point;

// Define the cluster structure
typedef struct {
    int num_points;
    data_point *points;
    double centroid_x;
    double centroid_y;
} cluster;

// Create a new data point
data_point *create_data_point(double x, double y) {
    data_point *point = malloc(sizeof(data_point));
    point->x = x;
    point->y = y;
    return point;
}

// Create a new cluster
cluster *create_cluster() {
    cluster *cluster = malloc(sizeof(cluster));
    cluster->num_points = 0;
    cluster->points = NULL;
    cluster->centroid_x = 0.0;
    cluster->centroid_y = 0.0;
    return cluster;
}

// Add a data point to a cluster
void add_data_point_to_cluster(cluster *cluster, data_point *point) {
    cluster->num_points++;
    cluster->points = realloc(cluster->points, sizeof(data_point) * cluster->num_points);
    cluster->points[cluster->num_points - 1] = *point;
}

// Calculate the centroid of a cluster
void calculate_centroid(cluster *cluster) {
    double sum_x = 0.0;
    double sum_y = 0.0;
    for (int i = 0; i < cluster->num_points; i++) {
        sum_x += cluster->points[i].x;
        sum_y += cluster->points[i].y;
    }
    cluster->centroid_x = sum_x / cluster->num_points;
    cluster->centroid_y = sum_y / cluster->num_points;
}

// Assign data points to clusters
void assign_data_points_to_clusters(cluster *clusters, int num_clusters, data_point *data_points, int num_data_points) {
    for (int i = 0; i < num_data_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            double distance = sqrt(pow(clusters[j].centroid_x - data_points[i].x, 2) + pow(clusters[j].centroid_y - data_points[i].y, 2));
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster = j;
            }
        }
        add_data_point_to_cluster(&clusters[closest_cluster], &data_points[i]);
    }
}

// Update the centroids of the clusters
void update_centroids(cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        calculate_centroid(&clusters[i]);
    }
}

// Perform k-means clustering
void k_means_clustering(cluster *clusters, int num_clusters, data_point *data_points, int num_data_points, int max_iterations) {
    // Initialize the clusters
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = *create_cluster();
    }

    // Assign data points to clusters
    assign_data_points_to_clusters(clusters, num_clusters, data_points, num_data_points);

    // Update the centroids of the clusters
    update_centroids(clusters, num_clusters);

    // Repeat the previous two steps until the centroids no longer change or the maximum number of iterations has been reached
    int iteration = 0;
    while (iteration < max_iterations) {
        // Assign data points to clusters
        assign_data_points_to_clusters(clusters, num_clusters, data_points, num_data_points);

        // Update the centroids of the clusters
        update_centroids(clusters, num_clusters);

        iteration++;
    }
}

// Print the clusters
void print_clusters(cluster *clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i + 1);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("  (%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create the data points
    data_point data_points[] = {
        {1.0, 1.0},
        {1.5, 2.0},
        {3.0, 4.0},
        {5.0, 7.0},
        {3.5, 5.0},
        {4.5, 6.0},
        {6.0, 8.0},
        {8.0, 10.0},
        {10.0, 12.0},
        {12.0, 14.0}
    };
    int num_data_points = sizeof(data_points) / sizeof(data_points[0]);

    // Create the clusters
    cluster clusters[3];
    int num_clusters = sizeof(clusters) / sizeof(clusters[0]);

    // Perform k-means clustering
    k_means_clustering(clusters, num_clusters, data_points, num_data_points, 100);

    // Print the clusters
    print_clusters(clusters, num_clusters);

    return 0;
}