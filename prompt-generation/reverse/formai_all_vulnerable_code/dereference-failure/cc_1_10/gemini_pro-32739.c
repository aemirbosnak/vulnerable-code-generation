//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Data point structure
typedef struct {
    double x;
    double y;
} DataPoint;

// Cluster structure
typedef struct {
    DataPoint centroid;
    int num_points;
    DataPoint* points;
} Cluster;

// Function to calculate the distance between two data points
double distance(DataPoint a, DataPoint b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Function to assign a data point to the closest cluster
int assign_cluster(DataPoint point, Cluster* clusters, int num_clusters) {
    int closest_cluster = 0;
    double min_distance = distance(point, clusters[0].centroid);

    for (int i = 1; i < num_clusters; i++) {
        double dist = distance(point, clusters[i].centroid);
        if (dist < min_distance) {
            min_distance = dist;
            closest_cluster = i;
        }
    }

    return closest_cluster;
}

// Function to update the centroid of a cluster
void update_centroid(Cluster* cluster) {
    double new_x = 0;
    double new_y = 0;

    for (int i = 0; i < cluster->num_points; i++) {
        new_x += cluster->points[i].x;
        new_y += cluster->points[i].y;
    }

    cluster->centroid.x = new_x / cluster->num_points;
    cluster->centroid.y = new_y / cluster->num_points;
}

// Function to perform k-means clustering
void k_means(DataPoint* data, int num_data, int num_clusters) {
    // Initialize clusters
    Cluster* clusters = (Cluster*)malloc(sizeof(Cluster) * num_clusters);
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].centroid.x = data[i].x;
        clusters[i].centroid.y = data[i].y;
        clusters[i].num_points = 0;
        clusters[i].points = NULL;
    }

    // Assign data points to clusters
    for (int i = 0; i < num_data; i++) {
        int cluster_index = assign_cluster(data[i], clusters, num_clusters);
        clusters[cluster_index].num_points++;
        clusters[cluster_index].points = realloc(clusters[cluster_index].points, sizeof(DataPoint) * clusters[cluster_index].num_points);
        clusters[cluster_index].points[clusters[cluster_index].num_points - 1] = data[i];
    }

    // Update cluster centroids
    for (int i = 0; i < num_clusters; i++) {
        update_centroid(&clusters[i]);
    }

    // Repeat until convergence
    int num_iterations = 0;
    int converged = 0;
    while (!converged) {
        num_iterations++;

        // Assign data points to clusters
        for (int i = 0; i < num_data; i++) {
            int cluster_index = assign_cluster(data[i], clusters, num_clusters);
            if (cluster_index != assign_cluster(data[i], clusters, num_clusters)) {
                converged = 0;
            }
            clusters[cluster_index].num_points++;
            clusters[cluster_index].points = realloc(clusters[cluster_index].points, sizeof(DataPoint) * clusters[cluster_index].num_points);
            clusters[cluster_index].points[clusters[cluster_index].num_points - 1] = data[i];
        }

        // Update cluster centroids
        for (int i = 0; i < num_clusters; i++) {
            update_centroid(&clusters[i]);
        }

        if (num_iterations > 100) {
            converged = 1;
        }
    }

    // Print the clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d:\n", i);
        printf("Centroid: (%f, %f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf("Number of points: %d\n", clusters[i].num_points);
        for (int j = 0; j < clusters[i].num_points; j++) {
            printf("Point %d: (%f, %f)\n", j, clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }

    // Free memory
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].points);
    }
    free(clusters);
}

int main() {
    // Data points
    DataPoint data[] = {
        {1.0, 2.0},
        {2.0, 2.0},
        {3.0, 2.0},
        {1.0, 4.0},
        {2.0, 4.0},
        {3.0, 4.0},
        {1.0, 6.0},
        {2.0, 6.0},
        {3.0, 6.0}
    };

    int num_data = sizeof(data) / sizeof(data[0]);

    // Number of clusters
    int num_clusters = 3;

    // Perform k-means clustering
    k_means(data, num_data, num_clusters);

    return 0;
}