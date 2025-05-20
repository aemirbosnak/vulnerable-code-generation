//GEMINI-pro DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double *x;
    int n;
} data_t;

typedef struct {
    int *cluster;
    int k;
} clustering_t;

double euclidean_distance(double *x1, double *x2, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pow(x1[i] - x2[i], 2);
    }
    return sqrt(sum);
}

clustering_t kmeans(data_t data, int k, int max_iterations) {
    clustering_t clustering;
    clustering.k = k;
    clustering.cluster = malloc(data.n * sizeof(int));

    // Initialize cluster centers randomly
    for (int i = 0; i < k; i++) {
        clustering.cluster[i] = rand() % data.n;
    }

    // Iterate until convergence or max iterations reached
    int iterations = 0;
    int changed = 1;
    while (changed && iterations < max_iterations) {
        changed = 0;

        // Assign each point to nearest cluster center
        for (int i = 0; i < data.n; i++) {
            double min_distance = INFINITY;
            for (int j = 0; j < k; j++) {
                double distance = euclidean_distance(data.x + i * data.n, data.x + clustering.cluster[j] * data.n, data.n);
                if (distance < min_distance) {
                    min_distance = distance;
                    clustering.cluster[i] = j;
                }
            }
        }

        // Update cluster centers
        for (int j = 0; j < k; j++) {
            // Find the mean of all points in cluster
            double *sum = malloc(data.n * sizeof(double));
            for (int i = 0; i < data.n; i++) {
                if (clustering.cluster[i] == j) {
                    for (int m = 0; m < data.n; m++) {
                        sum[m] += data.x[i * data.n + m];
                    }
                }
            }
            for (int m = 0; m < data.n; m++) {
                sum[m] /= data.n;
            }

            // Update cluster center
            for (int m = 0; m < data.n; m++) {
                data.x[clustering.cluster[j] * data.n + m] = sum[m];
            }

            free(sum);
        }

        iterations++;
    }

    return clustering;
}

int main() {
    // Create some random data
    int n = 100;
    int d = 2;
    data_t data;
    data.n = n;
    data.x = malloc(n * d * sizeof(double));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            data.x[i * d + j] = rand() % 100;
        }
    }

    // Perform k-means clustering
    int k = 3;
    int max_iterations = 100;
    clustering_t clustering = kmeans(data, k, max_iterations);

    // Print the cluster assignments
    for (int i = 0; i < n; i++) {
        printf("Point %d: cluster %d\n", i, clustering.cluster[i]);
    }

    // Free memory
    free(data.x);
    free(clustering.cluster);

    return 0;
}