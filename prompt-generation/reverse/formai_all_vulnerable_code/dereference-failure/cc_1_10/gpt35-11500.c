//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define INFINITY 1000000000

// Define data structure for data points
typedef struct {
    double *features;
    int cluster;
} DataPoint;

// Define data structure for cluster centers
typedef struct {
    int id;
    double *center;
} Cluster;

// Function to compute Euclidean distance between two data points
double euclidean_distance(double *features1, double *features2, int num_features) {
    double distance = 0;
    for (int i = 0; i < num_features; i++) {
        distance += pow(features1[i] - features2[i], 2);
    }
    return sqrt(distance);
}

// Function to initialize cluster centers at random data points
void initialize_clusters(DataPoint *data_points, Cluster *clusters, int num_points, int num_clusters, int num_features) {
    for (int i = 0; i < num_clusters; i++) {
        int random_index = rand() % num_points;
        for (int j = 0; j < num_features; j++) {
            clusters[i].center[j] = data_points[random_index].features[j];
        }
        clusters[i].id = i;
    }
}

// Function to assign each data point to its nearest cluster
void assign_clusters(DataPoint *data_points, Cluster *clusters, int num_points, int num_clusters, int num_features) {
    for (int i = 0; i < num_points; i++) {
        double min_distance = INFINITY;
        for (int j = 0; j < num_clusters; j++) {
            double distance = euclidean_distance(data_points[i].features, clusters[j].center, num_features);
            if (distance < min_distance) {
                min_distance = distance;
                data_points[i].cluster = j;
            }
        }
    }
}

// Function to update cluster centers
bool update_clusters(DataPoint *data_points, Cluster *clusters, int num_points, int num_clusters, int num_features) {
    bool changed = false;
    int *cluster_sizes = calloc(num_clusters, sizeof(int));
    for (int i = 0; i < num_points; i++) {
        int cluster_id = data_points[i].cluster;
        for (int j = 0; j < num_features; j++) {
            clusters[cluster_id].center[j] += data_points[i].features[j];
        }
        cluster_sizes[cluster_id]++;
    }
    for (int i = 0; i < num_clusters; i++) {
        if (cluster_sizes[i] == 0) {
            continue;
        }
        for (int j = 0; j < num_features; j++) {
            double new_center = clusters[i].center[j] / (double)cluster_sizes[i];
            if (fabs(new_center - clusters[i].center[j]) > 0.0001) {
                changed = true;
            }
            clusters[i].center[j] = new_center;
        }
    }
    free(cluster_sizes);
    return changed;
}

// Function to perform clustering
void cluster(DataPoint *data_points, Cluster *clusters, int num_points, int num_clusters, int num_features) {
    initialize_clusters(data_points, clusters, num_points, num_clusters, num_features);
    bool changed = true;
    int iterations = 0;
    while (changed && iterations < 100) {
        assign_clusters(data_points, clusters, num_points, num_clusters, num_features);
        changed = update_clusters(data_points, clusters, num_points, num_clusters, num_features);
        iterations++;
    }
}

// Function to print cluster assignments and centers
void print_clusters(DataPoint *data_points, Cluster *clusters, int num_points, int num_clusters, int num_features) {
    printf("Cluster assignments:\n");
    for (int i = 0; i < num_points; i++) {
        printf("Data point %d assigned to cluster %d\n", i, data_points[i].cluster);
    }
    printf("Cluster centers:\n");
    for (int i = 0; i < num_clusters; i++) {
        printf("Cluster %d center: ", i);
        for (int j = 0; j < num_features; j++) {
            printf("%f ", clusters[i].center[j]);
        }
        printf("\n");
    }
}

int main() {
    int num_points = 10;
    int num_clusters = 2;
    int num_features = 2;
    DataPoint *data_points = calloc(num_points, sizeof(DataPoint));
    for (int i = 0; i < num_points; i++) {
        data_points[i].features = calloc(num_features, sizeof(double));
        data_points[i].features[0] = rand() % 100;
        data_points[i].features[1] = rand() % 100;
    }
    Cluster *clusters = calloc(num_clusters, sizeof(Cluster));
    for (int i = 0; i < num_clusters; i++) {
        clusters[i].center = calloc(num_features, sizeof(double));
    }
    cluster(data_points, clusters, num_points, num_clusters, num_features);
    print_clusters(data_points, clusters, num_points, num_clusters, num_features);
    for (int i = 0; i < num_points; i++) {
        free(data_points[i].features);
    }
    free(data_points);
    for (int i = 0; i < num_clusters; i++) {
        free(clusters[i].center);
    }
    free(clusters);
    return 0;
}