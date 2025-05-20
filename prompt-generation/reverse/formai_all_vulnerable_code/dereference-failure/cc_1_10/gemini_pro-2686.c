//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of data points and the maximum number of clusters
#define MAX_DATA_POINTS 100
#define MAX_CLUSTERS 10

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
void initialize_clusters(Cluster* clusters, int num_clusters, DataPoint* data_points, int num_data_points) {
    // Randomly select the centroids of the clusters
    for (int i = 0; i < num_clusters; i++) {
        int index = rand() % num_data_points;
        clusters[i].centroid = data_points[index];
    }

    // Initialize the number of points in each cluster to 0
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].num_points = 0;
    }

    // Allocate memory for the points in each cluster
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].points = malloc(sizeof(DataPoint) * num_data_points);
    }
}

// Function to assign the data points to the clusters
void assign_data_points_to_clusters(Cluster* clusters, int num_clusters, DataPoint* data_points, int num_data_points) {
    // For each data point, find the closest cluster and assign it to that cluster
    for (int i = 0; i < num_data_points; i++) {
        double min_distance = INFINITY;
        int min_cluster_index = -1;

        for (int j = 0; j < num_clusters; j++) {
            double distance = sqrt(pow(data_points[i].x - clusters[j].centroid.x, 2) + pow(data_points[i].y - clusters[j].centroid.y, 2));

            if (distance < min_distance) {
                min_distance = distance;
                min_cluster_index = j;
            }
        }

        clusters[min_cluster_index].points[clusters[min_cluster_index].num_points] = data_points[i];
        clusters[min_cluster_index].num_points++;
    }
}

// Function to update the centroids of the clusters
void update_cluster_centroids(Cluster* clusters, int num_clusters) {
    // For each cluster, calculate the new centroid by averaging the positions of the points in the cluster
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

// Function to print the clusters
void print_clusters(Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        printf("Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Number of points: %d\n", clusters[i].num_points);
        printf("Points:\n");

        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }

        printf("\n");
    }
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Define the number of data points and the number of clusters
    int num_data_points = 100;
    int num_clusters = 10;

    // Allocate memory for the data points and the clusters
    DataPoint* data_points = malloc(sizeof(DataPoint) * num_data_points);
    Cluster* clusters = malloc(sizeof(Cluster) * num_clusters);

    // Initialize the data points and the clusters
    initialize_data_points(data_points, num_data_points);
    initialize_clusters(clusters, num_clusters, data_points, num_data_points);

    // Assign the data points to the clusters
    assign_data_points_to_clusters(clusters, num_clusters, data_points, num_data_points);

    // Update the centroids of the clusters
    update_cluster_centroids(clusters, num_clusters);

    // Print the clusters
    print_clusters(clusters, num_clusters);

    // Free the memory allocated for the data points and the clusters
    free(data_points);
    free(clusters);

    return 0;
}