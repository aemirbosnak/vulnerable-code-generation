//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: enthusiastic
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Euclidean distance calculation function
double distance(double *a, double *b, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return sqrt(sum);
}

// K-Means clustering algorithm
void kmeans(double **data, int n, int k, int max_iters) {
    // Initialize centroids randomly
    double **centroids = malloc(k * sizeof(double *));
    for (int i = 0; i < k; i++) {
        centroids[i] = malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            centroids[i][j] = data[rand() % n][j];
        }
    }

    // Assign data points to clusters
    int *clusters = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        double min_dist = INFINITY;
        int min_cluster = -1;
        for (int j = 0; j < k; j++) {
            double dist = distance(data[i], centroids[j], n);
            if (dist < min_dist) {
                min_dist = dist;
                min_cluster = j;
            }
        }
        clusters[i] = min_cluster;
    }

    // Update centroids
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            centroids[i][j] = 0;
        }
    }
    int *counts = calloc(k, sizeof(int));
    for (int i = 0; i < n; i++) {
        int cluster = clusters[i];
        for (int j = 0; j < n; j++) {
            centroids[cluster][j] += data[i][j];
        }
        counts[cluster]++;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            centroids[i][j] /= counts[i];
        }
    }
    free(counts);

    // Repeat until convergence or max iterations reached
    int iter = 0;
    while (iter < max_iters) {
        // Assign data points to clusters
        int *new_clusters = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            double min_dist = INFINITY;
            int min_cluster = -1;
            for (int j = 0; j < k; j++) {
                double dist = distance(data[i], centroids[j], n);
                if (dist < min_dist) {
                    min_dist = dist;
                    min_cluster = j;
                }
            }
            new_clusters[i] = min_cluster;
        }

        // Check if clusters have changed
        int changed = 0;
        for (int i = 0; i < n; i++) {
            if (clusters[i] != new_clusters[i]) {
                changed = 1;
                break;
            }
        }
        free(clusters);
        clusters = new_clusters;

        // Update centroids
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                centroids[i][j] = 0;
            }
        }
        counts = calloc(k, sizeof(int));
        for (int i = 0; i < n; i++) {
            int cluster = clusters[i];
            for (int j = 0; j < n; j++) {
                centroids[cluster][j] += data[i][j];
            }
            counts[cluster]++;
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                centroids[i][j] /= counts[i];
            }
        }
        free(counts);

        iter++;
    }

    // Print cluster assignments
    for (int i = 0; i < n; i++) {
        printf("Data point %d belongs to cluster %d\n", i, clusters[i]);
    }

    // Free memory
    for (int i = 0; i < k; i++) {
        free(centroids[i]);
    }
    free(centroids);
    free(clusters);
}

int main() {
    // Sample data
    double data[5][2] = {
        {1, 2},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 10}
    };

    // Perform K-Means clustering with k = 2 and max_iters = 10
    kmeans(data, 5, 2, 10);

    return 0;
}