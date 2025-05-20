//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Define struct for data point
typedef struct DataPoint {
    int x;
    int y;
} DataPoint;

// Define struct for cluster
typedef struct Cluster {
    DataPoint center;
    int size;
    DataPoint *points;
} Cluster;

// Calculate euclidean distance between two data points
double distance(DataPoint p1, DataPoint p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Initialize k clusters at random data points
Cluster* initialize_clusters(DataPoint* data_points, int num_points, int num_clusters) {
    Cluster* clusters = malloc(num_clusters * sizeof(Cluster));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].center = data_points[rand() % num_points];
        clusters[i].size = 0;
        clusters[i].points = malloc(num_points * sizeof(DataPoint));
    }
    return clusters;
}

// Assign each data point to the nearest cluster
void assign_clusters(DataPoint* data_points, int num_points, Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        for (int j = 0; j < num_clusters; j++) {
            double current_distance = distance(data_points[i], clusters[j].center);
            if (current_distance < min_distance) {
                clusters[j].points[clusters[j].size] = data_points[i];
                clusters[j].size++;
                min_distance = current_distance;
            }
        }
    }
}

// Recalculate cluster centers based on assigned data points
void recalculate_cluster_centers(Cluster* clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        int total_x = 0;
        int total_y = 0;
        for (int j = 0; j < clusters[i].size; j++) {
            total_x += clusters[i].points[j].x;
            total_y += clusters[i].points[j].y;
        }
        clusters[i].center.x = total_x / clusters[i].size;
        clusters[i].center.y = total_y / clusters[i].size;
        clusters[i].size = 0;
    }
}

// Check if clusters have converged (no further changes in assigned data points)
bool converged(Cluster* old_clusters, Cluster* new_clusters, int num_clusters) {
    for (int i = 0; i < num_clusters; i++) {
        if (old_clusters[i].center.x != new_clusters[i].center.x || old_clusters[i].center.y != new_clusters[i].center.y) {
            return false;
        }
    }
    return true;
}

// Perform k-means clustering on data points
Cluster* k_means(DataPoint* data_points, int num_points, int num_clusters, int max_iterations) {
    Cluster* current_clusters = initialize_clusters(data_points, num_points, num_clusters);
    Cluster* new_clusters = initialize_clusters(data_points, num_points, num_clusters);
    int iterations = 0;
    bool converged_flag = false;
    while (iterations < max_iterations && !converged_flag) {
        assign_clusters(data_points, num_points, current_clusters, num_clusters);
        recalculate_cluster_centers(current_clusters, num_clusters);
        converged_flag = converged(current_clusters, new_clusters, num_clusters);
        iterations++;
    }
    free(new_clusters);
    return current_clusters;
}

int main() {
    DataPoint data_points[] = {{2, 10}, {2, 5}, {8, 4}, {5, 8}, {7, 5}, {6, 4}, {1, 2}, {4, 9}};
    int num_points = sizeof(data_points) / sizeof(DataPoint);
    int num_clusters = 2;
    int max_iterations = 10;
    Cluster* clusters = k_means(data_points, num_points, num_clusters, max_iterations);
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d (center: %d,%d):\n", i+1, clusters[i].center.x, clusters[i].center.y);
        for (int j = 0; j < clusters[i].size; j++) {
            printf("(%d,%d) ", clusters[i].points[j].x, clusters[i].points[j].y);
        }
        printf("\n");
    }
    free(clusters);
    return 0;
}