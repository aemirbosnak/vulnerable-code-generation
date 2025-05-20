//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of clusters and data points
#define MAX_CLUSTERS 10
#define MAX_DATA_POINTS 100

// Define the data point structure
typedef struct {
    double x;
    double y;
} DataPoint;

// Define the cluster structure
typedef struct {
    DataPoint centroid;
    int num_points;
    DataPoint* points;
} Cluster;

// Function to initialize the data points
void initialize_data_points(DataPoint* data_points, int num_data_points) {
    for (int i = 0; i < num_data_points; i++) {
        data_points[i].x = rand() % 100;
        data_points[i].y = rand() % 100;
    }
}

// Function to initialize the clusters
void initialize_clusters(Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = rand() % 100;
        clusters[i].centroid.y = rand() % 100;
        clusters[i].num_points = 0;
        clusters[i].points = NULL;
    }
}

// Function to assign data points to clusters
void assign_data_points_to_clusters(DataPoint* data_points, int num_data_points, Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_data_points; i++) {
        double min_distance = INFINITY;
        int closest_cluster_index = -1;

        // Find the closest cluster to the data point
        for (int j = 0; j < num_clusters; j++) {
            double distance = sqrt(pow(data_points[i].x - clusters[j].centroid.x, 2) + pow(data_points[i].y - clusters[j].centroid.y, 2));
            if (distance < min_distance) {
                min_distance = distance;
                closest_cluster_index = j;
            }
        }

        // Assign the data point to the closest cluster
        clusters[closest_cluster_index].points = realloc(clusters[closest_cluster_index].points, sizeof(DataPoint) * (clusters[closest_cluster_index].num_points + 1));
        clusters[closest_cluster_index].points[clusters[closest_cluster_index].num_points] = data_points[i];
        clusters[closest_cluster_index].num_points++;
    }
}

// Function to update the centroids of the clusters
void update_cluster_centroids(Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        double sum_x = 0;
        double sum_y = 0;

        // Calculate the sum of the x and y coordinates of the data points in the cluster
        for (int j = 0; j < clusters[i].num_points; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }

        // Update the centroid of the cluster
        clusters[i].centroid.x = sum_x / clusters[i].num_points;
        clusters[i].centroid.y = sum_y / clusters[i].num_points;
    }
}

// Function to print the clusters
void print_clusters(Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        printf("Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Number of data points: %d\n", clusters[i].num_points);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("Data point %d: (%f, %f)\n", j, clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Define the number of clusters and data points
    int num_clusters = 3;
    int num_data_points = 100;

    // Allocate memory for the data points and clusters
    DataPoint* data_points = malloc(sizeof(DataPoint) * num_data_points);
    Cluster* clusters = malloc(sizeof(Cluster) * num_clusters);

    // Initialize the data points and clusters
    initialize_data_points(data_points, num_data_points);
    initialize_clusters(clusters, num_clusters);

    // Assign the data points to the clusters
    assign_data_points_to_clusters(data_points, num_data_points, clusters, num_clusters);

    // Update the centroids of the clusters
    update_cluster_centroids(clusters, num_clusters);

    // Print the clusters
    print_clusters(clusters, num_clusters);

    // Free the allocated memory
    free(data_points);
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);

    return 0;
}