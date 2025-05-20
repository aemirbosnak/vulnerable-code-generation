//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: systematic
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    double *data;
    int n_points;
    int n_features;
} dataset_t;

typedef struct {
    int *cluster_assignment;
    int n_clusters;
} clustering_t;

double euclidean_distance(double *p1, double *p2, int n_features) {
    double sum = 0;
    for (int i = 0; i < n_features; i++) {
        sum += pow(p1[i] - p2[i], 2);
    }
    return sqrt(sum);
}

clustering_t *k_means(dataset_t *dataset, int n_clusters) {
    // Initialize cluster centroids
    double **centroids = malloc(n_clusters * sizeof(double *));
    for (int i = 0; i < n_clusters; i++) {
        centroids[i] = malloc(dataset->n_features * sizeof(double));
        for (int j = 0; j < dataset->n_features; j++) {
            centroids[i][j] = dataset->data[i * dataset->n_features + j];
        }
    }

    // Initialize cluster assignments
    int *cluster_assignment = malloc(dataset->n_points * sizeof(int));
    for (int i = 0; i < dataset->n_points; i++) {
        cluster_assignment[i] = -1;
    }

    // Iterate until convergence
    int max_iterations = 100;
    int iteration = 0;
    while (iteration < max_iterations) {
        // Assign each point to its closest centroid
        for (int i = 0; i < dataset->n_points; i++) {
            double min_distance = INFINITY;
            int closest_cluster = -1;
            for (int j = 0; j < n_clusters; j++) {
                double distance = euclidean_distance(dataset->data + i * dataset->n_features, centroids[j], dataset->n_features);
                if (distance < min_distance) {
                    min_distance = distance;
                    closest_cluster = j;
                }
            }
            cluster_assignment[i] = closest_cluster;
        }

        // Update centroids
        for (int i = 0; i < n_clusters; i++) {
            int n_points_in_cluster = 0;
            for (int j = 0; j < dataset->n_points; j++) {
                if (cluster_assignment[j] == i) {
                    for (int k = 0; k < dataset->n_features; k++) {
                        centroids[i][k] += dataset->data[j * dataset->n_features + k];
                    }
                    n_points_in_cluster++;
                }
            }
            for (int k = 0; k < dataset->n_features; k++) {
                centroids[i][k] /= n_points_in_cluster;
            }
        }

        iteration++;
    }

    // Return clustering result
    clustering_t *clustering = malloc(sizeof(clustering_t));
    clustering->cluster_assignment = cluster_assignment;
    clustering->n_clusters = n_clusters;
    return clustering;
}

void print_clustering(clustering_t *clustering, dataset_t *dataset) {
    for (int i = 0; i < clustering->n_clusters; i++) {
        printf("Cluster %d:\n", i);
        for (int j = 0; j < dataset->n_points; j++) {
            if (clustering->cluster_assignment[j] == i) {
                for (int k = 0; k < dataset->n_features; k++) {
                    printf("%f ", dataset->data[j * dataset->n_features + k]);
                }
                printf("\n");
            }
        }
        printf("\n");
    }
}

int main() {
    // Generate a synthetic dataset
    int n_points = 100;
    int n_features = 2;
    dataset_t dataset;
    dataset.n_points = n_points;
    dataset.n_features = n_features;
    dataset.data = malloc(n_points * n_features * sizeof(double));
    for (int i = 0; i < n_points; i++) {
        for (int j = 0; j < n_features; j++) {
            dataset.data[i * n_features + j] = rand() / (double)RAND_MAX;
        }
    }

    // Perform k-means clustering with 3 clusters
    int n_clusters = 3;
    clustering_t *clustering = k_means(&dataset, n_clusters);

    // Print the clustering result
    print_clustering(clustering, &dataset);

    // Free memory
    free(dataset.data);
    free(clustering->cluster_assignment);
    free(clustering);

    return 0;
}