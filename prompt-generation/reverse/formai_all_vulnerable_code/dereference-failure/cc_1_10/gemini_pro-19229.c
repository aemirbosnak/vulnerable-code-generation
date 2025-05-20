//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: immersive
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
    int size;
    data_point *points;
    data_point centroid;
} cluster;

// Function to initialize a data point
data_point init_data_point(double x, double y) {
    data_point point;
    point.x = x;
    point.y = y;
    return point;
}

// Function to initialize a cluster
cluster init_cluster(int size) {
    cluster cluster;
    cluster.size = size;
    cluster.points = malloc(sizeof(data_point) * size);
    return cluster;
}

// Function to calculate the distance between two data points
double distance(data_point a, data_point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to calculate the centroid of a cluster
data_point calculate_centroid(cluster cluster) {
    data_point centroid;
    centroid.x = 0;
    centroid.y = 0;
    for (int i = 0; i < cluster.size; i++) {
        centroid.x += cluster.points[i].x;
        centroid.y += cluster.points[i].y;
    }
    centroid.x /= cluster.size;
    centroid.y /= cluster.size;
    return centroid;
}

// Function to assign a data point to a cluster
void assign_point_to_cluster(data_point point, cluster *clusters, int num_clusters) {
    double min_distance = INFINITY;
    int min_distance_cluster = -1;
    for (int i = 0; i < num_clusters; i++) {
        double distance_to_cluster = distance(point, clusters[i].centroid);
        if (distance_to_cluster < min_distance) {
            min_distance = distance_to_cluster;
            min_distance_cluster = i;
        }
    }
    clusters[min_distance_cluster].points[clusters[min_distance_cluster].size++] = point;
}

// Function to perform k-means clustering
void k_means_clustering(data_point *data, int num_data_points, int num_clusters) {
    // Initialize the clusters
    cluster *clusters = malloc(sizeof(cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i] = init_cluster(num_data_points);
    }

    // Assign the data points to the clusters
    for (int i = 0; i < num_data_points; i++) {
        assign_point_to_cluster(data[i], clusters, num_clusters);
    }

    // Calculate the centroids of the clusters
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid = calculate_centroid(clusters[i]);
    }

    // Repeat the previous two steps until the centroids do not change
    int num_iterations = 0;
    while (num_iterations < 100) {
        // Assign the data points to the clusters
        for (int i = 0; i < num_data_points; i++) {
            assign_point_to_cluster(data[i], clusters, num_clusters);
        }

        // Calculate the centroids of the clusters
        for (int i = 0; i < num_clusters; i++) {
            clusters[i].centroid = calculate_centroid(clusters[i]);
        }

        num_iterations++;
    }

    // Print the clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < clusters[i].size; j++) {
            printf("(%f, %f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }

    // Free the memory allocated for the clusters
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);
}

int main() {
    // Initialize the data points
    data_point data[] = {
        init_data_point(1, 2),
        init_data_point(3, 4),
        init_data_point(5, 6),
        init_data_point(7, 8),
        init_data_point(9, 10),
        init_data_point(11, 12),
        init_data_point(13, 14),
        init_data_point(15, 16),
        init_data_point(17, 18),
        init_data_point(19, 20)
    };

    // Perform k-means clustering
    k_means_clustering(data, sizeof(data) / sizeof(data[0]), 3);

    return 0;
}