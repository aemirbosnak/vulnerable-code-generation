//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the data types for the data points and clusters
typedef struct {
    double x; // x-coordinate
    double y; // y-coordinate
    int cluster; // cluster label
} DataPoint;

typedef struct {
    double x; // x-coordinate
    double y; // y-coordinate
    int num_points; // number of data points in the cluster
} Cluster;

// Generate a random data set
DataPoint* generate_data(int num_points) {
    DataPoint* data = (DataPoint*)malloc(num_points * sizeof(DataPoint));
    for (int i = 0; i < num_points; i++) {
        data[i].x = (double)rand() / RAND_MAX;
        data[i].y = (double)rand() / RAND_MAX;
        data[i].cluster = -1;
    }
    return data;
}

// Initialize the clusters
Cluster* initialize_clusters(int num_clusters, DataPoint* data, int num_points) {
    Cluster* clusters = (Cluster*)malloc(num_clusters * sizeof(Cluster));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].x = data[i].x;
        clusters[i].y = data[i].y;
        clusters[i].num_points = 1;
    }
    return clusters;
}

// Assign data points to clusters
void assign_clusters(DataPoint* data, int num_points, Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        int min_cluster = -1;
        for (int j = 0; j < num_clusters; j++) {
            double distance = sqrt(pow(data[i].x - clusters[j].x, 2) + pow(data[i].y - clusters[j].y, 2));
            if (distance < min_distance) {
                min_distance = distance;
                min_cluster = j;
            }
        }
        data[i].cluster = min_cluster;
    }
}

// Update the clusters
void update_clusters(DataPoint* data, int num_points, Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        double sum_x = 0;
        double sum_y = 0;
        int num_points = 0;
        for (int j = 0; j < num_points; j++) {
            if (data[j].cluster == i) {
                sum_x += data[j].x;
                sum_y += data[j].y;
                num_points++;
            }
        }
        clusters[i].x = sum_x / num_points;
        clusters[i].y = sum_y / num_points;
        clusters[i].num_points = num_points;
    }
}

// Main function
int main() {
    // Generate a random data set
    int num_points = 100;
    DataPoint* data = generate_data(num_points);

    // Initialize the clusters
    int num_clusters = 3;
    Cluster* clusters = initialize_clusters(num_clusters, data, num_points);

    // Assign data points to clusters
    assign_clusters(data, num_points, clusters, num_clusters);

    // Update the clusters
    update_clusters(data, num_points, clusters, num_clusters);

    // Print the clusters
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d: (%f, %f), %d points\n", i, clusters[i].x, clusters[i].y, clusters[i].num_points);
    }

    // Free the memory
    free(data);
    free(clusters);
    return 0;
}