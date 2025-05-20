//GPT-4o-mini DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point centroid;
    Point *points;
    int count;
} Cluster;

void initialize_clusters(Cluster *clusters, Point *data, int k, int data_size);
double calculate_distance(Point a, Point b);
void assign_points_to_clusters(Point *data, Cluster *clusters, int k, int data_size);
void update_centroids(Cluster *clusters, int k);
int has_converged(Cluster *clusters, Cluster *prev_clusters, int k);
void free_clusters(Cluster *clusters, int k);
void print_clusters(Cluster *clusters, int k);

int main() {
    int k = 3; // Number of clusters
    int data_size = 10; // Number of data points

    // Sample data points
    Point data[] = {
        {1.0, 2.0}, {1.5, 1.8}, {5.0, 8.0},
        {8.0, 8.0}, {1.0, 0.6}, {9.0, 11.0},
        {8.0, 2.0}, {10.0, 2.0}, {9.0, 3.0},
        {3.0, 3.0}
    };

    Cluster *clusters = malloc(k * sizeof(Cluster));
    Cluster *prev_clusters = malloc(k * sizeof(Cluster));

    // Initialize clusters with random centroids
    initialize_clusters(clusters, data, k, data_size);

    int iterations = 0;
    do {
        // Store previous cluster state
        for (int i = 0; i < k; i++) {
            prev_clusters[i] = clusters[i];
            clusters[i].count = 0; // Reset count for the new iteration
            clusters[i].points = malloc(data_size * sizeof(Point)); // Allocate space for points
        }

        assign_points_to_clusters(data, clusters, k, data_size);
        update_centroids(clusters, k);
        iterations++;
    } while (!has_converged(clusters, prev_clusters, k));

    print_clusters(clusters, k);

    // Free allocated memory
    for (int i = 0; i < k; i++) {
        free(clusters[i].points);
    }
    free(clusters);
    free(prev_clusters);

    return 0;
}

void initialize_clusters(Cluster *clusters, Point *data, int k, int data_size) {
    for (int i = 0; i < k; i++) {
        clusters[i].centroid = data[i]; // Initial centroids from data points
        clusters[i].count = 0;
        clusters[i].points = malloc(data_size * sizeof(Point)); // Allocate points array
    }
}

double calculate_distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

void assign_points_to_clusters(Point *data, Cluster *clusters, int k, int data_size) {
    for (int i = 0; i < data_size; i++) {
        double min_distance = __DBL_MAX__;
        int cluster_index = 0;

        for (int j = 0; j < k; j++) {
            double distance = calculate_distance(data[i], clusters[j].centroid);
            if (distance < min_distance) {
                min_distance = distance;
                cluster_index = j;
            }
        }

        clusters[cluster_index].points[clusters[cluster_index].count++] = data[i]; // Assign point
    }
}

void update_centroids(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        if (clusters[i].count == 0) continue; // Avoid division by zero

        double sum_x = 0, sum_y = 0;
        for (int j = 0; j < clusters[i].count; j++) {
            sum_x += clusters[i].points[j].x;
            sum_y += clusters[i].points[j].y;
        }
        clusters[i].centroid.x = sum_x / clusters[i].count; // Update x coordinate of centroid
        clusters[i].centroid.y = sum_y / clusters[i].count; // Update y coordinate of centroid
    }
}

int has_converged(Cluster *clusters, Cluster *prev_clusters, int k) {
    for (int i = 0; i < k; i++) {
        if (calculate_distance(clusters[i].centroid, prev_clusters[i].centroid) > 1e-5) {
            return 0;
        }
    }
    return 1; // Converged
}

void print_clusters(Cluster *clusters, int k) {
    for (int i = 0; i < k; i++) {
        printf("Cluster %d:\n", i + 1);
        printf(" Centroid: (%.2f, %.2f)\n", clusters[i].centroid.x, clusters[i].centroid.y);
        printf(" Points:\n");
        for (int j = 0; j < clusters[i].count; j++) {
            printf(" (%.2f, %.2f)\n", clusters[i].points[j].x, clusters[i].points[j].y);
        }
    }
}