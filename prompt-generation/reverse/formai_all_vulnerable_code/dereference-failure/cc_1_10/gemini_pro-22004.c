//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of clusters and data points
#define MAX_CLUSTERS 10
#define MAX_DATA_POINTS 100

// Define the data structure for a data point
typedef struct {
    double x;
    double y;
} DataPoint;

// Define the data structure for a cluster
typedef struct {
    DataPoint centroid;
    int num_points;
    DataPoint* points;
} Cluster;

// Function to create a new cluster
Cluster* create_cluster(DataPoint centroid) {
    Cluster* cluster = malloc(sizeof(Cluster));
    cluster->centroid = centroid;
    cluster->num_points = 0;
    cluster->points = NULL;
    return cluster;
}

// Function to destroy a cluster
void destroy_cluster(Cluster* cluster) {
    free(cluster->points);
    free(cluster);
}

// Function to add a data point to a cluster
void add_data_point_to_cluster(Cluster* cluster, DataPoint data_point) {
    cluster->points = realloc(cluster->points, (cluster->num_points + 1) * sizeof(DataPoint));
    cluster->points[cluster->num_points] = data_point;
    cluster->num_points++;
}

// Function to calculate the distance between two data points
double distance(DataPoint a, DataPoint b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to calculate the centroid of a cluster
DataPoint calculate_centroid(Cluster* cluster) {
    DataPoint centroid;
    centroid.x = 0;
    centroid.y = 0;
    for (int i = 0; i < cluster->num_points; i++) {
        centroid.x += cluster->points[i].x;
        centroid.y += cluster->points[i].y;
    }
    centroid.x /= cluster->num_points;
    centroid.y /= cluster->num_points;
    return centroid;
}

// Function to assign data points to clusters
void assign_data_points_to_clusters(Cluster* clusters, DataPoint* data_points, int num_data_points) {
    for (int i = 0; i < num_data_points; i++) {
        double min_distance = INFINITY;
        int min_cluster_index = -1;
        for (int j = 0; j < MAX_CLUSTERS; j++) {
            double distance_to_centroid = distance(data_points[i], clusters[j].centroid);
            if (distance_to_centroid < min_distance) {
                min_distance = distance_to_centroid;
                min_cluster_index = j;
            }
        }
        add_data_point_to_cluster(&clusters[min_cluster_index], data_points[i]);
    }
}

// Function to update the centroids of the clusters
void update_cluster_centroids(Cluster* clusters) {
    for (int i = 0; i < MAX_CLUSTERS; i++) {
        clusters[i].centroid = calculate_centroid(&clusters[i]);
    }
}

// Function to perform k-means clustering
void k_means_clustering(DataPoint* data_points, int num_data_points, int num_clusters) {
    // Create the initial clusters
    Cluster* clusters = malloc(num_clusters * sizeof(Cluster));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = *create_cluster(data_points[i]);
    }

    // Assign data points to clusters
    assign_data_points_to_clusters(clusters, data_points, num_data_points);

    // Update the centroids of the clusters
    update_cluster_centroids(clusters);

    // Repeat the previous two steps until the centroids no longer change
    int num_iterations = 0;
    while (num_iterations < 100) {
        assign_data_points_to_clusters(clusters, data_points, num_data_points);
        update_cluster_centroids(clusters);
        num_iterations++;
    }

    // Print the final clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }

    // Free the memory allocated for the clusters
    for (int i = 0; i < num_clusters; i++) {
        destroy_cluster(&clusters[i]);
    }
    free(clusters);
}

// Main function
int main() {
    // Create the data points
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

    // Perform k-means clustering
    k_means_clustering(data_points, sizeof(data_points) / sizeof(data_points[0]), 3);

    return 0;
}